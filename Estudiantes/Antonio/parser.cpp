/**
 * Parser for ST0244 language - Adapted to C++
 *
 * @author Helmuth Trefftz
 * @author Jose Luis Montoya
 *
 * El lenguaje que se reconoce es el siguiente:
 *
 * <program> ::= program <funDefinitionList> endprogram
 * <funDefinitionList> ::= <funDefinition> <funDefinitionList>
 *              | epsilon
 * <funDefinition> ::= def <variable> lparen <varDefList> rparen
 *              <varDefList>
 *              <statementList>
 *              <retorno>
 *              enddef
 * <retorno>    ::= return <complemento>
 * <complemento> ::= <variable> | <constante>
 * <varDefList> ::= <varDef> <varDefList>
 *              | epsilon
 * <varDef>     ::= int <variable>
 * <variable>   ::= <letra><letraodigito>
 * <letra>      ::= a | b | ... | z | A | B | ... | Z
 * <constante>  ::= <digito>+
 * <letraodigito> ::= <letra><letraodigito> | <digito><letraodigito> | epsilon
 * <digito>     ::= 0 | 1 | ... | 9
 * <statementList> ::= <statement> <statementList>
 *              | epsilon
 * <statment> ::= read variable 
 *              | print variable 
 *              | call variable lparen <variableList> rparen
 * <variableList> ::= <variable> <variableList>
 *              | epsilon
 */
#include <string>
#include <iostream>
#include <fstream>
#include "parser.h"
#include "lexer.h"
#include "token.h"


//#define debug

using namespace std;
/**
 * Constructor The name of the file with the source code is received as
 * parameter
 *
 * @param fileName Name of file where the source code is be read
 */
Parser::Parser(string strFileName)
{
	fstream prueba;
	prueba.exceptions( std::fstream::failbit | std::fstream::badbit );
	
	try
	{	
		prueba.open(strFileName, fstream::in);
		prueba.close();
	}
	catch (fstream::failure e)
	{
		cout << "No se encontró el archivo " << strFileName << endl;
		exit(3);
	}
	
	try {
		lexer = new Lexer(strFileName);
		token = lexer->nextToken();
	}
	
	catch (fstream::failure e) {
		cout << "Se pierde acceso con el archivo " << strFileName << endl;
		exit(3);
	}
#ifdef debug
	cout << "DEBUG: Parser constructed" << "\n";
#endif
}

/**
 * Added to C++ compliance
 */
Parser::~Parser()
{
	delete token;
	delete lexer;
#ifdef debug
	cout << "DEBUG: Parser destroyed" << "\n";
#endif
}

/**
 * Check if the current token is the same as expected, as per the derivation
 *
 * @param expected Expected token
 */
void Parser::recognize(int expected)
{
	if (token->getCode() == expected)
	{
		token = lexer->nextToken();
	}
	else
	{
		cout << "Syntax Error. " 
		     << "Expected: " << lexer->getTokenText(expected) 
			 << " found: " << lexer->getTokenText(token->getCode())
			 << " " << token->getToken()
			 << endl;
		exit(2);
	}
}

/**
 * Check if the current token is a variable Returns the name of the
 * variable. This will be needed when generating code.
 */
string Parser::recognizeVariable()
{
	string text;
	if (token->getCode() == VARIABLE) {
  cout << "reconoci variable " << token->getToken() << endl;
		text = token->getToken();
		// Generate code for the variable
		token = lexer->nextToken();
	}else {
		cout << "Syntax Error. "
			 << "Expected: variable found: "
			 << token->getToken() << endl;
		text = "";
		exit(2);
	}
	return text;
}

//reconocimiento de variable o constante para encontrar asignacion y prueba de simbolos 
void Parser::assign()
{
  if (token->getCode()== ASSIGN){
      recognize(ASSIGN);
  }else{
    cout << "Syntax Error. "
         << "Expected: variable or constant found: "
         << token->getToken();
    exit(2);
  }
 }
/**
 * Check if the current token is a variable Returns the name of the
 * variable. This will be needed when eenerating code.
 */
void Parser::recognizeConstante()
{
	string text;
	if (token->getCode() == CONSTANT) {
		text = token->getToken();
		// Generate code for the variable
		token = lexer->nextToken();
	}
	else {
		cout << "Syntax Error. "
			 << "Expected: constante found: "
			 << token->getToken() << endl;
		text = "";
		exit(2);
	}
}

/**
 * <program> ::= program <funDefinition> endprogram
 */
void Parser::program()
{
	recognize(PROGRAM);
	funDefinitionList();
  cout << token->getToken() << endl;
	recognize(ENDPROGRAM);
	if (token->getCode() == TEOF)
		cout << "No errors found" << endl;
}

/**
 * <funDefinitionList> ::= <funDefinition> <funDefinitionList>
 *                  | epsilon
 */
void Parser::funDefinitionList()
{
	if(token->getCode() == DEF) {
		funDefinition();
		funDefinitionList();
	}
	else {
		// nothing, epsilon
	}
}

/**
 * <funDefinition> ::= def variable lparen <varDefList> rparen 
 *              <varDefinitionList>
 *              <satamentList> 
 *              enddef
 *
 */
void Parser::funDefinition()
{
	// Header
	recognize(DEF);
	recognizeVariable();
	recognize(LPAREN);
	varDefList();
	recognize(RPAREN);
	// Variable definitions
	varDefList();
	// Statements
	statementList();
	retorno();
	recognize(ENDDEF);
}

/**
 * <varDefList> ::= <varDef> <varDefList>
 *                  | epsilon
 *
 */
void Parser::varDefList()
{
	if (token->getCode() == INT) {
		// all variable definitions start with "int"
		// Not that the token is not recoginzed here but in
		// varDef
		varDef();
		varDefList();
	}
}

/**
 * <varDef> ::= int variable
 */
void Parser::varDef()
{
	recognize(INT);
	// Use the name of the variable to generate code
	string text = recognizeVariable();
}

/**
 * <statementList> ::= <statement> <statementList> 
 *                  | epsilon
 *
 */
void Parser::statementList()
{
	if (token->getCode() == READ
			|| token->getCode() == PRINT
			|| token->getCode() == CALL 
      || token->getCode() == WHILE
      || token->getCode() == VARIABLE) {
		statement();
		statementList();
	}
	else {
		// nothing, epsilon
	}
}

/**
 *
 * <statment> ::= read variable 
 *              | print variable 
 *              | call variable lparen
 */         
void Parser::statement()
{
	string text = "";
	switch (token->getCode())
	{
		case READ:
			recognize(READ);
			text = recognizeVariable();
			break;
		case PRINT:
			recognize(PRINT);
			text = recognizeVariable();
			break;
		case CALL:
			recognize(CALL);
			text = recognizeVariable();
			recognize(LPAREN);
			variableList();
			recognize(RPAREN);
			break;
    case VARIABLE:
      recognizeVariable();
  cout << "A validar igual" << endl;
      assign();// reoconoce asignacions 
  cout << "A validar expr" << endl;
      expr();
      cout << "Termine" << endl;
      break;
    case WHILE:
      ciclo();
      break;
		default:
			break;
	}
}

/**
 * <retorno>    ::= return <complemento>
 */
void Parser::retorno()
{
  cout << token->getToken() << endl;
	recognize(RETURN);
	complemento();
}

/**
 * <complemento> ::= <variable> | <constante>
 */
void Parser::complemento()
{
	if (token->getCode() == VARIABLE)
		recognizeVariable();
	else
		if (token->getCode() == CONSTANT)
			recognizeConstante();
		else
		{
			cout << "Syntax Error. "
				 << "Expected: variable or constant, found: "
				 << token->getToken() << endl;
			exit(2);
		}
}

/**
 * <variableList> ::= variable <variableList> 
 *              | epsilon
 */
void Parser::variableList()
{
	string text = "";
	if(token->getCode() == VARIABLE) {
		text = recognizeVariable();
		variableList();
	} 
	else {
		// nothing, epsilon
	}
}

void Parser::expr()
{
  term();
  exprRest();
}

void Parser:: exprRest()
{
  if(token->getCode()== MAS){
    recognize(MAS);
    term();
    exprRest();
  }else if(token->getCode()== MENOS){
    recognize(MENOS);
    term();
    exprRest();
  }else{
    //nada, epsilon 
  }
}

void Parser::term()
{
  factor();
  termRest();
}

void Parser::termRest()
{
  if(token->getCode()== POR){
    recognize(POR);
    term();
    termRest();
  }else if(token->getCode()== DIV){
    recognize(DIV);
    term();
    termRest();
  }else{
    //nada, epsilon 
  }
}

void Parser::factor()
{
  if(token->getCode() == LPAREN){
    recognize(LPAREN);
    expr();
    recognize(RPAREN);

  }else if(token->getCode()== VARIABLE){
    recognizeVariable();
  }else if(token->getCode()== CONSTANT){
    recognizeConstante();
  }else{
    cout<< "Syntax Error. "
        << "Expected: variable, constante or expression, found: "
        << token->getToken() << endl; 
        exit(2);
  }
}

void Parser::ciclo()
{
/*  recognize(WHILE);
  recognize(LPAREN);
  while(token->getCode()== VARIABLE || token->getCode()== CONSTANT){
    if (token->getCode()== VARIABLE){
      recognizeVariable();
      recognizeConditionSymbol();
      recognize(RPAREN);
      varDefList();
      statementList();
      varDefList();
      statementList();
      varDefList();
    }else if(token->getCode()== CONSTANT){
      recognizeConstante();
      recognizeConditionSymbol();
      recognize(RPAREN);
      varDefList();
      statementList();
      varDefList();
      statementList();
      varDefList();
    }else if (token->getCode()== ENDWHILE){
      break;
    }
  }
  recognize(ENDWHILE);*/
  recognize(WHILE);
  recognize(LPAREN);
  bool bandera = true;
  while(bandera){
    if (token->getCode() == VARIABLE){
      recognizeVariable();
      if(token->getCode()== MAS ||token->getCode()== MENOS ||token->getCode()== POR ||token->getCode()== DIV){
        expr();
        }
    }else if(token->getCode()== CONSTANT){
      recognizeConstante();
      if(token->getCode()== MAS ||token->getCode()== MENOS ||token->getCode()== POR ||token->getCode()== DIV){
        expr();
      }
    }
    if(token->getCode()== RPAREN){
      recognize(RPAREN);
      recognize(ENDWHILE);
      bandera=false;
    }else if(token->getCode()== AND 
    || token->getCode()== OR
    || token->getCode()== EQUALS
    || token->getCode()== DIFFERENT){
      recognizeConditionSymbol();
    }
  }
}
//void Parser::recognizeCondicional(){
  // if, tokengetcode= lparen
  //   recognocer lparen
  //    expr
  // recognice rparen
//

void Parser::recognizeCondition(){
  if(token->getCode()== EQUALS){
    recognize(EQUALS);
    expr();
  }
  else if(token->getCode()== DIFFERENT){
    recognize(DIFFERENT);
    expr();
  }else if(token->getCode()== AND){
    recognize(AND);
    expr();
  }else{
    cout<< "Syntax Error. "
        << "Expected: == o !=, found: "
        << token->getToken() << endl; 
    exit(2);
  }
}

void Parser::recognizeConditionRest(){
  if(token->getCode()== AND){
    recognize(AND);
    if(token->getCode()== VARIABLE){
      recognizeVariable();
      recognizeConditionSymbol();
    }else if(token->getCode()== CONSTANT){
      recognizeConstante();
      recognizeConditionSymbol();
    }

  }else if(token->getCode()== OR){
    recognize(OR);
    if(token->getCode()== VARIABLE){
      recognizeVariable();
      recognizeConditionSymbol();
    }else if(token->getCode()== CONSTANT){
      recognizeVariable();
      recognizeConditionSymbol();
    }
  }
}


void Parser::recognizeConditionSymbol(){
  recognizeCondition();
  recognizeConditionRest();
}

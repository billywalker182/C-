/**
 * Very simple Lexer, built on the Java Scanner.  - Adapted to C++
 * Limitation: all the symbols have to be separted with spaces 
 * in the source file.
 *
 * @author Helmuth Trefftz
 * @author Jose Luis Montoya
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "lexer.h"
#include "evalex.h"

using namespace std;
/**
 * This lexer returns tokens to the Parser
 * @author Helmuth Trefftz
 */
Lexer::Lexer(string strFileName)
{
//	fileScanner = new Scanner(File(fileName));
// Convert the fileScanner into C** open file stream ifstream
	fileScanner.open(strFileName, ios::in);
	table.push_back(Token(PROGRAM, "program"));
	table.push_back(Token(ENDPROGRAM, "endprogram"));
	table.push_back(Token(DEF, "def"));
	table.push_back(Token(ENDDEF, "enddef"));
	table.push_back(Token(IF, "if"));
	table.push_back(Token(ELSE, "else"));
	table.push_back(Token(ENDIF, "endif"));
	table.push_back(Token(VARIABLE, "variable"));
	table.push_back(Token(CONSTANT, "constante"));
	table.push_back(Token(EQUALS, "=="));
	table.push_back(Token(LPAREN, "("));
	table.push_back(Token(RPAREN, ")"));
	table.push_back(Token(INT, "int"));
	table.push_back(Token(READ, "read"));
	table.push_back(Token(PRINT, "print"));
	table.push_back(Token(CALL, "call"));
	table.push_back(Token(RETURN, "return"));
	table.push_back(Token(TEOF, "TEOF"));
  table.push_back(Token(ASSIGN, "="));
  table.push_back(Token(MAS, "+"));
  table.push_back(Token(MENOS, "-"));
  table.push_back(Token(POR, "*"));
  table.push_back(Token(DIV, "/"));
  table.push_back(Token(WHILE, "while"));
  table.push_back(Token(ENDWHILE, "endwhile"));
  table.push_back(Token(DIFFERENT, "!="));
  table.push_back(Token(OR, "||"));
  table.push_back(Token(AND, "&&"));
}

/**
 * Added to C++ compliance
 */
Lexer::~Lexer()
{
	table.clear();
	lineScanner.clear();
}

/**
 * Finds the next non-blank text in the input file.
 * If the file is finished, it returns the text "TEOF"
 * @return Next non-blank text
 */
string Lexer::nextText()
{
// 
	string text;
	string temp;
	do {
		text = "";
		
		if(lineScanner.length() == 0)
		{
			if(!fileScanner.eof())
			{
					// read next line an prepare line scanner
				getline(fileScanner,lineScanner, '\n');
			}
			else {
				// End Of File
				text = "TEOF";
			}
		}
		else
		{
			if(lineScanner.find(" ") != string::npos)
			{
				text = lineScanner.substr(0, lineScanner.find(" "));
				lineScanner = lineScanner.substr(lineScanner.find(" ")+1, lineScanner.length()-1);
			}
			else
			{
				text = lineScanner.substr(0,lineScanner.length()-1);
				lineScanner.clear();
			}
		}
	} while (text.length() == 0);
	return text;
}

/**
 * Returns the next token (as code)
 * @return next token: code and text (if constant or variable)
 */
Token* Lexer::nextToken()
{
	string text = nextText();
	// Check if text is a valid keyword
	for(auto t: table)
	{
		string comparar = t.getToken();

		if(comparar.compare(text) == 0) {
			return new Token(t.getCode(), "");
		}
	}
	// Check if text is a valid variable name
	if(validVariableName(text)) return new Token(VARIABLE, text);
	// Check if text is a valid integer constant
	if(validIntConstant(text)) return new Token(CONSTANT, text);
	// If none of the above, return invalid token
	return new Token(INVALIDTOKEN, text);
}

/**
 * Added -- Returns true if the parameter is a character
 * @param c character to be checked
 * @return true if character is valid, false otherwise
 */
bool isLetter(char c) {
   return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * Returns true if the parameter is a valid variable name
 * (all characters are letters)
 * @param text text to be checked
 * @return true if text is a valid variable name, false otherwise
 */
bool Lexer::validVariableName(string text)
{
	if (!isLetter(text.at(0)))
		return false;
	for(int i = 1; i < text.length(); i++) {
		if(!isLetter(text.at(i)) && !isdigit(text.at(i))) return false;
	}
	return true;
}

/**
 * Returns true if the parameter is a valid integer constant
 * (all characters are digits>)
 * @param text text to be cheked
 * @return true if text is a valid integer constant, false otherwise
 */
bool Lexer::validIntConstant(string text)
{
	for(int i = 0; i < text.length(); i++) {
		if(!isdigit(text.at(i))) return false;
	}
	return true;
}

/**
 * Given the numerical code of a token, return the text associated
 * with the token.
 * Used to make the error reporting in the Parser more readable
 * @param code Numerical code of the token
 * @return Text associated with the token
 */
string Lexer::getTokenText(int code)
{
	for(auto t: table) {
		if(t.getCode() == code) {
			return t.getToken();
		}
		
	}
	return "";
}

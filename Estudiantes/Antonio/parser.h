#ifndef parser_h
#define parser_h

#include <string>

#include "token.h"
#include "lexer.h"

using namespace std;

class Parser
{
	private:
		Token* token;
		Lexer* lexer;
		string recognizeVariable();
		void recognize(int expected);	
		void recognizeConstante();
	
	public:
		Parser(string strFileName);
		virtual ~Parser();
		void program();
		void funDefinitionList();
		void funDefinition();
		void varDefList();
		void varDef();
		void statementList();
		void statement();
		void variableList();
		void retorno();
		void complemento();
    void assign();
    void expr();
    void exprRest();
    void term();
    void termRest();
    void factor();
    void ciclo();
    void recognizeCondition();
    void recognizeConditionRest();
    void recognizeConditionSymbol();
};

#endif
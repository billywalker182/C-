#ifndef lexer_h
#define lexer_h

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "token.h"

using namespace std;

class Lexer
{
	private:
	    vector<Token> table;
    
		fstream fileScanner;
		string lineScanner;
		bool validVariableName(string text);
		bool validIntConstant(string text);
		
	public:
		Lexer(string strFileName);
		virtual ~Lexer();
		string nextText();
		Token* nextToken();
		string getTokenText(int code);
};

const int PROGRAM = 1;
const int ENDPROGRAM = 2;
const int DEF = 3;
const int ENDDEF = 4;
const int IF = 5;
const int ELSE = 6;
const int ENDIF = 7;
const int VARIABLE = 8;
const int CONSTANT = 9;
const int EQUALS = 10;
const int ASSIGN = 11;
const int LPAREN = 12;
const int RPAREN = 13;
const int INT = 14;
const int READ = 15;
const int PRINT = 16;
const int CALL = 17;
const int RETURN = 18;
const int INVALIDTOKEN = 98;
const int TEOF = 99;
const int MAS = 19;
const int MENOS = 20;
const int POR = 21;
const int DIV = 22;
const int WHILE= 23;
const int ENDWHILE = 24;
const int DIFFERENT = 25;
const int AND = 26;
const int OR = 27;
#endif
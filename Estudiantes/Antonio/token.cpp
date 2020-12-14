/**
 * Class for storing a token. - Adapted to C++
 * It has two attributes: the numeric code and (possibly) the text
 * @author Helmuth Trefftz
 */
#include <string>
#include "token.h"

using namespace std;

Token::Token(int code, string text)
{
	this->code = code;
	this->text = text;
}

/**
 * Added to C++ compliance
 */
Token::~Token()
{
	text.clear();
}

string Token::toString() {
	return "" + to_string(code) + " " + text;
}

string Token::getToken() {
	return text;
}

int Token::getCode() {
	return code;
}

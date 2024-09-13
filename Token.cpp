//
// Created by xmani on 9/4/2024.
//

#include <iostream>
#include <iomanip>
#include "Token.hpp"

//default constructor, want to give it line data and set up some default vairables apart of the object.
Token::Token(int line, int pos) {
    _eof = false;
    _tokenString = "";
    _lineNumber = line;
    _charPos = pos;
}

//set of return functions to tell if a token is if a given type.

bool& Token::isEOF() { return _eof; }

//or we want to return the comment name if it is a comment
std::string Token::getTokenString() { return _tokenString; }

//create setter functions
void Token::setEndOfFile() { _eof = true; }

void Token::setTokenString(std::string dataString) {
    _tokenString = dataString;
}

//and ofc a function to print out tokens.
void Token::print() {

    //spits out line number and position of token.
    std::cout << "[" << std::setw(2) << _lineNumber << ", " << std::setw(3) << _charPos << "] ";


    //use code below as a format example, if we have a + as a token then if 
    //its a + opperator just print out + dont store anything in the string for that token
    /*if (isDoubleSlash()) {
        std::cout << "//"<<std::endl;
    }
    else if (isNextLine()) {
        std::cout << "\n";
    }
    else if (isOpenSlashStar()) {
        std::cout << "/*"<<std::endl;
    }
    else if (isCloseStarSlash()) {
        std::cout << ""<<std::endl;
    }
    else if (isComment()) {
        std::cout << _comment<<std::endl;
    }else {
        std::cout << "Token::print -- unknown token.\n" << std::endl;
        exit(3);
    }*/

}

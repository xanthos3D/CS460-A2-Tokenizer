//
// Created by xmani on 9/4/2024.
//


#ifndef PROJECT1_PHASE2_TOKEN_HPP
#define PROJECT1_PHASE2_TOKEN_HPP


#include <string>

class Token {
public:
    // token recieves a line number ans position
    Token(int, int);

    // simple getter functions to tell if a token is a given type
    // note may want to have a switch statement that returns the type of token and store the token type as a string?
    bool &isEOF();
    //if a token has more complex information then store it in the token string
    std::string getTokenString();

    //simple setter functions to set a token to a given type.
    void setEndOfFile();
    void setTokenString(std::string);

    //useful tester function so we can print the tokens and there type.
    void print();

private:
    bool _eof ;
    std::string _tokenString;
    int _lineNumber, _charPos;
};

#endif //PROJECT1_PHASE2_TOKEN_HPP

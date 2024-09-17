//
// Created by xmani on 9/4/2024.
//

#include <iostream>
#include <iomanip>
#include "Token.hpp"

//default constructor, want to give it line data and set up some default vairables apart of the object.
Token::Token(int line, int pos) {
    //misc idenfitier types
    _identifier = false;
    _doubleQuote = false;
    _singleQuote= false;
     _semicolon= false;
     _comma= false;
      _eof= false;
    //braces and brackets
    _LParen= false;
    _RParen= false;
    _LBrace= false;
    _RBrace= false;
    _LBracket= false;
    _RBracket= false;
    //opperators
    _assignmentOperator= false;
    _modulo= false;
    _plus= false;
    _minus= false;
    _asterisk= false;
    _divide= false;
    _caret= false;
    //data types
    _int= false;
    _double= false;
    _char= false;
    _string= false;
    //boolean opperators
    _boolE= false;
    _boolNE= false;
    _boolGT= false;
    _boolLT= false;
    _boolGTE= false;
    _boolLTE= false;
    _boolAnd= false;
    _boolOr= false;
    _boolNot= false;
    _boolTrue= false;
    _boolFalse= false;
    
    _tokenString = "";
    _lineNumber = line;
    _charPos = pos;
}

//set of return functions to tell if a token is if a given type.
bool& Token::isIdentifier(){ return _identifier;}
bool& Token::isDoubleQuote(){return _doubleQuote;}
bool& Token::isSingleQuote(){return _singleQuote;}
bool& Token::isSemicolon(){return _semicolon;}
bool& Token::isComma(){return _comma;}
bool& Token::isEOF(){return _eof;}

bool& Token::isLParen(){return _LParen;}
bool& Token::isRParen(){return _RParen;}
bool& Token::isLBrace(){return _LBrace;}
bool& Token::isRBrace(){return _RBrace;}
bool& Token::isLBracket(){return _LBracket;}
bool& Token::isRBracket(){return _RBracket;}

bool& Token::isAssignmentOperator(){return _assignmentOperator;}
bool& Token::isModulo(){return _modulo;}
bool& Token::isPlus(){return _plus;}
bool& Token::isMinus(){return _minus;}
bool& Token::isAsterisk(){return _asterisk;}
bool& Token::isDivide(){return _divide;}
bool& Token::isCarot(){return _caret;}

bool& Token::isInt(){return _int;}
bool& Token::isDouble(){return _double;}
bool& Token::isChar(){return _char;}
bool& Token::isString(){return _string;}

bool& Token::isBoolE(){return _boolE;}
bool& Token::isBoolNE(){return _boolNE;}
bool& Token::isBoolGT(){return _boolGT;}
bool& Token::isBoolLT(){return _boolLT;}
bool& Token::isBoolGTE(){return _boolGTE;}
bool& Token::isBoolLTE(){return _boolLTE;}
bool& Token::isBoolAnd(){return _boolAnd;}
bool& Token::isBoolOr(){return _boolOr;}
bool& Token::isBoolTrue(){return _boolTrue;}
bool& Token::isBoolFalse(){return _boolFalse;}



//create setter functions
void Token::setIdentifier(std::string input) { 
    _identifier = true;
    _tokenString = input;
 }
void Token::setDoubleQuote(){ _doubleQuote = true; }
void Token::setSingleQuote(){ _singleQuote = true; }
void Token::setSemicolon(){ _semicolon = true; }
void Token::setComma(){ _comma = true; }
void Token::setEndOfFile(){ _eof = true; }

void Token::setLParen(){ _LParen = true; }
void Token::setRParen(){ _RParen = true; }
void Token::setLBrace(){ _LBrace = true; }
void Token::setRBrace(){ _RBrace= true; }
void Token::setLBracket(){ _LBracket = true; }
void Token::setRBracket(){ _RBracket = true; }

void Token::setAssignmentOperator() { _assignmentOperator = true; }
void Token::setModulo(){ _modulo = true; }
void Token::setPlus(){ _plus = true; }
void Token::setMinus(){ _minus = true; }
void Token::setAsterisk(){ _asterisk = true; }
void Token::setDivide(){ _divide = true; }
void Token::setCarot(){ _caret = true; }

void Token::setInt(std::string input) { 
    _int = true;
    _tokenString = input;
}
void Token::setDouble(std::string input){
     _double = true; 
     _tokenString = input;
}
void Token::setChar(std::string input){
     _char = true;
     _tokenString = input;
}
void Token::setString(std::string input){
     _string = true;
     _tokenString = input;
}

void Token::setBoolE(){ _boolE= true; }
void Token::setBoolNE(){ _boolNE= true; }
void Token::setBoolGT(){ _boolGT= true; }
void Token::setBoolLT(){ _boolLT= true; }
void Token::setBoolGTE(){ _boolGTE= true; }
void Token::setBoolLTE(){ _boolLTE= true; }
void Token::setBoolAnd(){ _boolAnd= true; }
void Token::setBoolOr(){ _boolOr= true; }
void Token::setBoolTrue(){ _boolTrue= true; }
void Token::setBoolFalse(){ _boolFalse= true; }

//or we want to return the token string.
std::string Token::getTokenString() { return _tokenString; }

void Token::setTokenString(std::string dataString) {
    _tokenString = dataString;
}

//and ofc a function to print out tokens.
void Token::print() {

    //spits out line number and position of token.
    //std::cout << "[" << std::setw(2) << _lineNumber << ", " << std::setw(3) << _charPos << "] ";

    //its a + opperator just print out + dont store anything in the string for that token
    if (isEOF()) {

    }else{
        std::cout<<std::endl;
        std::cout<< "Token type: ";

        if(isIdentifier()){
            std::cout<< "IDENTIFIER" <<std::endl;
            std::cout<<"Token:      "<<_tokenString<<std::endl;
        }else if(isDoubleQuote()){
            std::cout<< "DOUBLE_QUOTE" <<std::endl;
            std::cout<<"Token:      "<<"\""<<std::endl;
        }else if(isSingleQuote()){
            std::cout<< "SINGLE_QUOTE" <<std::endl;
            std::cout<<"Token:      "<<"'"<<std::endl;
        }else if(isSemicolon()){
            std::cout<< "SEMICOLON" <<std::endl;
            std::cout<<"Token:      "<<";"<<std::endl;
        }else if(isComma()){
            std::cout<< "COMMA" <<std::endl;
            std::cout<<"Token:      "<<","<<std::endl;
        }else if(isLParen()){
            std::cout<< "LEFT_PARENTHESIS" <<std::endl;
            std::cout<<"Token:      "<<"("<<std::endl;
        }else if(isRParen()){
            std::cout<< "RIGHT_PARENTHESIS" <<std::endl;
            std::cout<<"Token:      "<<")"<<std::endl;
        }else if(isLBrace()){
            std::cout<< "LEFT_BRACE" <<std::endl;
            std::cout<<"Token:      "<<"{"<<std::endl;
        }else if(isRBrace()){
            std::cout<< "RIGHT_BRACE" <<std::endl;
            std::cout<<"Token:      "<<"}"<<std::endl;
        }else if(isLBracket()){
            std::cout<< "LEFT_BRACKET" <<std::endl;
            std::cout<<"Token:      "<<"["<<std::endl;
        }else if(isRBracket()){
            std::cout<< "RIGHT_BRACKET" <<std::endl;
            std::cout<<"Token:      "<<"]"<<std::endl;
        }else if(isAssignmentOperator()){
            std::cout<< "ASSIGNMENT_OPERATOR" <<std::endl;
            std::cout<<"Token:      "<<"="<<std::endl;
        }else if(isModulo()){
            std::cout<< "MODULUS" <<std::endl;
            std::cout<<"Token:      "<<"%"<<std::endl;
        }else if(isPlus()){
            std::cout<< "PLUS" <<std::endl;
            std::cout<<"Token:      "<<"+"<<std::endl;
        }else if(isMinus()){
            std::cout<< "MINUS" <<std::endl;
            std::cout<<"Token:      "<<"-"<<std::endl;
        }else if(isAsterisk()){
            std::cout<< "ASTERISK" <<std::endl;
            std::cout<<"Token:      "<<"*"<<std::endl;
        }else if(isDivide()){
            std::cout<< "DIVISION" <<std::endl;
            std::cout<<"Token:      "<<"/"<<std::endl;
        }else if(isCarot()){
            std::cout<< "CARET" <<std::endl;
            std::cout<<"Token:      "<<"^"<<std::endl;
        }else if(isInt()){
            std::cout<< "INTEGER" <<std::endl;
            std::cout<<"Token:      "<<_tokenString<<std::endl;
        }else if(isDouble()){
            std::cout<< "DOUBLE" <<std::endl;
            std::cout<<"Token:      "<<_tokenString<<std::endl;
        }else if(isChar()){
            std::cout<< "CHAR" <<std::endl;
            std::cout<<"Token:      "<<_tokenString<<std::endl;
        }else if(isString()){
            std::cout<< "STRING" <<std::endl;
            std::cout<<"Token:      "<<_tokenString<<std::endl;
        }else if(isBoolE()){
            std::cout<< "BOOLEAN_EQUAL" <<std::endl;
            std::cout<<"Token:      "<<"=="<<std::endl;
        }else if(isBoolNE()){
            std::cout<< "BOOLEAN_NOT_EQUAL" <<std::endl;
            std::cout<<"Token:      "<<"!="<<std::endl;
        }else if(isBoolGT()){
            std::cout<< "BOOLEAN_GREATER_THAN" <<std::endl;
            std::cout<<"Token:      "<<">"<<std::endl;
        }else if(isBoolLT()){
            std::cout<< "BOOLEAN_LESS_THAN" <<std::endl;
            std::cout<<"Token:      "<<"<"<<std::endl;
        }else if(isBoolGTE()){
            std::cout<< "BOOLEAN_GREATER_THAN_OR EQUAL" <<std::endl;
            std::cout<<"Token:      "<<">="<<std::endl;
        }else if(isBoolLTE()){
            std::cout<< "BOOLEAN_LESS_THAN_OR EQUAL" <<std::endl;
            std::cout<<"Token:      "<<"<="<<std::endl;
        }else if(isBoolAnd()){
            std::cout<< "BOOLEAN_AND" <<std::endl;
            std::cout<<"Token:      "<<"&&"<<std::endl;
        }else if(isBoolOr()){
            std::cout<< "BOOLEAN_OR" <<std::endl;
            std::cout<<"Token:      "<<"||"<<std::endl;
        }else if(isBoolTrue()){
            std::cout<< "BOOLEAN_TRUE" <<std::endl;
            std::cout<<"Token:      "<<"True"<<std::endl;
        }else if(isBoolFalse()){
            std::cout<< "BOOLEAN_FALSE" <<std::endl;
            std::cout<<"Token:      "<<"False"<<std::endl;
        }else{
        std::cout << "Token::print -- unknown token.\n" << std::endl;
        exit(3);
        }
    }

}

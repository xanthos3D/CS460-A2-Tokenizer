/** ***************************************************************************
 * @remark CS 460: Definition of Parser class
 *
 * @author Luis Galvez
 *         Xander
 *         Christian Gonzalez
 *         Anthony Manese
 *
 * @file  Parser.hpp
 * @date  Fall 2024
 **************************************************************************** */

#ifndef PROJECT1_PHASE2_PARSER_HPP
#define PROJECT1_PHASE2_PARSER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "CST.h"

class Parser {
public:
    Parser(Tokenizer& tokenizer) : tokenizer(tokenizer), currentToken(tokenizer.getToken()), cst(new CST()) {}
    CST* parse();
private:
    Tokenizer tokenizer;
    Token currentToken;
    CST* cst;
};


#endif //PROJECT1_PHASE2_PARSER_HPP

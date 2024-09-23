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
#include "CST.h"

class Parser {
public:
    Parser( std::string  );
    void BuildCST( CST, std::vector<Token> );
    void printCST();
private:

};


#endif //PROJECT1_PHASE2_PARSER_HPP

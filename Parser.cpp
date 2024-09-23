#include <iostream>
#include "Parser.hpp"
#include "CST.h"
#include "CSTNode.h"
#include "stack"

CST* Parser::parse() {
    cst->setRoot(new CSTNode("Program")); // Setting a root node for the program
    while (!currentToken.isEOF()) {
        Declaration(cst->root);
    }
    return cst;
}

void Declaration(){
}
void Expression(){

}
void eat(TokenType type) {
    if (currentToken.type == type) {
        currentToken = tokenizer.getNextToken();
    } else {
        error("Unexpected token: " + currentToken.value);
    }
}

void functionDefinition(CSTNode* parent) {

}

void variableDeclaration(CSTNode* parent) {
}

void statement(CSTNode* parent) {
#ifndef CS460_A2_TOKENIZER_CSTNODES_H
#define CS460_A2_TOKENIZER_CSTNODES_H
#include <iostream>
#include <fstream>
#include <string>
#include "Token.hpp"

class CSTNodes {
public:
    CSTNodes(Token t) : token(t), leftChild(nullptr), rightSibling(nullptr) {}
    ~CSTNodes() {
        leftChild(nullptr);
        rightSibling(nullptr);
    }
    CSTNodes *leftChild() { return left; }
    CSTNodes *rightSibling() { return right; }

    void leftChild( CSTNodes *newLeft ) { left = newLeft; }
    void rightSibling(CSTNodes *newRight) { right = newRight; }

    Token& token_value() { return token; }
private:
    CSTNodes *left, *right;
    Token token;
};


#endif //CS460_A2_TOKENIZER_CSTNODES_H

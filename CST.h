#ifndef CS460_A2_TOKENIZER_CST_H
#define CS460_A2_TOKENIZER_CST_H
#include <iostream>
#include <fstream>
#include <string>
#include "Token.hpp"
#include "CSTNode.h"

class CST {
public:
    CST() : root(nullptr) {}
    void setRoot(CSTNode* node) { root = node; }

private:
    CSTNode* root;
};


#endif //CS460_A2_TOKENIZER_CST_H

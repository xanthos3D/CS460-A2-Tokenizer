#ifndef CS460_A2_TOKENIZER_CST_H
#define CS460_A2_TOKENIZER_CST_H
#include <iostream>
#include <fstream>
#include <string>
#include "Token.hpp"

class CST {
public:
    CST();
    CST(std::vector<Token>);
    void SYA();
    void insert();
private:

};


#endif //CS460_A2_TOKENIZER_CST_H

//
// Created by xmani on 2/2/2023.
//
//
// Created by Ali Kooshesh on 1/22/23.
//

#include <iostream>
#include <string>
#include "Tokenizer.hpp"
//simple function that puts the fstream into the object

Tokenizer::Tokenizer(std::string name) : lineNumber{ 1 },
                                         charPosition{ 1 },
                                         inputFileName{ name } {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

//used to determine if a character is important, aka is a token we care about.
// for the case of our tokenizer there will be a lot.
bool Tokenizer::charOfInterest(char c) {
    

    //use code below as a example of how we may implement this depending on input. 
    //the code below was used to find a char of interest for comments like // and /*
    /*
    if (c == '/') {
        if (inputStream.peek() == '/') {
            //std::cout<< "found char of interest // "<<std::endl;
            return true;
        }else if(inputStream.peek() == '*'){
            //std::cout<< "found char of interest /* "<<std::endl;
            return true;
        }
        return false;

    }else if(c == '*') {
        if (inputStream.peek() == '/') {
            //std::cout<< "found char of interest "<<std::endl;
            return true;
        }
        return false;

    }else if(c == '\n'){
        //std::cout<< "found char of interest next line "<<std::endl;
        

        return true;
    }
*/
    return false; 
}

// function that makes the token.
Token Tokenizer::getToken() {
    // temp char to store input comming from the fstream
    char c;
    //temp string variable for storing tag.
    std::string tempText = "";

    // check to see if file is readable, if not printer error message.
    if (!inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    //this eats up all non esential input we dont care about, such as spaces not inside a string token.
    while (inputStream.get(c) && !charOfInterest(c)) {
        
        std::cout<< c;
        tempText += c;
        charPosition++;

    }

    // makes a token with the given line number and char position.
    Token token(lineNumber, charPosition);

    // after this point is where our DFA will be defined. we want various state to acount for scenarious like string tokens,
    // this tokenizer class has a int named state which we should use to keep track of the state as we tokenize.
    std::cout<< state << std::endl;

    //if we have reached the end of the file then we set the bool of current token to reflect that then we return token.
    if (inputStream.eof()) {
        token.setEndOfFile();
        return token;
    }else{
        // The condition of one of the above "if ... else if" statements should
        // evaluate to true because function charOfInterest return true when it
        // finds a character that is the start of some token and that the
        // "if ... else if" has one case for each character that starts a token.
        // Therefore, the control should never get here. However, it is always
        // a good idea to have an "else" when you have a sequence of "if ... else if"
        // statements so that you do not end up with a case that has not been handled.
        // For example, you forgot to account for one of the cases.
        std::cout << "There is a logic error in unction Tokenizer::getToken.\n";
        std::cout << "The function doesn't know how to process this character: ->" << c << "<-\n";
        exit(1);
    }

    //we should never return a token using this statement.
    return token;
}






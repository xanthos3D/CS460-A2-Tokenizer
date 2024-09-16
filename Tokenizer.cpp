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
    
    //fill out the list of character we want to look out for when looping
    //if char is a number or a alpha character then we found a craf of interest
    if (isalnum(c)) {
        return true;
    }else if(c == '*') {
        return true;
    }else if(c == '-'){
        return true;
    }else if(c == '+'){
        return true;
    }else if(c == '/'){
        return true;
    }else if(c == '='){
        return true;
    }

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

    // makes a token with the given line number and char position.
    Token token(lineNumber, charPosition);

    //state 0 of our dfa, havent seen any input or returning from previus states.
    if(state == 0){

    //std::cout<<"looping through on state 0"<<std::endl;
    //this eats up all non esential input we dont care about, such as spaces not inside a string token.
    while (inputStream.get(c) && !charOfInterest(c)) {
        charPosition++;

    }

    if (inputStream.eof()) {
        token.setEndOfFile();
        return token;
    //found a identifier
    }else if(isalnum(c)){
        //std::cout<<"found identifier"<<std::endl;
        //grab all the rest of the characters in the identifier
        tempText += c;
        while (inputStream.get(c) && c != ' ') {
        tempText += c;
        charPosition++;
        }

        //set token and return it
        token.setIdentifier(tempText);

        return token;

    }
    

    }


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






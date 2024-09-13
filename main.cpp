/* ***********************************************************************
team justice names here:
xander maniaci
Luis Galvez
Christian Gonzalez
Anthony Manese

how to compile program through terminal
1. g++ main.cpp Token.cpp Tokenizer.cpp
2. ./a.out programming_assignment_2-test_file_3.c

how to run makefile
1.  make
2. ./Tokenizer programming_assignment_2-test_file_3.c

description:
Write a program in C or C++ that tokenize a c file.

Write a program in C or C++ that will identify and remove comments from an input test file using 
a deterministic finite state automoton (DFA) then use a DFA to convert the input file into a series
of tokens. Lastly, your program should display the tokens as output (if no syntax errors occurred)
or an error message instead.
*********************************************************************** */
#include <iostream>
#include <fstream>
#include<stack>
#include "Token.hpp"
#include "Tokenizer.hpp"

using namespace std;

/** **************************************************************************************
function Headers
 *****************************************************************************************/
string commentParser(std::ifstream& inputStream,string fileName);
void parser(Tokenizer& tempTokenizer);
// functions to handle the open and close tags as they come into the parser.

/** **************************************************************************************
driver program
@pre: takes a input c file
@post: removes the comments in the .c file input and outputs a c file
 *****************************************************************************************/
int main(int argc, char *argv[]) {

    // we expect the name of the file as an argument to the program.
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
        exit(1);
    }

    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading

    if(!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }

    inputStream.close();

    std::cout << "found file: " <<argv[1] << std::endl;

    //create file name without the .c at the end
    string filename = argv[1];
    filename.pop_back();
    filename.pop_back();

    //makes our output file by calling our function
    string output = commentParser(inputStream,argv[1]);

    //name of our new file that we generated
    string tokenizeFile = filename + " without comments.c";

    //creates a decent name for each input file so it saves to different test files based on its name
    ofstream result("./" + tokenizeFile, ios::out);

    //pipe in the the file 
    result << output;

    result.close();

    // now we open the c code file we generated without comments, by making our tokenizer object and pass in the new file name.
    Tokenizer tokenizer(tokenizeFile);

    return 0;
}


/** **************************************************************************************
function to get tokens loop through file getting tokens from the tokenizer until we get to a eof token.
@pre: takes a tokenizer object
@post: makes a list of tokens out of our comment fre output file.
 *****************************************************************************************/
void parseTokens(Tokenizer& tempTokenizer){

    //gets the first token of the file
    Token tempToken = tempTokenizer.getToken();

    //as long as the token recieved is not a eof keep looping through the file.
    while (!tempToken.isEOF()) {
        //keep grabbing new tokens and setting the next token as temptoken until we 
        //run out of tokens.
    
    }



}


/** **************************************************************************************
function to remove comments by using a dfa to traverse through our file.
@pre: takes a ifstream object and a filename
@post: removes the comments in the .c file input and outputs a c file
 *****************************************************************************************/
string commentParser(std::ifstream& inputStream,string fileName){

    inputStream.open(fileName, std::ios::in);

    string file = "";
    int state = 0;
    char c;
    int lineNumber = 1;
    int startOfComment = -1;

    //keep looping through our dfa as long as we have input to read
    while (!inputStream.eof()){

        cout<<c;
        inputStream.get(c);

        //state 0 grabs everything until we reach a /
        if(state == 0 ) {
            //if we find a slash then we want to transition to state 1
            if (c == '/') {
                state = 1;
                //otherwise add the input to the file.
            } else{
                if (c == '"') {
                    state = 5;
                } else if (c == '\n') {
                    ++lineNumber;
                } else if (c == '*') {
                    state = 6;
                }
                file += c;
            }
            // if we find a / then we need to check if the next char is a * or a /
        }else if(state == 1){
            //if we find a slash after the initial slash then we are in a c style comment so progress to state 2
            if(c == '/'){
                //adds two spaces to the file to account for the double slash.
                file +="  ";
                state = 2;
                //otherwise if we find a /* then progress to state 3 c++ style comment
            }else if(c == '*'){
                //adds two spaces to the file to account for the slash star.
                file +="  ";
                state = 3;
                //The beginning of a comment block that we need to keep track of if never closed
                startOfComment = lineNumber;
                // otherwise we are not in a comment back to state 0
            }else{
                //add the / since not a comment
                file +='/';
                //add the new char c as well since not in comment
                file +=c;
                state = 0;
            }
            //if we are in a c style comment then
        }else if(state == 2){
            //if we find a next line char then c style comment is done, back to state 0
            if(c == '\n'){
                file +=c;
                state = 0;
                //keep track of the line we are by increasing every time we encounter a new line
                ++lineNumber;
            }else{
                //replace that comment with spaces
                file +=' ';
            }
            //state for being inside a c++ style comment
        }else if(state == 3){
            //if we find a next line char then c style comment is done, back to state 0
            if(c == '*'){
                file +=' ';
                state = 4;
                //if we find a next line char then preserve it.
            }else if(c == '\n') {
                file += c;
                ++lineNumber;
            }else{
                //replace that comment with spaces
                file +=' ';
            }
            //state to check if c++ style comment should be ending
        }else if(state == 4){
            //if we find a next line char then c style comment is done, back to state 0
            if(c == '/'){
                //set double space to handle places where */ should be
                file +=" ";
                state = 0;
            }else if(c == '*'){
                //set double space to handle places where */ should be
                file +=" ";
            }else if(c == '\n'){
                file +=c;
                ++lineNumber;
            }else{
                //replace that comment with spaces
                file +=" ";
                state = 3;
            }
            //set input in comments to white space unless we find a next line character
        } else if (state == 5){
            if ( c=='"'){
                state = 0;
            }
            file += c;
        } else if (state == 6){
            if (c == '/'){
                startOfComment = lineNumber;
                break;
            }
            file +=c;
            state = 0;
        }
    }
    //output error message if: inside a never ending c++ comment (/* without the */) or if end of c++ comment is read without the starting of the comment (*/ without the /*)
    if ( state == 3 || state == 4 || !inputStream.eof()){
        cout << "ERROR: Program contains C-style, unterminated comment starting on line " << startOfComment << endl;
        exit(1);
    }

    inputStream.close();

    cout<<endl;
    cout<<"==================output file=================="<< endl;
    cout<< file;

    return file;



}

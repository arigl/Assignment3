/*
 Alex Rigl
 Student ID: 2300146
 Email: crigl@chapman.edu
 Class: CPSC 350
 Section: 2
 Assignment 3: Syntax Checker
 Purpose: Declares variables that will be used in Delimiter.cpp
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SyntaxChecker {
    public:
        SyntaxChecker(); //Constructor
        ~SyntaxChecker(); //Destructor

        int checkSyntax(string fileName); //takes in a filename and determines if the syntax is correct or not 

        char x; // stores the peek of the stack
        bool cont; // determines whether the loop should continue;
        string repeat; // whether or not to check a new file
        int counter; // location in the file
        bool errors; // if there are errors or not
        int quoteCount; // used to determine if the data is within quotes
        bool same; // if the quotes are the same index
        bool quote; // if the data is within a quote
        bool comment; // if the data is within a comment
};

/*
 Alex Rigl
 Student ID: 2300146
 Email: crigl@chapman.edu
 Class: CPSC 350
 Section: 2
 Assignment 3: Syntax Checker
 Purpose: Executes classes and methods to ensure the syntax is correct in a given document
 */

#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"
#include "SyntaxChecker.h"

using namespace std;

int main(int argc, char** argv) {
    SyntaxChecker sc; // Creates a delimiter to check the syntax

    if (argc != 2) // checks for the correct type in the arguements
    {
        cout << "Please enter a valid input type." << endl;
    }
    else
    {
        string file = argv[1]; // takes in the file name from the arguments
        file = file.c_str();
        sc.checkSyntax(file); // calls the method in SyntaxChecker with the filename
    }

    return 0;
}

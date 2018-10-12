/*
 Alex Rigl
 Student ID: 2300146
 Email: crigl@chapman.edu
 Class: CPSC 350
 Section: 2
 Assignment 3: Syntax Checker
 Purpose: Analyzes source code and determines whether or not the syntax is correct, it looks for () {} [] // ""
 Code that is commented or is in quotes will be ignored
 */

#include "SyntaxChecker.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

SyntaxChecker::SyntaxChecker()
{
  // Constructor
}


SyntaxChecker::~SyntaxChecker()
{
  // Destructor
}

int SyntaxChecker::checkSyntax(string fileName)
{
    // Definining Variables
    GenStack<char> myStack(100);
    cont = true;


    while (cont) // loop until error or user exit
    {
        // Create a file and open in
        ifstream inFile; // creates a variable for opening a file
        inFile.open(fileName); // opens a file from the arguments

        // Checks if the file is availble or not
        if (!inFile) {
          cerr << "Unable to open file " << fileName << endl;;
          exit(1);
        }

        // Iterates through each line in the File
        counter = 1; // counts which line the for loop is on
        quoteCount = 0;
        same = false;
        quote = false;
        comment = false;

        for(std::string line; getline( inFile, line ); )
        {
            // Iterates through the line
            for (int i = 0; i < line.size(); ++i)
            {
                // Checks for commented out code, ingore the rest of the sentence if commented
                if (line[i] == '/' && line[i+1] == '/'){
                  comment = true;
                }

                if (line[i] == '"' && quoteCount == 0){
                  quoteCount++;
                  same = true;
                  quote = true;
                }
                if (line[i] == '"' && quoteCount == 1 && same == false){
                  quoteCount--;
                  quote = false;
                }
                same = false;

                // Checks for each the different syntax types
                if (((line[i] == '('||(line[i] == ')'))||((line[i] == '[')||(line[i] == ']'))||((line[i] == '{')||(line[i] == '}'))) && quote == false && comment == false)
                {
                    x = myStack.peek(); // peeks the first value in the stack

                    // Checks to see if the stack matches up with the corresponding syntax in the line
                      if (((x == ('('))&&(line[i] == ')')) || ((x == ('{'))&&(line[i] == '}')) || ((x == ('['))&&(line[i] == ']'))) {
                          myStack.pop();
                      }
                      // Checks for mismatching syntaxes
                      else if ((x == '(')&&(line[i] == '}')) {
                          cout << "Line " << counter << ": expected ) and found " << line[i] << endl;
                          return 0;
                      }
                      else if ((x == '(')&&(line[i] == ']')) {
                          cout << "Line " << counter << ": expected ) and found ]" << endl;
                          return 0;
                      }
                      else if ((x == '[')&&(line[i] == ')')) {
                        cout << "Line " << counter << ": expected ] and found )"<< endl;
                          return 0;
                      }
                      else if ((x == '[')&&(line[i] == '}')) {
                        cout << "Line " << counter << ": expected ] and found }"<< endl;
                          return 0;
                      }
                      else if ((x == '{')&&(line[i] == ')')) {
                        cout << "Line " << counter << ": expected } and found )"<< endl;
                          return 0;
                      }
                      else if ((x == '{')&&(line[i] == ']')) {
                        cout << "Line " << counter << ": expected } and found ]"<< endl;
                          return 0;
                      }
                    // checks if there is no ending to the syntax
                      else if ((line[i] == '(')||(line[i] == '[')||(line[i] == '{')) {
                        myStack.push(line[i]); // pushes the line to the stack for further chekcing
                      }
                }
            }
            ++counter; // counts the number of lines
            comment = false;
        }
        errors = myStack.isEmpty();
        if (errors) // if there is no more items in the stack
        {
          cout << "There are no errors. :)" << endl;
          cout << "Would you like to check another file? (1 for yes, 0 for no) ";
          cin >> repeat; // asks the user whether or not they want to analyze another file

          if (repeat == "1")
          {
              cout << "Enter the name of your file ";
              cin >> fileName; // takes in the new filename here
              continue; // goes to the end of the if statement
          }
          else
          {
              cont = false; // signals and end to the while loop
          }
        }
        else
        {
          // There is no match for a specified syntax
          cout << "Reached end of file missing match for:  " << myStack.peek() << endl;
          return 0;
        }
    }
    return 0; // end program
}

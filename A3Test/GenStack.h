/*
 Alex Rigl
 Student ID: 2300146
 Email: crigl@chapman.edu
 Class: CPSC 350
 Section: 2
 Assignment 3: Syntax Checker
 Purpose: Makes a genstack that will store data, and allows you to remove, add, and look at variables
 */

#include <iostream>
#include <string>

using namespace std;

template <class T>
class GenStack {
    private:

    public:
        GenStack(int maxSize); //Constructor
        ~GenStack(); //Destructor

        void push(T data); // adds a data value to the stack
        T pop(); // removes a data value from the stack
        T peek(); //indexes a value from the stack

        bool isFull(); // determines whether or not the stack is full
        bool isEmpty(); // determines whether or not the stack contains anything
        void expand(); // increases the size of the stack

        int size; // keeps track of the size of the stack
        int top; // keeps track of the index of the top of the stack

        T *myArray; // defines an array to hold the stack
        T *temp; // used for increasing size
};

//Constructor
template <class T>
GenStack<T>::GenStack(int maxSize) {
    myArray = new T[maxSize]; // make sa new array based on maxSize
    size = maxSize; // takes in a size from main, typically 10 or 100
    top = -1; // sets default value of top to -1
    temp = new T[size]; // creates a new temp array
}

//Destructor
template <class T>
GenStack<T>::~GenStack() {
    delete []myArray; // deletes the array to save memory
    delete []temp; // deletes the temp array to save memory
}

template <class T>
void GenStack<T>::push(T data) {
  // if the stack is full expand size
    if (isFull() == true) {
        expand();
        push(data);
    }
  // otherwise add the data to the stack, and increase the top size
    else {
        myArray[++top] = data;
    }
}

template <class T>
T GenStack<T>::pop() {
  // if empty, don't remove and display error message
    if (isEmpty() == true)
    {
        cout << "stack is empty" << endl;
        return 0;
    }
  // remove the top
    else
    {
        return myArray[top--];
    }
}

template <class T>
T GenStack<T>::peek() {
    // if the stack is empty, return 0
    if (top == -1) {
        return 0;
    }
    // otherwise return the top of the stack
    else {
        return myArray[top];
    }
}

template <class T>
bool GenStack<T>::isFull() {
    // if the top is almost the max size, dont add anymore
    return (top == size - 1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
    // if there are no values in the stack, return true
    return (top == -1);
}

template <class T>
void GenStack<T>::expand() {
    // Makes a new temp array
    temp = new T[size];
    // Makes a new array with increased size
    myArray = new T[size+1];

    for (int i = top; i > -1; --i)
    {
        // transfer data from the temp array to the new array
        temp[i] = myArray[i];
        myArray[i] = temp[i];
    }
}

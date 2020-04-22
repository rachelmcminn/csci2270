#include "RPNCalculator.hpp"
#include <iostream>
#include <string>
using namespace std;

/*
Operand* stackHead{
    
}
*/

RPNCalculator::RPNCalculator(){ //constructor
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){ //destructor
    while(stackHead != NULL){
        pop();
    }
    stackHead = NULL;
}

bool RPNCalculator::isEmpty(){ //checks if stack is empty
    if(stackHead == NULL){ //if head is null, its an empty list
        return true;
    }
    else{
        return false;
    }
}

void RPNCalculator::push(float number){//push element onto stack
    Operand* newNum = new Operand; //declare space for new number
    newNum->number = number;
    if(isEmpty()){
        stackHead = newNum;
        newNum->next = NULL;
    }
    else{
        newNum->next = stackHead;
        stackHead = newNum;
    }
    
}

void RPNCalculator::pop(){ //delete topmost item from stack
    Operand* temp = new Operand; //declare space for temp
    temp = stackHead;
    if(isEmpty()){
        cout << "Stack empty, cannot pop an item." << endl;
        return;
    }
    else{
        stackHead = stackHead->next;
        delete temp;
    }

}

Operand* RPNCalculator::peek(){
    if(isEmpty()){
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
    else{
        return stackHead;
    }
}

bool RPNCalculator::compute(std::string symbol){
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;

    if(symbol == "+" || symbol == "*"){ //if symbol is * or +
        if(stackHead == NULL){ //if stack is empty
            cout << "err: not enough operands" << endl;
            return false;
        }

        Operand* temp = new Operand;
        temp = NULL;
        a = stackHead->number;

        if(stackHead->next == NULL){
            cout << "err: not enough operands" << endl;
            return false;
        }
        b = stackHead->next->number;

        if(symbol == "+"){
            c = a + b;
            pop();
            pop();
            push(c);
            return true;
        }
        if(symbol == "*"){
            c = a*b;
            pop();
            pop();
            push(c);
            return true;
        } 

    }
    
    else{
        cout << "err: invalid operation" << endl;
    } 
    return false;

}


/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>

// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  string input;
  RPNCalculator calc;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, input); //read input
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */
   
   if(isNumber(input) == true){ //if input is a number
      calc.push(stof(input)); //push onto stack
   }
   if(input == "+"){ //if user enters + operand
     calc.compute("+"); //compute 
   }
   if(input == "*"){ //if user enters * operand
      calc.compute("*"); //compute
   }

    /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */

   if(input == "="){
     if(calc.isEmpty()){ //if stack is empty
       cout << "No operands: Nothing to evaluate" << endl;
       return 0;
     }

     /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/
      Operand *temp = new Operand;
      temp = calc.peek();

     if(temp->next != NULL){ //if theres more than one item left on the stack, input is invalid
       cout << "Invalid expression" << endl;
       return 0;
     }
     else{ //otherwise, print the result of the expression
       cout << temp->number << endl; //print the numbers, setprecision 4
        break; //without this had an error (invalid argument stof no conversion)
     }
   }
  }
  return 0;
}

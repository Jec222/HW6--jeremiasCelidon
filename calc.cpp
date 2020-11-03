#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include "dlist.h"

using namespace std;

int main2 () {
  Dlist<double> stack;
  string input;
  while (cin >> input) {
    if(input == "q"){
      break;
    }
    else if(isdigit(input[0])){
      double given = atof(input.c_str());
      stack.InsertFront(given);
    }
    else if(input == "+" || input == "-" || input == "*"){
      if(!stack.IsEmpty()){
        double number1 = stack.RemoveFront();
        if(!stack.IsEmpty()){
          double number2 = stack.RemoveFront();
          if(input == "+"){
            stack.InsertFront(number1 + number2);
          }
          else if(input == "-"){
            stack.InsertFront(number2 - number1);
          }
          else{
            stack.InsertFront(number1*number2);
          }
        }
        else{
          stack.InsertFront(number1);
          cout << "Not enough operands\n";
        }
      }
      else{
        cout << "Not enough operands\n";   
      }
    }
    else if(input.size() == 1){
      char operation = input[0];
      switch(operation){
        case '/':
          if(!stack.IsEmpty()){
            double number1 = stack.RemoveFront();
            if(number1 > 0){
              if(!stack.IsEmpty()){
                double number2 = stack.RemoveFront();
                stack.InsertFront(number1/number2);
              }
              else{
                stack.InsertFront(number1);
                cout << "Not enough operands\n";
                break;
              }
            }
            else{
              cout << "Divide by zero\n";
              stack.InsertFront(number1);
              break;
            }
          }
          else{
            cout << "Not enough operands\n";
            break;
          }
          break;
        case 'n':
          if(!stack.IsEmpty()){
            double number1 = stack.RemoveFront();
            stack.InsertFront(-1*number1);
          }
          else{
            cout << "Not enough operands\n";
            break;
          }
          break;
        case 'd':
          if(!stack.IsEmpty()){
            double number1 = stack.RemoveFront();
            stack.InsertFront(number1);
            stack.InsertFront(number1);
          }
          else{
            cout << "Not enough operands\n";
            break;
          }
          break;
        case 'r':
          if(!stack.IsEmpty()){
            double number1 = stack.RemoveFront();
            if(!stack.IsEmpty()){
              double number2 = stack.RemoveFront();
              stack.InsertFront(number1);
              stack.InsertFront(number2);
            }
            else{
              stack.InsertFront(number1);
              cout << "Not enough operands\n";
              break;
            }
          }
          else{
            cout << "Not enough operands\n";
            break;
          }
          break;
        case 'p':
          if(!stack.IsEmpty()){
            double number1 = stack.RemoveFront();
            cout << number1 <<endl;
            stack.InsertFront(number1);
          }
          else{
            cout << "Not enough operands\n";
            break;
          }
          break;
        case 'c':
          while(!stack.IsEmpty()){
            stack.RemoveFront();
          }
          break;
        case 'a':
          Dlist<double> reference;
          if(stack.IsEmpty()== true){
            cout << "Not enough operands\n";
            break;
          }
          while(!stack.IsEmpty()){
            double num = stack.RemoveFront();
            cout << num << " ";
            reference.InsertBack(num);
          }
          cout << endl;
          stack = reference;
          break;         
      }
    }
    else{
      cout << "Bad input" << endl;  
    }
  
  }

  return 0;

}

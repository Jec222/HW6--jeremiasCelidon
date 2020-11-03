/* Pseudocode:
----------------
create a stack using Dlist 

create a data value to store the data in 

While data is still being read 

  if data char convert to string to keep stack with same data type

  if data is a + - *
    pop stack.RemoveFront()
      make sure stack not empty for each operand + - *
        pop stack.RemoveFront()
        perform desired operand pop stack.RemoveFront()

      if stack empty insert element poped
        Dysplay Not enough operands

  if input size equals to 1 
    set iqual to operation 
      switch(operation)
        operation = /
          if stack not emply  
            RemoveFront()
            if RemoveFront() is grather than 0
              check stack not empty 
                RemoveFront()
                InsertFront with the division of the fist pop and second pop
              else 
                Dysplay Not enough operands
            else
              Dysplay Divide by zero
          else
            Dysplay  Not enough operands
        operation = n
          if stack is not emply 
            InsertFront(-1*RemoveFront())
          else
            Dysplay Not enough operands
        operation = d
          if stack is not empty 
            pop first element and store in value copy
            InsertFront twise with copy 
          else
            Dysplay Not enough operands
        operation = r
          if stack is not empty 
            pop first elemet 
            checkif stack is not empty
              pop second elemet 
              InsertFront(first element)
              InsertFront(second element)
            else
              InsertFront(first element)
              Display Not enough operands
          else
            Display Not enough operands
        operation = p
          if stack is not empty 
           pop fisrt element Display insert again 
          else
            Display Not enough operands
        operation = c
          while stack not empty
            remove front
        operation = a
          create a temp stack 

          if is empty 
            Dysplay Not enough operands
          while is not empty 
            pop and print 
            insert pop temp stack

          set old stack equal to temp
           
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include "dlist.h"

int main() {

  Dlist<double> stack_calc;
  std::string Data;

  while (std::cin >> Data) {

    if(isdigit(Data[0])){
      double read = atof(Data.c_str());
      stack_calc.InsertFront(read);
    }
    if(Data == "*" || Data == "-" || Data == "+"){
      if(!stack_calc.IsEmpty()){

        double first_num = stack_calc.RemoveFront();

        if(!stack_calc.IsEmpty()){

          double second_num = stack_calc.RemoveFront();
          if(Data == "*")
            stack_calc.InsertFront(first_num * second_num);
          
          if(Data == "-")
            stack_calc.InsertFront(second_num - first_num);
    
          if(Data == "+")
            stack_calc.InsertFront(first_num + second_num);
        }
        else{
          stack_calc.InsertFront(first_num);
          std::cout << "Not enough operands\n";
        }
      }
      else{
        std::cout << "Not enough operands\n";   
      }
    }
    if(Data.size() == 1){
      char oparand = Data[0];
      switch(oparand){
        case '/':
          if(!stack_calc.IsEmpty()){
            if(double first_num = stack_calc.RemoveFront() > 0){
              if(!stack_calc.IsEmpty()){
                stack_calc.InsertFront(first_num/stack_calc.RemoveFront());
                break;
              }
            
              else{
                stack_calc.InsertFront(first_num);
                std::cout << "Not enough operands\n";
                break;
              }
            }
            else{
              std::cout << "Divide by zero\n";
              stack_calc.InsertFront(first_num);
              break;
            }
          }
          else{
            std::cout << "Not enough operands\n";
            break;
          }
        case 'n':
          if(!stack_calc.IsEmpty()){
            stack_calc.InsertFront(-1*stack_calc.RemoveFront());
            break;
          }
          else{
            std::cout << "Not enough operands\n";
            break;
          }
  
        case 'd':
          if(!stack_calc.IsEmpty()){
            double copy = stack_calc.RemoveFront();
            stack_calc.InsertFront(copy);
            stack_calc.InsertFront(copy);
            break;
          }
          else{
            std::cout << "Not enough operands\n";
            break;
          }
        case 'r':
          if(!stack_calc.IsEmpty()){
            double first_num = stack_calc.RemoveFront();
            if(!stack_calc.IsEmpty()){
              double second_num = stack_calc.RemoveFront();
              stack_calc.InsertFront(first_num);
              stack_calc.InsertFront(second_num);
              break;
            }
            else{
              stack_calc.InsertFront(first_num);
              std::cout << "Not enough operands\n";
              break;
            }
          }
          else{
            std::cout << "Not enough operands\n";
            break;
          }

        case 'p':
          if(!stack_calc.IsEmpty()){
            double print = stack_calc.RemoveFront();
            std::cout << print <<std::endl;
            stack_calc.InsertFront(print);
            break;
          }
          else{
            std::cout << "Not enough operands\n";
            break;
          }
        case 'c':
          while(!stack_calc.IsEmpty()){
            stack_calc.RemoveFront();
          }
          break;
        case 'a':
          Dlist<double> temp;
          if(stack_calc.IsEmpty()== true){
            std::cout << "Not enough operands\n";
            break;
          }
          while(!stack_calc.IsEmpty()){
            double print = stack_calc.RemoveFront();
            std::cout << print << " ";
            temp.InsertBack(print);
          }
          std::cout << std::endl;
          stack_calc = temp;
          break;         
      }
    }
    else{
      std::cout << "Bad Data" << std::endl;  
    }
    if(Data == "q")
      break;
  }
  return 0;
}

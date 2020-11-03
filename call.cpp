/* Pseudocode:
---------------
Initialize a struct for Customers 
struct Costumer {
 
  Initialize time_stamp
  Initialize name
  Initialize status
  Initialize int tick 

void CostumersData
  
  will create a new costumer 
  will read data from a file and will store it in 
  time stamp name status tick in that order  
  will insert it in a queue of costumers 

    if (Costumer_tick == new_Costumer->time_stamp) 
      Costumer_tick = Costumer_tick + new_Costumer->tick;

    if (Costumer_tick < new_Costumer->time_stamp)
      Costumer_tick = new_Costumer->time_stamp + new_Costumer->tick;

    else 
      Costumer_tick += new_Costumer->tick;

  }


void KeepTime(int current, Dlist<Costumer*> &Costumer_list) {
  
  Costumer* Costumer = Costumer_list.RemoveFront();
  
  while (Costumer->time_stamp == current) {
    
    if (Costumer->status == "none") 
      std::cout<<"Call from "<<Costumer->name<<" a regular member\n"; 
    else 
      std::cout<<"Call from "<<Costumer->name<<" a "<<Costumer->status<<" member\n"; 
    
    Costumer = Costumer_list.RemoveFront();
  }
  Costumer_list.InsertFront(Costumer);
}
void Add (Costumer* current, Dlist<Costumer*> &answer_list) {
  Costumer* new_Costumer = new Costumer;
  new_Costumer->time_stamp = current->time_stamp;
  new_Costumer->name = current->name;
  new_Costumer->status = current->status;
  new_Costumer->tick = current->tick;
  answer_list.InsertBack(new_Costumer);
}
void List(int event_number, Dlist<Costumer*> Costumer_list, Dlist<Costumer*> &answer_list) {
  int temp = event_number;
  
  for  ( int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "platium" ) {
      Add(current,answer_list);
      temp--;
    } else {
      Costumer_list.InsertBack(current);
    }
  }
  event_number = temp;
  for (int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "gold" ) {
      Add(current,answer_list);
      temp--;
    }
    else 
      Costumer_list.InsertBack(current);
  }

  event_number = temp;
  for (int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "silver" ) {
      Add(current,answer_list);
      temp--;
    } else {
      Costumer_list.InsertBack(current);
    }
  }
  //REGULAR MEMBERS
  event_number = temp;
  for (int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "none" ) {
      Add(current,answer_list);
      temp--;
    } else 
        Costumer_list.InsertBack(current);
    
  }
}
void Answer(int current, Dlist<Costumer*> &answer_list) {

  Costumer* Costumer = answer_list.RemoveFront();
    if (Costumer->time_stamp > current) {
      Answer(current, answer_list);
      
      Costumer* next_Costumer = answer_list.RemoveFront();
      if (next_Costumer->status == "stillcalling") {
        answer_list.InsertFront(Costumer); 
        answer_list.InsertFront(next_Costumer); 
      } 
      else{
        answer_list.InsertFront(next_Costumer); 
        answer_list.InsertFront(Costumer); 
      }  
    } 
    else {
    
      if ( Costumer->tick == 1 && Costumer->status != "stillcalling") {
        std::cout << "Answering call from " << Costumer->name<<"\n";
        delete Costumer;
      }
      if ( Costumer->tick == 1 && Costumer->status == "stillcalling" )
        delete Costumer;
      if (Costumer->tick > 1 && Costumer->status == "stillcalling") {
        Costumer->tick = Costumer->tick -1;
        answer_list.InsertFront(Costumer);
      }
      else {
        std::cout << "Answering call from " << Costumer->name <<"\n"; 
        Costumer->tick = Costumer->tick -1; 
        Costumer->status = "stillcalling";
        answer_list.InsertFront(Costumer);
      }
    } 

}
void Test (int rem_tick,Dlist<Costumer*> &Costumer_list,Dlist<Costumer*> &answer_list) {
  for (int i = 0; i <= rem_tick; i++) {
    std::cout<< "Starting tick #" <<i << std::endl;
    KeepTime(i,Costumer_list);
    Answer(i,answer_list); 
  }
}
#include <iostream>
#include <string>
#include "dlist.h"

struct Costumer {
  int time_stamp;
  std::string name;
  std::string status;
  int tick;
};
void CostumersData (int &, int , Dlist<Costumer*> &);
void KeepTime(int , Dlist<Costumer*> &);
void Add (Costumer* , Dlist<Costumer*> &);
void List(int , Dlist<Costumer*> , Dlist<Costumer*> &);
void Answer(int , Dlist<Costumer*> &);
void Test (int ,Dlist<Costumer*> &,Dlist<Costumer*> &);

int main() {
  Dlist<Costumer*> call_list;
  Dlist<Costumer*> answer_list;
  int Costumer_tick = 0;
  int event_number;
  std::cin >> event_number;
  CostumersData(Costumer_tick,event_number,call_list); 
  List(event_number,call_list, answer_list);
  Test(Costumer_tick, call_list, answer_list);
}
void CostumersData (int &Costumer_tick, int event_number, Dlist<Costumer*> &Costumer_list) {
  for (int i = 0; i < event_number; i++) {

    Costumer* new_Costumer = new Costumer;
    std::cin >> new_Costumer->time_stamp >> new_Costumer->name >> new_Costumer->status >> new_Costumer->tick;
    Costumer_list.InsertBack(new_Costumer); 

    if (Costumer_tick == new_Costumer->time_stamp) 
      Costumer_tick = Costumer_tick + new_Costumer->tick;

    if (Costumer_tick < new_Costumer->time_stamp)
      Costumer_tick = new_Costumer->time_stamp + new_Costumer->tick;

    else 
      Costumer_tick += new_Costumer->tick;

  }
}
void KeepTime(int current, Dlist<Costumer*> &Costumer_list) {
  
  Costumer* Costumer = Costumer_list.RemoveFront();
  
  while (Costumer->time_stamp == current) {
    
    if (Costumer->status == "none") 
      std::cout<<"Call from "<<Costumer->name<<" a regular member\n"; 
    else 
      std::cout<<"Call from "<<Costumer->name<<" a "<<Costumer->status<<" member\n"; 
    
    Costumer = Costumer_list.RemoveFront();
  }
  Costumer_list.InsertFront(Costumer);
}
void Add (Costumer* current, Dlist<Costumer*> &answer_list) {
  Costumer* new_Costumer = new Costumer;
  new_Costumer->time_stamp = current->time_stamp;
  new_Costumer->name = current->name;
  new_Costumer->status = current->status;
  new_Costumer->tick = current->tick;
  answer_list.InsertBack(new_Costumer);
}
void List(int event_number, Dlist<Costumer*> Costumer_list, Dlist<Costumer*> &answer_list) {
  int temp = event_number;
  
  for  ( int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "platium" ) {
      Add(current,answer_list);
      temp--;
    } else {
      Costumer_list.InsertBack(current);
    }
  }
  event_number = temp;
  for (int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "gold" ) {
      Add(current,answer_list);
      temp--;
    }
    else 
      Costumer_list.InsertBack(current);
  }

  event_number = temp;
  for (int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "silver" ) {
      Add(current,answer_list);
      temp--;
    } else {
      Costumer_list.InsertBack(current);
    }
  }
  //REGULAR MEMBERS
  event_number = temp;
  for (int i = 0 ; i < event_number; i++) {
    Costumer* current = Costumer_list.RemoveFront();
    if ( current->status == "none" ) {
      Add(current,answer_list);
      temp--;
    } else 
        Costumer_list.InsertBack(current);
    
  }
}
void Answer(int current, Dlist<Costumer*> &answer_list) {

  Costumer* Costumer = answer_list.RemoveFront();
    if (Costumer->time_stamp > current) {
      Answer(current, answer_list);
      
      Costumer* next_Costumer = answer_list.RemoveFront();
      if (next_Costumer->status == "stillcalling") {
        answer_list.InsertFront(Costumer); 
        answer_list.InsertFront(next_Costumer); 
      } 
      else{
        answer_list.InsertFront(next_Costumer); 
        answer_list.InsertFront(Costumer); 
      }  
    } 
    else {
    
      if ( Costumer->tick == 1 && Costumer->status != "stillcalling") {
        std::cout << "Answering call from " << Costumer->name<<"\n";
        delete Costumer;
      }
      if ( Costumer->tick == 1 && Costumer->status == "stillcalling" )
        delete Costumer;
      if (Costumer->tick > 1 && Costumer->status == "stillcalling") {
        Costumer->tick = Costumer->tick -1;
        answer_list.InsertFront(Costumer);
      }
      else {
        std::cout << "Answering call from " << Costumer->name <<"\n"; 
        Costumer->tick = Costumer->tick -1; 
        Costumer->status = "stillcalling";
        answer_list.InsertFront(Costumer);
      }
    } 

}
void Test (int rem_tick,Dlist<Costumer*> &Costumer_list,Dlist<Costumer*> &answer_list) {
  for (int i = 0; i <= rem_tick; i++) {
    std::cout<< "Starting tick #" <<i << std::endl;
    KeepTime(i,Costumer_list);
    Answer(i,answer_list); 
  }
}
#include <iostream>
#include <string>
#include "dlist.h"

struct Caller {
  int time_stamp;
  std::string name;
  std::string status;
  int duration;
};
// IMPLEMENT FUNCTION GETCALLERINFOR
void GetCallersInfor (int &total_tick, int event_number, Dlist<Caller*> &caller_list) {
   for (int i = 0; i < event_number; i++) {
    Caller* new_caller = new Caller;
    std::cin >> new_caller->time_stamp >> new_caller->name >> new_caller->status >> new_caller->duration;
    caller_list.InsertBack(new_caller); 
    //calculate total_tick;
    if (total_tick == new_caller->time_stamp) {
      total_tick = total_tick + new_caller->duration;
    } else if (total_tick < new_caller->time_stamp){
      total_tick = new_caller->time_stamp + new_caller->duration ;
    } else {
      total_tick += new_caller->duration;
    }
  }
}
// IMPLEMENT CallerAtCurrentTime
void CallerAtCurrentTime(int curr_tick, Dlist<Caller*> &caller_list) {
  try {
    Caller* caller = caller_list.RemoveFront();
  while (caller->time_stamp == curr_tick) {
    if (caller->status == "none") {
      std::cout<<"Call from "<<caller->name<<" a regular member\n"; 
    } else {
      std::cout<<"Call from "<<caller->name<<" a "<<caller->status<<" member\n"; 
    }
    caller = caller_list.RemoveFront();
  }
  caller_list.InsertFront(caller);
  }
  catch (emptyList) {
  }
}
//
void AddCallerToAnwerList (Caller* curr, Dlist<Caller*> &answer_list) {
  Caller* new_caller = new Caller;
  new_caller->time_stamp = curr->time_stamp;
  new_caller->name = curr->name;
  new_caller->status = curr->status;
  new_caller->duration = curr->duration;
  answer_list.InsertBack(new_caller);
}
// FUNCTION TO MAKE A LIST OF CALLER TO CALL BACK IN ORDER
void MakeAnswerList(int event_number, Dlist<Caller*> caller_list, Dlist<Caller*> &answer_list) {
  int ev = event_number;
  //PLATIUM MEMBERS
  for  ( int i = 0 ; i < event_number; i++) {
    Caller* curr = caller_list.RemoveFront();
    if ( curr->status == "platium" ) {
      AddCallerToAnwerList(curr,answer_list);
      ev--;
    } else {
      caller_list.InsertBack(curr);
    }
  }
  //GOLD MEMBERS
  event_number = ev;
  for (int i = 0 ; i < event_number; i++) {
    Caller* curr = caller_list.RemoveFront();
    if ( curr->status == "gold" ) {
      AddCallerToAnwerList(curr,answer_list);
      ev--;
    } else {
      caller_list.InsertBack(curr);
    }
  }
  //SILVER MEMBERS
  event_number = ev;
  for (int i = 0 ; i < event_number; i++) {
    Caller* curr = caller_list.RemoveFront();
    if ( curr->status == "silver" ) {
      AddCallerToAnwerList(curr,answer_list);
      ev--;
    } else {
      caller_list.InsertBack(curr);
    }
  }
  //REGULAR MEMBERS
  event_number = ev;
  for (int i = 0 ; i < event_number; i++) {
    Caller* curr = caller_list.RemoveFront();
    if ( curr->status == "none" ) {
      AddCallerToAnwerList(curr,answer_list);
      ev--;
    } else {
      caller_list.InsertBack(curr);
    }
  }
}

//FUNCTION TO INPUT CURRENT CALLS 
void CurrAnswer(int curr_tick, Dlist<Caller*> &answer_list) {
  try {
    Caller* caller = answer_list.RemoveFront();
    if (caller->time_stamp > curr_tick) {
      CurrAnswer(curr_tick, answer_list);
      try {
        Caller* next_caller = answer_list.RemoveFront();
        if (next_caller->status == "stillcalling") {
          answer_list.InsertFront(caller); 
          answer_list.InsertFront(next_caller); 
        } else {
          answer_list.InsertFront(next_caller); 
          answer_list.InsertFront(caller); 
        }
      }
      catch (emptyList){
        answer_list.InsertFront(caller); 
      }  
    } else {
      if ( caller->duration == 1 && caller->status != "stillcalling") {
        std::cout << "Answering call from " << caller->name<<"\n";
        delete caller;
      } else if ( caller->duration == 1 && caller->status == "stillcalling" ) {
        delete caller;
      } else if (caller->duration > 1 && caller->status == "stillcalling") {
        caller->duration = caller->duration -1;
        answer_list.InsertFront(caller);
      } else {
        std::cout << "Answering call from " << caller->name <<"\n"; 
        caller->duration = caller->duration -1; 
        caller->status = "stillcalling";
        answer_list.InsertFront(caller);
      }
    } 
  }
  catch (emptyList) {
  }
}
//// IMPLEMENT RunSimulator
void RunSimulator (int rem_tick,Dlist<Caller*> &caller_list,Dlist<Caller*> &answer_list) {
  for (int i = 0; i <= rem_tick; i++) {
    std::cout<< "Starting tick #" <<i <<"\n";
    CallerAtCurrentTime(i,caller_list);
    CurrAnswer(i,answer_list); 
  }
}
int main() {
  Dlist<Caller*> call_list;
  Dlist<Caller*> answer_list;
  int total_tick = 0;
  //get event information
  int event_number;
  std::cin >> event_number;
  //TEST THE CALL SIMULATOR
  GetCallersInfor(total_tick,event_number,call_list); 
  MakeAnswerList(event_number,call_list, answer_list);
  RunSimulator(total_tick, call_list, answer_list);
}
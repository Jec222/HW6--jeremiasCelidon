
#include <iostream>
#include <string>
#include "dlist.h"
#include ""

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
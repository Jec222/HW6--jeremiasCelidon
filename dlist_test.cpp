#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
  string name;
  string uniqname;
  Job job;
};

int main() {
  Dlist<Record*> catsweb1; 
  //CREATE RECORD 1
  Record* p1 = new Record;
  p1->name = "Andrew1 DeOrio";
  p1->uniqname = "awdeorio1";
  p1->job = FACULTY;
 //CREATE RECORD 2

  catsweb1.InsertFront(p1);
 
  //testing Copy-constructor
  while ( !catsweb1.IsEmpty() ) {
    Record *r = catsweb1.RemoveFront();
    cout << r->uniqname << endl;
    delete r;
  }
  return 0;
}
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

  Record* p1 = new Record;
  p1->name = "Jeremias";
  p1->uniqname = "testing";
  p1->job = FACULTY;

  catsweb1.InsertFront(p1);
 
  while ( !catsweb1.IsEmpty() ) {
    Record *r = catsweb1.RemoveFront();
    cout << r->uniqname << endl;
    delete r;
  }
  return 0;
}
#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:

  // Operational methods

  bool IsEmpty() const;//done
  // EFFECTS: returns true if list is empty, false otherwise

  void InsertFront(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the front of the list
    
  void InsertBack(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the back of the list

  T RemoveFront();
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
  //         throws an instance of emptyList if empty

  T RemoveBack();
  // MODIFIES this
  // EFFECTS removes and returns last object from non-empty list
  //         throws an instance of emptyList if empty

  // Maintenance methods
  Dlist();                                   // ctor
  Dlist(const Dlist &l);                     // copy ctor
  Dlist &operator=(const Dlist &l);          // assignment
  ~Dlist();                                  // dtor

 private:
  // A private type
  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  node   *first; // The pointer to the first node (0 if none)
  node   *last;  // The pointer to the last node (0 if none)
  //How us this different than the doubly linked list in class?

  // Utility methods

  void MakeEmpty();
  // EFFECT: called by constructors to establish empty
  // list invariant
    
  void RemoveAll();
  // EFFECT: called by destructor and operator= to remove and destroy
  // all list nodes

  void CopyAll(const Dlist &l);
  // EFFECT: called by copy constructor/operator= to copy nodes
  // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/
 /*PSEUDOCODE
 IsEmpty()
  if null first is not null return 1
  else return 0 

InsertFront(const T &o)
  create a pointer to a new node 
  set new pointer data to o

  if first equals nullptr
    set last and first to temp

  else
    make first prev equal to temp
    make temp next  equal to first 
    make first equal to temp

InsertBack(const T &o)
  create a re node that will be added to the back
  set temp node data to o from the parameter 

  if last is equal to nullptr
    set first and last to temp 

  else
    make temp new last 
    make temp prev equal to last 
    make last equal to temp

RemoveFront()
  if list is not empty
    set a temp node equal to first
    set value being delited to delValue of data type T

  if first and last are the same 
     make last and first equal to nullptr

  else
    set first to its next node value 
    set first prev equal to nullptr

  delete temp;
  return delValue;

RemoveBack()
 if list is not empty
    set a temp node equal to last 
    set a delValue to be equal the last o value
    
    if first and last are the same 
      make last and first equal to nullptr
    
    else
      set last equal to last prev value
      set last next equal to nullptr
    
    delete temp; 
    return delValue;


Dlist()
  call MakeEmpty function to make an empty list

Dlist(const Dlist &l)
  call CopyAll to set equal to l
 
operator= (const Dlist &l)

  if the curent list equal to l
    return the the curent list 

  else
    call RemoveAll and CopyAll and return curent list

~Dlist()
  call RemoveAll method to delete all nodes in the list
MakeEmpty()
  set first and last equal to nullptr

RemoveAll()

  make temp equal to first 

  while not the end of the list 
    set first to the next node in the list 
    delete temp
    make temp equal to first 

  set first equal to nullptr
    
CopyAll(const Dlist &l)

  if list l is empy
   make curent list empty

  else
    create new node called temp set equal to fist none from l

    while the list is not empty 
      set nodes from l equal to l by calling InsertBack
      set temp equal to temp next
 */
template <typename T>
bool Dlist<T>::IsEmpty() const{
   return !first?1:0;
}
template <typename T>
void Dlist<T>::InsertFront(const T &o){
   node* temp = new node;
   temp -> o = o;

  if (first == nullptr) {
    first = last = temp;
  }
  else{
    first -> prev = temp;
    temp -> next = first;
    first = temp; 
  }
}
template <typename T>
void Dlist<T>::InsertBack(const T &o){

  node* temp = new node;
  temp -> o = o;

  if (last == nullptr){
    first = last = temp;
  }

  else{
    last->next = temp;
    temp->prev = last;
    last = temp;
  }
}
template <typename T>
T Dlist<T>::RemoveFront(){

  if (!IsEmpty()){
    node* temp = first;
    T delValue = temp -> o;

    if(first == last){
      last = nullptr;
      first = nullptr;
    }
    else {
      first = first -> next;
      first -> prev = nullptr;

    }
    delete temp;
    return delValue;
  }
}
template <typename T>
T Dlist<T>::RemoveBack(){
  if (!IsEmpty()){
    node* temp = last;
    T delValue = temp-> o;

    if (first == last){
      first = nullptr;
      last = nullptr;
    }
    else {
      last = last -> prev;
      last -> next = nullptr;
    }
    delete temp; 
    return delValue;
  }
}
template <typename T>
Dlist<T>::Dlist(){
  MakeEmpty();
}       
template <typename T>                 
Dlist<T>::Dlist(const Dlist &l){
  CopyAll(l);
} 
template <typename T>     
Dlist<T>& Dlist<T>::operator= (const Dlist &l){      
  
  if (this == &l) 
    return *this;

  RemoveAll();
  CopyAll(l); 
  return *this;
} 
template <typename T>        
Dlist<T>::~Dlist(){
  RemoveAll();
}
template <typename T>
void Dlist<T>::MakeEmpty(){
  first = last = nullptr;
}
template <typename T>
void Dlist<T>::RemoveAll(){

  node *temp = first;
  while (temp != nullptr) {
    first = first -> next;
    delete temp;
    temp = first;
  }
  first = nullptr;
}
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l){

  if (l.first == nullptr) {
    first = last = nullptr;
  } 
  else {
    node* temp = l.first;
    while (temp) {
      InsertBack(temp->o);
      temp = temp->next;
    }
  }
}


/* this must be at the end of the file */
#endif /* __DLIST_H__ */

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
template <typename T>
bool Dlist<T>::IsEmpty() const{
   return (first == NULL && last == NULL);
}
template <typename T>
void Dlist<T>::InsertFront(const T &o){
   // if list is empty
  if (first == NULL && last == NULL) {
    first = new node;
    first -> o = 0;
    first -> next = first -> prev = NULL;
    last = first;
    return;
  }
  // else
  else{
    node *newNode = new node;
    newNode -> o = o;
    newNode -> prev = NULL;
    newNode -> next = first;
    first -> prev = newNode;
    first = newNode;
  }
}
template <typename T>
void Dlist<T>::InsertBack(const T &o){

  if (first == NULL && last == NULL){
    first = new node;
    first -> o = 0;
    first -> next = first -> prev = NULL;
    last = first;
    return;
  }

  else{
    node *newNode = new node;
    newNode -> o = o;
    newNode -> next = NULL;
    newNode -> prev = last;
    last -> next = newNode;
    last = newNode;
  }
}
template <typename T>
T Dlist<T>::RemoveFront(){

  if (first == NULL)
    MakeEmpty();

  if (first == last) {
    RemoveAll();
    MakeEmpty();
    //return;
  }
  else{
    node *temp = first;
    first = first -> next;
    first -> prev = NULL;
    temp -> next = NULL;
    delete temp;
  }
}
template <typename T>
T Dlist<T>::RemoveBack(){
  if (last == NULL)
    MakeEmpty();

  if (first == last){
    RemoveAll();
    MakeEmpty();
    return;
  }
  else{
    node *temp = last;
    last = last -> prev;
    last -> next = NULL;
    temp -> prev = NULL;
    delete temp;
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
//Dlist&<T>::Dlist operator=(const Dlist &l){
  RemoveAll();
  CopyAll(l);
  return this;  
} 
template <typename T>        
Dlist<T>::~Dlist(){
  RemoveAll();
}
template <typename T>
void Dlist<T>::MakeEmpty(){
  first = last = NULL;
}
template <typename T>
void Dlist<T>::RemoveAll(){
  while (first) {
    node *temp = first;
    first = first->next;
    temp->next = NULL;
    delete temp;
  }
}
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l){
  first = l.first;
  delete l.first;
}


/* this must be at the end of the file */
#endif /* __DLIST_H__ */

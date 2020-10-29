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
   return (first == nullptr && last == nullptr);
}
template <typename T>
void Dlist<T>::InsertFront(const T &o){
   // if list is empty
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
  first = last = nullptr;
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
  while (temp! = nullptr) {
    first = first -> next;
    delete temp;
    temp = first;
  }
  first = nullptr;
}
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l){
  first = l.first;
  delete l.first;
}


/* this must be at the end of the file */
#endif /* __DLIST_H__ */

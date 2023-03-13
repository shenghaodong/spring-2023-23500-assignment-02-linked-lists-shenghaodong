#include <iostream>
#include "Node.h"
#include "OList.h"

List::OList(){
  head = nullptr;
}

List::~OList(){
  std::cerr << "Calling the destructor\n";
  Node *walker = head;
  Node *trailer = nullptr;
  while (walker != nullptr){
    trailer=  walker;
    walker = walker->getNext();
    std::cerr << "Deleting " << trailer->getData() << ", ";
    delete trailer;
  }
  std::cerr << "\n";
  
  
}

// insert at the "front" (head)
void OList::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

void OList::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();
    
  }

std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

bool OList::contains(std::string value)
  Node *walker = head;
  while (walker != nullptr && walker->getData() != value){
    walker = walker->getNext();
  }
  if (walker == nullptr){
    return false;
  } else {
    return true;
  }

}
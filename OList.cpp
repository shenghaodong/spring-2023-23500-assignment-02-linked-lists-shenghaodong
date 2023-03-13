#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
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

int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
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

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end 
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case 
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
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

std::string OList::get(int loc){
  Node *walker = head;
  int count = 0;
  while (walker != nullptr && count < loc){
    walker = walker->getNext();
    count++;
  }
  if (walker == nullptr){
    return "nullptr";
  } else {
    return walker->getData();
  }
}

bool OList::contains(std::string value){
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

void OList::remove(int loc){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;
    trailer=walker;
    walker = walker->getNext();
  }

  if (walker == nullptr){
    throw std::out_of_range("Tried to remove out of range");
  }

  if (trailer == nullptr){
    // we're removing the first item in the list
    head = walker->getNext();
    delete walker;
  } else {
    // general case of having a node before the
    // node to delete
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

void OList::reverse(){
  //Test this last because it'll break everything
  Node *walker, *trailer;
  walker = this->head; //Current
  trailer = nullptr; //Prev
  while(walker != nullptr){
    Node *next = walker->getNext();
    walker->setNext(trailer);
    trailer = walker;
    walker = next;
  }
  head = trailer;
}
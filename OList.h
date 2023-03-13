#pragma once
#include <iostream>
#include "Node.h"

class OList{
 private:
    Node *head;
 public:
    OList();
    ~OList();
    void insert(std::string data);
    void insert(int loc, std::string data);
    std::string toString();
    bool contains(std::string value);
    get(int loc);
    void remove(int loc);
    void reverse();


//   std::string toString(); // for testing purposes
//   void remove(int loc);
};


/*
A constructor
A destructor
void insert(value) - insert a new node with value into the list in its proper location.
std::string toString() - return a string representation of the full list.
bool contains(value) - returns true if value is in the list, false otherwise.
get(loc) - returns the value at loc
void remove(loc) - returns the value at loc
void reverse() - This should “reverse” the list - that is reverse the pointers
*/
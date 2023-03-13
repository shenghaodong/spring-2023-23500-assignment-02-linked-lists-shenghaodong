#include <iostream>
#include "OList.h"
#include "lists.h"

int main(){
    OList *l = new OList();
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(0,"a");
    std::cout << l->toString() << " " << l->length() << "\n";
    l->insert(1,"b");
    l->insert(2,"c");
    l->insert(3,"d");
    l->insert(4,"e");
    l->insert(5,"f");
    l->insert(6,"g");
    l->insert(7,"h");
    std::cout << l->toString() << " " << l->length() << "\n";
    l->reverse();
    std::cout << l->toString() << " " << l->length() << "\n";

    return 0;
}
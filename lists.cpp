int List::length(){
    int count = 0;
    Node *walker = head;
    while(walker != nullptr){
        count++;
        walker = walker -> getNext();
    }
}


std::string List::find(std::string data){
    Node *walker = head;
    While (walker != nullptr && walker -> getData() != data){
        walker = walker -> getNext();
    }
    if (walker == nullptr){
        return "";
    }else{
        return walker -> getData();
    }
}

std::string List::toString(){
    Node *tmp = this -> head;
    std::string result = "";
    while(tmp != nullptr){
        result = result + tmp -> getData();
        result = result + "-->";
        tmp = tmp -> getNext();
    }
    result = result  + "nullptr";
}

//do remove based on a value on assignment
void List::remove(int loc){
    Node *walker, *trailer;
    walker = this -> head;
    trailer = nullptr;
    
    while(loc > 0 && walker != nullptr){
        loc = loc -1;
        trailer = walker;
        walker = walker -> getNext();
    }

    if(walker == nullptr){
        throw std::out_of_range("Tried to remove out of range");
    }
    if (trailer == nullptr){
        //We're removing the first itme in the list
        head = walker -> getNext();
        delete walker;
    }else{
        trailer -> setNext(walker -> getNext());
        delete walker;
    }

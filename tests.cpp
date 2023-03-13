#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lists.h"
#include "Olist.h"
#include "node.h"
/*
    OList();
    ~OList();
    void insert(std::string data);
    void insert(int loc, std::string data);
    int length();
    std::string toString();
    bool contains(std::string value);
    std::string get(int loc);
    void remove(int loc);
    void reverse();


*/
// Tests
TEST_CASE("OList"){
    OList *l = new OList();
    l->insert(0,"a");
    l->insert(1,"b");
    l->insert(2,"c");
    l->insert(3,"d");
    l->insert(4,"e");
    l->insert(5,"f");
    l->insert(6,"g");
    l->insert(7,"h");
    CHECK(l->length() == 8);
    CHECK(l->toString()== "a-->b-->c-->d-->e-->f-->g-->h-->nullptr");
    CHECK(l->contains("d") == true);
}

TEST_CASE("OList 2"){
    OList *l = new OList();
    l->insert(0,"a");
    l->insert(1,"b");
    l->insert(2,"c");
    l->insert(3,"d");
    l->insert(4,"e");
    l->insert(5,"f");
    l->insert(6,"g");
    l->insert(7,"h");
    l->remove(3);
    CHECK(l->contains("d") == false);
    l->reverse();
    CHECK(l->toString()== "h-->g-->f-->e-->c-->b-->a-->nullptr");
}

TEST_CASE("OList 3"){
    OList *l = new OList();
    l->insert(0,"a");
    l->insert(1,"b");
    l->insert(2,"c");
    l->insert(3,"d");
    l->insert(4,"e");
    l->insert(5,"f");
    l->insert(6,"g");
    l->insert(7,"h");
    CHECK(l->get(3) == "d");
    CHECK(l->get(0) == "a");
}

#pragma once
#include <iostream>
#include "Node.h"

class List{
private:
    Node *head;

public:
    List();
    ~List();

    void insert(std::string data);
    void insert(int loc, std::string data);
    bool contains(std::string item);
    bool remove(int loc);
    int length();

    std::string toString();
};
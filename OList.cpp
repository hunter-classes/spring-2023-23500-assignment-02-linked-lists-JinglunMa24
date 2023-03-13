#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList() {
    head = nullptr;
}

OList::~OList() {
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


void OList::insert(std::string data) {
    Node *newNode = new Node(data);
    if(head == nullptr) {
        head = newNode;
    }
    else {
        Node *trailer, *walker;
        walker = head;
        trailer = nullptr;

        while (walker != nullptr && std::stoi(walker->getData()) < std::stoi(newNode->getData())) {
            trailer = walker;
            walker = walker->getNext();
        }

        if(trailer == nullptr) {
            newNode->setNext(head);
            head = newNode;
        }
        else {
            trailer->setNext(newNode);
            newNode->setNext(walker);
        }

    }
}

void OList::reverse() {
    Node *walker, *trailer, *tmp;
    tmp = nullptr;
    trailer = nullptr;
    walker = head;
    while (walker != nullptr) {
        tmp = walker->getNext();
        walker->setNext(trailer);
        trailer = walker;
        walker = tmp;
    }
    head = trailer;
}

std::string OList::get(int loc) {
    Node *walker = head;
    while (walker != nullptr && loc > 0) {
        loc = loc - 1;
        walker = walker->getNext();
    }

    if (walker == nullptr) {
        return "Nullptr, out of range";
    }
    else {
        return walker->getData();
    }
}

bool OList::contains(std::string value) {
    Node *walker = head;

    while (walker != nullptr) {
        if (walker->getData() == value) {
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

bool OList::remove(int loc) {
    Node *walker = head;
    Node *trailer = nullptr;

    while (loc > 0 && walker != nullptr) {
        loc = loc - 1;
        trailer = walker;
        walker = walker->getNext();
    }

    if (walker == nullptr) {
        throw std::out_of_range("Insert is out of range");
    }

    if (trailer == nullptr) {
        head = walker->getNext();
        delete walker;
        return true;
    }
    else {
        trailer->setNext(walker->getNext());
        delete walker;
        return true;
    }
    return false;
}

int OList::length() {
    int count = 0;
    Node *walker = head;
    while (walker != nullptr) {
        count++;
        walker = walker->getNext();
    }
    return count;
}

std::string OList::toString() {
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr) {
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}
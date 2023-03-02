#include <iostream>
#include "List.h"

int main() {
    List *l = new List();

    l->insert(0,"a");
    l->insert(0,"b");
    l->insert(0,"c");
    l->insert(0,"d");

    try {
        l->insert(10,"x");
    }
    catch (std::exception e){
        std::cout << "Insert x didn't work\n";
    }

    l->insert(2,"inserted at 2");
    //std::cout << l->toString() << "\n";
    l->insert(5,"inserted at end");
    std::cout << l->toString() << " " << l->length() << "\n";
    std::cout << "Did it contain b?" << "\n" << l->contains("b") << "\n";
    std::cout << "Did it contain v?" << "\n" << l->contains("v") << "\n";

    l->remove(0);
    std::cout << l->toString() << " " << l->length() << "\n";
    l->remove(2);
    std::cout << l->toString() << " " << l->length() << "\n";
    return 0;

}
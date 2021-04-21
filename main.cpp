#include <iostream>
#include "exception/IndexOutOfBoundsException.h"
#include "collection/List.h"
#include "collection/ArrayList.h"
#include "collection/LinkedList.h"

template<typename T>
void printSize(List<T> *list) {
    std::cout << "Size = " << (*list).size() << std::endl;
}

template<typename T>
void printAll(List<T> *list) {
    for (int i = 0; i < (*list).size(); i++) {
        std::cout << (*list).get(i) << std::endl;
    }
}

void testArrayList() {
    List<int> *arrayList = new ArrayList<int>();
    (*arrayList).add(1);
    (*arrayList).add(2);
    (*arrayList).add(3);
    (*arrayList).add(4);
    (*arrayList).add(5);
    printAll(arrayList);
    printSize(arrayList);
    (*arrayList).remove(2);
    printAll(arrayList);
    printSize(arrayList);
    try {
        (*arrayList).get(-1);
    } catch (IndexOutOfBoundsException &e) {
        e.printMessage();
    }
}

void testLinkedList() {
    List<int> *linkedList = new LinkedList<int>();
    (*linkedList).add(1);
    (*linkedList).add(2);
    (*linkedList).add(3);
    (*linkedList).add(4);
    (*linkedList).add(5);
    printAll(linkedList);
    printSize(linkedList);
    (*linkedList).remove(4);
    printAll(linkedList);
    printSize(linkedList);
    try {
        (*linkedList).get(-1);
    } catch (IndexOutOfBoundsException &e) {
        e.printMessage();
        throw e;
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    try{
        testArrayList();
        testLinkedList();
    } catch (...) {
        std::cout<<"Oops..."<<std::endl;
    }
    return 0;
}

#include <iostream>
#include "exception/IndexOutOfBoundsException.h"
#include "collection/List.h"
#include "collection/ArrayList.h"
#include "collection/LinkedList.h"
#include "collection/TreeSet.h"
#include <fstream>

template<typename T>
void printSize(List<T> *list) {
    std::cout << "Size = " << (*list).size() << std::endl;
}

template<typename T>
void printAll(List<T> *list) {
    for (int i = 0; i < (*list).size(); i++) {
        std::cout << (*list).get(i) << " ";
    }
    std::cout << std::endl;
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
    arrayList->set(3, 7);
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
    linkedList->set(4, 7);
    linkedList->add(8);
    printAll(linkedList);
    printSize(linkedList);
    try {
        (*linkedList).get(-1);
    } catch (IndexOutOfBoundsException &e) {
        e.printMessage();
        throw e;
    }
}

void testTreeMap() {
    TreeSet<int> treeMap;
    treeMap.add(5);
    treeMap.add(10);
    treeMap.add(1);
    treeMap.add(3);
    std::cout << treeMap.find(10) << std::endl;
}

void bubbleSort(List<int> *list) {
    int n = list->size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            int curr = list->get(j);
            int next = list->get(j + 1);
            if (curr > next) {
                list->set(j, next);
                list->set(j + 1, curr);
                swapped = true;
            }
        }
        // IF no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

void testBubbleSort() {
    List<int> *list = new LinkedList<int>();
    for (int i = 0; i < 10; i++) {
        int next = rand() % 100;
        list->add(next);
    }
    std::cout<<"Before: ";
    printAll(list);
    bubbleSort(list);
    std::cout<<"After: ";
    printAll(list);
}

void writeToFile(List<int> * list, const std::string& path){
    std::ofstream my_file;
    my_file.open(path, std::ios::in);
    if (!my_file.is_open()) {
        std::cout << "No such file";
    }
    else {
        for(int i = 0; i < list->size(); i++){
            my_file << std::to_string(list->get(i)) << std::endl;
        }
    }
    my_file.close();
}

List<int>* readFromFile(const std::string& path){
    List<int> *out = new ArrayList<int>();
    std::ifstream my_file;
    my_file.open(path, std::ios::in);
    if (!my_file.is_open()) {
        std::cout << "No such file";
    }
    else {
        for(std::string line; getline( my_file, line ); ){
            out->add(std::stoi(line));
        }
    }
    my_file.close();
    return out;
}

void testReadFromFile() {
    List<int>* list = readFromFile("C:\\Users\\владислав\\CLionProjects\\list\\list_input.txt");
    printAll(list);
}

void testWriteToFile(){
    List<int>* list = readFromFile("C:\\Users\\владислав\\CLionProjects\\list\\list_input.txt");
    writeToFile(list, "C:\\Users\\владислав\\CLionProjects\\list\\list_output.txt");
}

int main() {

    try {
//        testArrayList();
//        testLinkedList();
//        testTreeMap();
//        testBubbleSort();
    testWriteToFile();
    } catch (...) {
        std::cout << "Oops..." << std::endl;
    }

    return 0;
}

//
// Created by владислав on 21.04.2021.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
#include "../exception/IndexOutOfBoundsException.h"

template<class T>
class List {

public:

    virtual void add(T t) = 0;

    virtual void set(int index, T t) = 0;

    virtual T get(int index) = 0;

    virtual void remove(int index) = 0;

    int size(){
        return length;
    }

    bool isEmpty(){
        return length == 0;
    }
protected:

    int length = 0;

    void checkIndex(int index) {
        if(index < 0 || index >= size()){
            throw IndexOutOfBoundsException("Index must be between 0 (incl.) and size (not incl)");
        }
    }

};


#endif //LIST_LIST_H

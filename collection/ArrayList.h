//
// Created by владислав on 21.04.2021.
//

#ifndef LIST_ARRAYLIST_H
#define LIST_ARRAYLIST_H
#include "List.h"
#include "../exception/IndexOutOfBoundsException.h"

template<class T>
class ArrayList : public List<T>{

private:
    T *elements = new T[0];


public:

    void add(T t) override;

    void remove(int index) override;

    T get(int index) override;

    void set(int index, T t) override;

};

template<class T> void ArrayList<T>::add(T t){
    T *neuArr = new T[this->length + 1];
    for (int i = 0; i < this->length; i++) {
        neuArr[i] = this->elements[i];
    }
    neuArr[this->length] = t;
    delete[] this->elements;
    this->elements = neuArr;
    this->length++;
}

template<class T>
void ArrayList<T>::set(int index, T t) {
    this->checkIndex(index);
    elements[index] = t;
}

template<class T> void ArrayList<T>::remove(int index) {
    this-> checkIndex(index);
    T *neuArr = new T[this->length - 1];
    for (int i = 0; i < index; i++) {
        neuArr[i] = this->elements[i];
    }
    for (int i = index + 1; i < this->length; i++) {
        neuArr[i - 1] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = neuArr;
    this->length--;
}

template<class T> T ArrayList<T>::get(int index) {
    this-> checkIndex(index);
    return this->elements[index];
}


#endif //LIST_ARRAYLIST_H

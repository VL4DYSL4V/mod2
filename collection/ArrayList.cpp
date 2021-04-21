//
// Created by владислав on 21.04.2021.
//

#include "ArrayList.h"

//template<class T> void ArrayList<T>::add(T t){
//    T *neuArr = new T[this->length + 1];
//    for (int i = 0; i < this->length; i++) {
//        neuArr[i] = this->elements[i];
//    }
//    neuArr[this->length] = t;
//    delete[] this->elements;
//    this->elements = neuArr;
//    this->length++;
//}
//
//template<class T> void ArrayList<T>::remove(int index) {
//    this-> checkIndex(index);
//    T *neuArr = new T[this->length - 1];
//    for (int i = 0; i < index; i++) {
//        neuArr[i] = this->elements[i];
//    }
//    for (int i = index + 1; i < this->length; i++) {
//        neuArr[i - 1] = this->elements[i];
//    }
//    delete[] this->elements;
//    this->elements = neuArr;
//    this->length--;
//}
//
//template<class T> T ArrayList<T>::get(int index) {
//    this-> checkIndex(index);
//    return this->elements[index];
//}

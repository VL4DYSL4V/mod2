//
// Created by владислав on 21.04.2021.
//

#ifndef LIST_LINKEDLIST_H
#define LIST_LINKEDLIST_H

#include "List.h"

template<class T>
class LinkedList : public List<T> {

private:
    class Node {

    private:
        Node *next = NULL;
        T value;
    public:
        Node() = default;

        Node(T value) {
            this->value = value;
        }

        Node *getNext() const {
            return next;
        }

        void setNext(Node *next) {
            Node::next = next;
        }

        T getValue() {
            return value;
        }
    };

    Node *head = NULL;
    Node *tail = NULL;

public:
    void add(T t) override;

    void remove(int index) override;

    T get(int index) override;

    void set(int index, T t) override;

};

template<class T>
void LinkedList<T>::add(T t) {
    Node *newNode = new Node(t);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    this->length++;
}

template<class T>
void LinkedList<T>::set(int index, T t) {
    this->checkIndex(index);
    Node *nodeBeforeInserted = head;
    Node * inserted = new Node(t);
    if (index == 0) {
        inserted->setNext(head->getNext());
        head = inserted;
    } else {
        for (int i = 0; i < index - 1; i++) {
            nodeBeforeInserted = nodeBeforeInserted->getNext();
        }
        Node *nodeToReplace = nodeBeforeInserted->getNext();
        inserted->setNext(nodeToReplace->getNext());
        nodeBeforeInserted->setNext(inserted);
        if(index == this->length - 1){
            tail = inserted;
        }
    }
}

template<class T>
void LinkedList<T>::remove(int index) {
    this->checkIndex(index);
    Node *nodeBeforeRemoved = head;
    if (index == 0) {
        head = head->getNext();
        delete nodeBeforeRemoved;
        if (this->length == 1) {
            tail = NULL;
        }
    } else {
        for (int i = 0; i < index - 1; i++) {
            nodeBeforeRemoved = nodeBeforeRemoved->getNext();
        }
        Node *nodeToRemove = nodeBeforeRemoved->getNext();
        if (nodeToRemove == tail) {
            tail = nodeBeforeRemoved;
        } else {
            Node *afterRemoved = nodeToRemove->getNext();
            nodeBeforeRemoved->setNext(afterRemoved);
        }
        delete nodeToRemove;
    }
    this->length--;
}


template<class T>
T LinkedList<T>::get(int index) {
    this->checkIndex(index);
    Node *next = head;
    for (int i = 0; i < index; i++) {
        next = next->getNext();
    }
    return next->getValue();
}


#endif //LIST_LINKEDLIST_H

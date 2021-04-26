//
// Created by владислав on 25.04.2021.
//

#ifndef LIST_TREEMAP_H
#define LIST_TREEMAP_H

#include <clocale>

template<class T>
class TreeMap {
private:

    class Node {
    private:
        T _value;
        Node *left;
        Node *right;

    public:
        Node(T value) {
            _value = value;
            left = NULL;
            right = NULL;
        }

        Node() : _value(NULL), left(NULL), right(NULL) {
        }

        void setLeft(Node *ptr) {
            left = ptr;
        }

        void setRight(Node *ptr) {
            right = ptr;
        }

        void setValue(T iValue) {
            _value = iValue;
        }

        T getValue() {
            return _value;
        }

        Node *getLeft() {
            return left;
        }

        Node *getRight() {
            return right;
        }
    };

private:
    Node *head;

public:

    TreeMap() : head(NULL) {
    }

    TreeMap(T value) {
        Node *node = new Node(value);
        head = node;
    }

    TreeMap(Node* node) {
        head = node;
    }

    bool add(Node *node, int value) {
        if (head == NULL) {
            Node * node = new Node(value);
            head = node;
            return true;
        }
        if (value >= node->getValue()) {
            if (node->getRight() != NULL)
                return add(node->getRight(), value);
            else {
                Node * newNode = new Node(value);
                node->setRight(newNode);
                return true;
            }
        } else {
            if (node->getLeft() != NULL)
                add(node->getLeft(), value);
            else {
                Node * newNode = new Node(value);
                node->setLeft(newNode);
                return true;
            }
        }
    }

    bool add(T value) {
        if (head == NULL) {
            Node * node = new Node(value);
            head = node;
            return true;
        }
        if (value >= head->getValue()) {
            if (head->getRight() != NULL)
                return add(head->getRight(), value);
            else {
                Node * newNode = new Node(value);
                head->setRight(newNode);
                return true;
            }
        } else {
            if (head->getLeft() != NULL)
                return add(head->getLeft(), value);
            else {
                Node * newNode = new Node(value);
                head->setLeft(newNode);
                return true;
            }
        }
    }

    bool find(T value, Node *node) {

        while (node != NULL) {
            if (value == node->getValue()) {
                return true;
            } else {
                if (value <= node->getValue()) {
                    return find(value, node->getLeft());
                } else {
                    return find(value, node->getRight());
                }
            }
        }
        return false;
    }

    bool find(T value) {
        while (head != NULL) {
            if (value == head->getValue()) {
                return true;
            } else {
                if (value <= head->getValue()) {
                    return find(value, head->getLeft());
                }
                else {
                    return find(value, head->getRight());
                }
            }
        }
        return false;
    }

};


#endif //LIST_TREEMAP_H

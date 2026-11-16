#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Cabel1.h"

class DoublyLinkedList {
private:
    struct Node {
        Cabel data;
        Node* prev;
        Node* next;

        Node(const Cabel& cabel);
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty() const;

    void pushFront(const Cabel& cabel);
    void pushBack(const Cabel& cabel);

    bool insertAfter(double impedance, const Cabel& cabel);

    void popFront();
    void popBack();

    bool removeByValue(double impedance);

    void displayForward() const;
    void displayBackward() const;

    void clear();
};

#endif

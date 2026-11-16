#include "dll1.h"
#include <iostream>

using namespace std;

DoublyLinkedList::Node::Node(const Cabel& cabel)
    : data(cabel), prev(nullptr), next(nullptr) {}

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

void DoublyLinkedList::pushFront(const Cabel& cabel) {
    Node* newNode = new Node(cabel);

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Кабель додано на початок списку.\n";
}

void DoublyLinkedList::pushBack(const Cabel& cabel) {
    Node* newNode = new Node(cabel);

    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Кабель додано в кінець списку.\n";
}

bool DoublyLinkedList::insertAfter(double impedance,
                                   const Cabel& cabel) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.getImpedance() == impedance) {
            Node* newNode = new Node(cabel);

            newNode->prev = current;
            newNode->next = current->next;

            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }

            current->next = newNode;

            cout << "Кабель успішно вставлено.\n";
            return true;
        }

        current = current->next;
    }

    cout << "Кабель із таким опором не знайдено.\n";
    return false;
}

void DoublyLinkedList::popFront() {
    if (isEmpty()) {
        cout << "Список порожній!\n";
        return;
    }

    Node* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    cout << "Перший елемент видалено.\n";
}

void DoublyLinkedList::popBack() {
    if (isEmpty()) {
        cout << "Список порожній!\n";
        return;
    }

    Node* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    cout << "Останній елемент видалено.\n";
}

bool DoublyLinkedList::removeByValue(double impedance) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.getImpedance() == impedance) {
            if (current == head) {
                popFront();
            }
            else if (current == tail) {
                popBack();
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                cout << "Кабель видалено зі списку.\n";
            }

            return true;
        }

        current = current->next;
    }

    cout << "Кабель не знайдено.\n";
    return false;
}

void DoublyLinkedList::displayForward() const {
    if (isEmpty()) {
        cout << "Список порожній!\n";
        return;
    }

    Node* current = head;

    cout << "\nПрямий вивід списку:\n";

    while (current != nullptr) {
        current->data.output();
        cout << "\n";
        current = current->next;
    }
}

void DoublyLinkedList::displayBackward() const {
    if (isEmpty()) {
        cout << "Список порожній!\n";
        return;
    }

    Node* current = tail;

    cout << "\nЗворотний вивід списку:\n";

    while (current != nullptr) {
        current->data.output();
        cout << "\n";
        current = current->prev;
    }
}

void DoublyLinkedList::clear() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = tail = nullptr;
}

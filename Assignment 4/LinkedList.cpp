#include "LinkedList.h"
#include<iostream>
using namespace std;
#include <unordered_map>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addNode(int value) {
    Node* newNode = new Node{ value, 1, nullptr };

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::removeNode(int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void LinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << "(" << current->value << ", " << current->occurrences << ") ";
        current = current->next;
    }
 
}

void LinkedList::createListFromVector(const std::vector<int>& vec) {
    unordered_map<int, int> occurrences;
    for (const int& value : vec) {
        occurrences[value]++;
    }

    for (const auto& entry : occurrences) {
        Node* newNode = new Node{ entry.first, entry.second, nullptr };

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

int LinkedList::sumOfNodes() const {
    int sum = 0;

    Node* current = head;
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
    }

    return sum;
}
#pragma once
#include <iostream>
#include <vector>

struct Node {
    int value;
    int occurrences;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void addNode(int value);
    void removeNode(int value);
    void printList() const;
    void createListFromVector(const std::vector<int>& vec);
    int sumOfNodes() const;

private:
    Node* head;
};


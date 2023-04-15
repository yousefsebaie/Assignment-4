#include <iostream>
using namespace std;
#include <vector>
#include "LinkedList.h"


void insertAfter(std::vector<int>& vec, int firstValue, int secondValue) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == firstValue) {
            vec.insert(vec.begin() + i + 1, secondValue);
            i++; // skip the inserted value
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    int firstValue, secondValue;
    cout << "Enter the first value: ";
    cin >> firstValue;
    cout << "Enter the second value: ";
    cin >> secondValue;

    insertAfter(vec, firstValue, secondValue);

    LinkedList list;
    list.createListFromVector(vec);
    list.printList();

    std::cout << "Sum of nodes: " << list.sumOfNodes() << std::endl;

    return 0;
}
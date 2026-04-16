#include <iostream>
using namespace std;

struct Node {
    string move;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void addMove(string move) {
    Node* node = new Node{move, nullptr, tail};
    if (tail) tail->next = node;
    else head = node;
    tail = node;
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        addMove(string(1, from) + " -> " + to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    addMove(string(1, from) + " -> " + to);
    hanoi(n - 1, aux, to, from);
}

void printList() {
    Node* cur = head;
    while (cur) {
        cout << cur->move << endl;
        cur = cur->next;
    }
}

void freeList() {
    Node* cur = head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'C', 'B');
    printList();
    freeList();
    return 0;
}

#include <bits/stdc++.h>
#define MAX 5
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *_insert(Node *node, int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(node == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = node;

    while(temp->next != node) temp = temp->next;

    temp->next = newNode;
    newNode->next = node;

    return node;
}

void traversal(Node *node) {
    if(node == NULL) return;

    Node *temp = node;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != node);

    cout << "(Kembali ke head)" << endl;
}

int main() {
    Node *node = NULL;

    int iter = MAX;

    while(iter--) {
        int num;

        cout << "Masukkan data: ";
        cin >> num;

        node = _insert(node, num);
    }

    cout << endl << "Visualisasi:" << endl;
    traversal(node);

    return 0;
}


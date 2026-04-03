#include <bits/stdc++.h>
using namespace std;

// struktur node
struct node {
    int data;
    node *next;
};

class stack_ {
private:
    node *top;

public:
    // konstruktor
    stack_() {
        top = NULL;
    }

    // push
    void push(int x) {
        node *new_node = new node();
        new_node->data = x;
        new_node->next = top;
        top = new_node;

        cout << x << " ditambahkan ke dalam stack\n";
    }

    // pop
    void pop() {
        if (top == NULL) {
            cout << "Stack underflow\n";
            return;
        }

        node *temp = top;
        cout << temp->data << " dihapus dari stack\n";
        top = top->next;
        delete temp;
    }

    // top/peek
    void peek() {
        if (top == NULL) cout << "Stack kosong\n";
        else cout << "Elemen teratas: " << top->data << endl;
    }

    // cek_kosong
    bool check_empty() {
        return (top == NULL);
    }
};

int main() {
    stack_ s;

    s.push(20);
    s.push(50);
    s.push(70);

    s.peek();

    s.pop();
    s.pop();
    s.peek();

    return 0;
}

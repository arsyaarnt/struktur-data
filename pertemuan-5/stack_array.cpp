#include <bits/stdc++.h>
using namespace std;

#define MAX 5

class stack_ {
private:
    int arr[MAX];
    int top;

public:
    stack_() {
        top = -1; // stack kosong
    }

    // push
    void push(int x) {
        if (top == MAX - 1) cout << "Stack overflow\n";
        else {
            arr[++top] = x;
            cout << x << " telah ditambahkan ke dalam stack\n";
        }
    }

    // pop
    void pop() {
        if(top == -1) cout << "Stack underflow\n";
        else {
            cout << arr[top--] << " dihapus dari stack\n";
        }
    }

    // top/peek
    void peek() {
        if (top == -1) cout << "Stack kosong\n";
        else cout << "Elemen teratas: " << arr[top] << endl;
    }
};

int main() {
    stack_ s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.peek();

    return 0;
}

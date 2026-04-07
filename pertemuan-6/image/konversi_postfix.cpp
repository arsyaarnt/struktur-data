#include <bits/stdc++.h>
using namespace std;

int precedence(char opr) {
    if(opr == '^') return 3;
    else if(opr == '*' || opr == '/') return 2;
    else if(opr == '+' || opr == '-') return 1;
    else return 0;
}

bool is_operator(char c) {
    return(c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

string infix_to_postfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if(isalnum(c)) postfix += c;
        else if(c == '(') st.push(c);
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if(!st.empty()) st.pop();
        }
        else if(is_operator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Masukkan ekspresi infix: ";
    cin >> infix;

    string postfix = infix_to_postfix(infix);

    cout << "Ekspresi postfix: " << postfix << endl;

    return 0;
}

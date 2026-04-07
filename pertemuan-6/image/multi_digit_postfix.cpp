#include <bits/stdc++.h>
using namespace std;

int eval_postfix(string exp) {
    stack<int> st;
    stringstream ss(exp);
    string token;

    while(ss >> token) {

        if(token == "*" || token == "/" || token == "+" || token == "-") {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();

            if(token == "*") st.push(num1 * num2);
            else if(token == "/") st.push(num1 / num2);
            else if(token == "+") st.push(num1 + num2);
            else st.push(num1 - num2);
        }
        else st.push(stoi(token));
    }

    return st.top();
}

int main() {
    string postfix;

    cout << "Masukkan ekspresi postfix (pisahkan dengan spasi): ";
    getline(cin, postfix);

    cout << "Hasil: " << eval_postfix(postfix) << endl;

    return 0;
}

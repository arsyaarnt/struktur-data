#include <bits/stdc++.h>
using namespace std;

void check_letter(char x) {
    if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o'
    || x == 'A' || x == 'I' || x == 'U' || x == 'E' || x == 'O') {
        cout << "Vowel";
    }
    else cout << "Consonant";
}

int main() {
    char letter;
    cin >> letter;

    check_letter(letter);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, column, n, num = 1;
    cin >> n;

    for(int row = 0; row <= n; row++) {
        for(int column = 0; column < row; column++) {
            cout << num++ << " ";
        }

        cout << "\n";
    }

    return 0;
}

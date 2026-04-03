#include <bits/stdc++.h>
using namespace std;

int main() {
    int matrix[3][4] = {{255, 250, 245, 240}, {150, 175, 200, 225}, {100, 125, 150, 175}};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

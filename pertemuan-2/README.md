# Review Dasar-dasar C++

## Input dan Output
Program akan meminta input untuk variabel ```angka``` dan ```huruf``` dari pengguna melalui ```cin```, dan meng-*print* output melalui ```cout``` dan ```puts```.

**Kode**:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    char huruf;
    cout << "Masukkan huruf: ";
    cin >> huruf;

    puts("Angka & huruf yang kamu input adalah: ");
    cout << angka << " & " << huruf << endl;

    return 0;
}
```

**Output**:
![Output File input_output.cpp](img/input_output.png)

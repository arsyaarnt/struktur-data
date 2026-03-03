# Review Dasar-dasar C++

## Input dan Output
Program akan meminta *input* untuk variabel ```angka``` dan ```huruf``` dari pengguna melalui ```cin```, dan meng-*print output* melalui ```cout``` dan ```puts```.

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

![Output File input_output.cpp](image/input_output.png)


## Control Flow
Program akan menentukan apakah angka yang di-*input* pengguna termasuk ke dalam bilangan ganjil atau genap.

**Kode**:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n % 2 == 0) cout << "Even";
    else cout << "Odd";

    return 0;
}
```
**Output**:

![Output File control_flow.cpp](image/control_flow.png)

## Loop
Program akan menjalankan program secara berulang (*looping*) sebanyak ```n``` kali (sesuai dengan apa yang di-*input* pengguna) hingga membentuk sebuah pola angka yang nilainya terus bertambah dengan bentuk segitiga.

**Kode**:
```cpp
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
```

**Output**:

![Output File loop.cpp](image/loop.png)

## Function 1 (Huruf)
Program akan menggunakan fungsi ```check_letter``` untuk menentukan apakah huruf yang di-*input* pengguna merupakan huruf vokal atau konsonan.

**Kode**:
```cpp
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
```

**Output**:

![Output File function.cpp](image/function.png)

## Function 2 (Bilangan Prima)
Program akan meng-*print* semua bilangan prima yang berada di dalam *range* angka yang telah ditentukan pengguna. Program akan menggunakan fungsi ```isPrime``` untuk menentukan apakah bilangan tersebut merupakan bilangan prima atau tidak, dan fungsi ```findPrimes``` untuk mencari bilangan-bilangan prima yang terdapat di dalam *range* yang telah ditentukan oleh pengguna.

**Kode**:
```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }

    return true;
}

void findPrimes(int left, int right) {
    bool found = false;
    for(int i = left; i <= right; i++) {
        if(isPrime(i)) {
            cout << i << " ";
            found = true;
        }
    }

    if(!found) cout << "No prime numbers found in the given range.";
}

int main() {
    int left, right;
    cin >> left >> right;

    findPrimes(left, right);

    return 0;
}
```

**Output**:

![Output File function2.cpp](image/function2.png)

## Array
Program akan menentukan nilai minimum menggunakan fungsi ```getMin``` dan maksimum menggunakan fungsi ```getMax``` dari *array* yang telah di-*input* pengguna.

**Kode**:
```cpp
#include <bits/stdc++.h>
using namespace std;

getMin(int arr[], int n) {
    int res = arr[0];
    for(int i = 0; i < n; i++) res = min(res, arr[i]);

    return res;
}

getMax(int arr[], int n) {
    int res = arr[0];
    for(int i = 0; i < n; i++) res = max(res, arr[i]);

    return res;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Minimum element of array: " << getMin(arr, n) << endl;
    cout << "Maximum element of array: " << getMax(arr, n) << endl;

    return 0;
}
```

**Output**:

![Output File array.cpp](image/array.png)

## Pointers
Program akan meng-*print* nilai dan alamat dari variabel ```var```, serta nilai yang disimpan di *pointer* ```ptr``` dan nilai yang ditunjuk oleh ```ptr``` menggunakan *dereference operator*.

**Kode**:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int var;
    cin >> var;

    int *ptr = &var;

    cout << "Value of x: " << var << endl;
    cout << "Address of x: " << &var << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    return 0;
}
```

**Output**:

![Output File pointers.cpp](image/pointers.png)

## String
Program akan menentukan *size* dari *string* ```str``` yang di-*input* pengguna menggunakan ```str.size()```.

**Kode**:
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    cout << str.size() << endl;

    return 0;
}
```

**Output**:

![Output File string.cpp](image/string.png)

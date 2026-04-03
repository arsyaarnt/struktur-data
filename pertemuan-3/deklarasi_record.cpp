#include <bits/stdc++.h>
using namespace std;

struct mahasiswa {
    string nim, nama, prodi;
    float ipk;
};

int main() {
    mahasiswa mhs1, mhs2;

    mhs1.nim = "5025251001";
    cin >> mhs1.nama;

    mhs2.nim = "5025251010";
    cin >> mhs2.ipk;

    cout << endl;
    cout << "NIM mhs1: " << mhs1.nim << endl;
    cout << "IPK mhs2: " << mhs2.ipk << endl;

    return 0;
}

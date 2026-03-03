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

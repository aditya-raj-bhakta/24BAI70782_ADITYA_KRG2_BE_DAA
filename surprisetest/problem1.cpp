#include <bits/stdc++.h>
using namespace std;

long long superDigit(long long n) {
    if (n < 10) return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

int main() {
    string n;
    long long k;
    cin >> n >> k;

    long long initialSum = 0;

    // Sum digits of n
    for (char c : n) {
        initialSum += (c - '0');
    }

    // Multiply by k
    initialSum *= k;

    cout << superDigit(initialSum) << endl;

    return 0;
}
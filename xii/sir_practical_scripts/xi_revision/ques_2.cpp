#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long long fibonacci(int n) {
    long long f = 0, s = 1, t;
    if (n < 3) return (n - 1);
    for (int i = n - 2; i > 0; --i) {
        t = f + s;
        f = s;
        s = t;
    }
    return t;
}

int main() {
    unsigned int terms = 0;
    cout << "No. of terms? "; cin >> terms;
    for (int i = 1; i <= terms; ++i)
        cout << i << " - " << fibonacci(i) << endl;

    while (getchar() != '\n');
    getchar();
}

#include <iostream>
#include <iomanip>
using namespace std;

int comb(int n, int r) {
    float k = 1;
    if( n < 0 or r < 0 or r > n) return 0;
    for (int i = 0; i < r; ++i) {
        k *= float(n-i)/(i+1);
    }
    return k;
}

int main() {
    int n;
    cout << "Enter no. of line : "; cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k < (n - i); ++k) cout << "    ";
        for (int r = 0; r <= i; ++r) 
            cout << setw(8) << comb(i, r);
        cout << endl;
    }
    while (getchar() != '\n');
    getchar();
}
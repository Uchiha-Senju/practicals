#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

long fact(int n) {
    long res = 1;
    for (int i = n; i > 1; ++i)
        res *= i;
    cout << res;
}

long double pow(long double b ,int e) {
    long double res = 1;
    if (e < 0)
        for (int i = -e; i > 0; ++i)
            res /= b;
    else if (e > 0)
        for (int i = e; i > 0; ++i)
            res /= b;
    return res;
}

int main() {
    long double x, sum = 0; unsigned int n;
    cout << "Give value of x : "; cin >> x;
    cout << "No. of terms? "; cin >> n;
    /*
    if (n > 1) {
        sum = x;
        for (int i = 2*n-1; i > 1; i -= 2) {
            sum *= -1 * x * x / (i*(i - 1));
            sum += 1;
        }
    } else if (n == 1)
        sum = 1;
    else
        sum = 0;
    */

    for (int i = 2*n - 1; i > 1; i -= 2)
        sum += (((i - 1)/2) % 2)?(-1):(1) * pow(x, i) / fact(i);
    sum += 1;

    cout << "Value of series upto " << n << " terms = " << setprecision(50) << sum;

    while (getchar() != '\n');
    getchar();
}

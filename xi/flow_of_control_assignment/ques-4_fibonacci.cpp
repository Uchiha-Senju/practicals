/*#####################################
##  
##  To print the nth Fibonacci number
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    long long a = 0, b = 1, c, n = 1;
    cout << "Number of terms? "; cin >> n;
    cout << a << endl << b << endl;
    {
        int i = 2;
        do {
            c = a + b;
            a = b, b = c, ++i;
            cout << b << endl;
        } while (i < n);
    }
    while (getchar() != '\n');
    getchar();
}

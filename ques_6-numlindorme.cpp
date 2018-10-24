/*#####################################################
##    
##    To take number and output it's digit-wise
##    palindrome e.g.
##    2493339 => 9333949
##    
##    By Varad Mahahsabde
##    Copyright 2018
##    
####################################################*/

#include <iostream>
using namespace std;

int main() {
    long x, x_copy; int b = 10; cout << "Enter number : "; cin >> x;
    x_copy = x;
    while (x_copy > 0) {
        cout << x_copy % b;
        x_copy /= b;
    }
    cout << endl;
    {while (getchar() != '\n');
    getchar();}
}

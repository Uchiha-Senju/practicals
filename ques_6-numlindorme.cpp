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
    long x; int b = 10; cout << "Enter number : "; cin >> x;
    while (x>0) {
        cout << x%b;
        x /= b;
    }
    cout << endl;
    getchar();
}

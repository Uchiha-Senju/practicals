/*#####################################
##  
##  To check if the given number is a
##  palindrome
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    long long x, temp, mirror = 0; int b = 10;
    cout << "Enter number : "; cin >> x;
    temp = x;
    while (temp > 0) {
        mirror *= b;
        mirror += temp % b;
        temp /= b;
    }
    if (x == mirror) cout << "Number is a palindrome\n";
    else cout << "Number is not a palindrome\n";
    while (getchar() != '\n');
    getchar();
}

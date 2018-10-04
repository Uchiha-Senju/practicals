/*####################################################
##    
##    To confirm if given number is trimorphic i.e.
##    it's cube ends in itself e.g.
##    4 -> 6 4
##    24 -> 138 24
##    249 -> 15438 249
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
####################################################*/

#include <iostream>
using namespace std;

double pow(double b , int e) {
    double r = 1;
    for (int i = 0; i < abs(e); ++i) {
        if (b > 0) r *= double(b);
        if (b < 0) r /= double (b);
    }
    return r;
}

int main() {
    int n, n_alt, digit_no = 0; cout << "Enter the number : "; cin >> n;
    n_alt = n;
    while (n_alt > 0) {
        n_alt /= 10;
        ++digit_no;
    }
    if ( !n ) digit_no = 1;
    if ( n*n*n % (long long int)(pow(10, digit_no)) == n) cout << n << " is trimorphic ( n^3 = " << n*n*n / (long long int)(pow(10, digit_no)) << " " << n << ")"<< endl;
    else cout << n << " is not trimorphic (n^3 = " << n*n*n << ")"<< endl;
}

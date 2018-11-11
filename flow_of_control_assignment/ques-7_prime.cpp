/*#####################################
##  
##  To print all prime numbers till a
##  given point
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

double sqrt(double x) {
    double a = 1, a_old = 0;
    while (a != a_old && x > 0) {
        a_old = a;
        a -= (a - x/a)/2;
    }
    return a_old;
}

bool isPrime(int x) {
    double upper_bound = sqrt(x);
    for (int i = 2; i <= upper_bound; ++i) if(!(x%i)) return false;
    return true;
}

int main() {
    unsigned int n;
    cout << "Enter the limit : "; cin >> n;
    for (int i = 2; i <= n; ++i) if (isPrime(i)) cout << i << endl;
}

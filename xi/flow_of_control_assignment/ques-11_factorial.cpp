/*#####################################
##  
##  
##  
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
#include <iomanip>
using namespace std;

long double fact(int x) {
    long double a = 1;
    if (x < 0) return 0;
    for (int i = 2; i <= x; ++i) 
        a *= i;
    return a;
}

int main() {
    int n;
    cout << "Give number : "; cin >> n;
    cout << "Factorial : " << setprecision(50) << fact(n) << endl;
    while (getchar() != '\n');
    getchar();
}

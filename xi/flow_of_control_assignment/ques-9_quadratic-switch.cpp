/*#####################################
##  
##  To calculate the roots of a
##  quadratic equation
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

long double sqrt(long double x) {
    long double a = 1, a_old = 0;
    if(x <= 0) return 0;
    while (a != a_old) {
        a_old = a;
        a -= (a - x/a)/2;
    }
    return a;
    
}

int main() {
    double a, b, c, D;
    char choice;
    cout << "Enter the co-efficients of x^2, x, and 1 : "; cin >> a >> b >> c;
    if ((D = b*b - 4*a*c) < 0) 
        cout << "The given equation has imaginary roots";
    else {
        cout << "Bigger root or smaller root first (b/s)?"; cin >> choice;
        if (choice >= 'a' and choice <= 'z') choice -= 32;
        switch (choice) {
            case 'B':
                cout << "The roots are " << (-b+sqrt(D))/2*a << " and " << (-b-sqrt(D))/2*a << endl;
                break;
            case 'S':
                cout << "The roots are " << (-b-sqrt(D))/2*a << " and " << (-b+sqrt(D))/2*a << endl;
                break;
            default :
                return 1;
                break;
        }
    }
    while (getchar() != '\n');
    getchar();
}

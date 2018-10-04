/*####################################################
##    
##    
##    
##    
##    
##    
##    
##    
##    
##    
####################################################*/

#include <iostream>
#include <string.h>
using namespace std;

int abs(int x) {
    return (x > 0)? x : -x;
}

double pow(double b , int e) {
    double r = 1;
    for (int i = 0; i < abs(e); ++i) {
        if (b > 0) r *= double(b);
        if (b < 0) r /= double (b);
    }
    return r;
}

double pow10l(int e) {
    return pow(10,e);
}

double nthRoot(double b, double n) {
    double a = 1, d;
    d = (a - b / pow(a, (n - 1) ));
    while (d > 1e-14) {
        a -= d;
        d = (a - b / pow(a, (n - 1) ));
    }
    return (a>-1)? a : 1/0;
}

double pow(double b, double e) {
    double r;
    e *= 1000000;
    return nthRoot( pow(b, int(e)), 1000000);
}

int fact(int x) {
    int f = 1;
    for (int i = 2; i <= x; ++i) f *= i;
    return f;
}

double exp(double x) {
    double a = 0;
    for (int i = 0; i < 100; ++i) 
        a += pow(x, i) / fact(i);
    return a;
}

double sin(double x) {
    double a = 0;
    for (int i = 0; i < 100; ++i)
        a += pow(double(-1),i) * pow(x,i) / fact(i);
    return a;
}

double cos(double x) {
    double a = 0;
    for (int i = 0; i < 100; ++i)
        a += pow(double(-1),i) * pow(x,(2 * i + 1)) / fact((2 * i + 1));
    return a;
}

double pi(int accuracy) {
    double pipa = 4;
    for (int i = 0; i < accuracy; ++i) pipa += pow(-1.0,i) * 4 / (2 * i + 1);
    return pipa;
}

int main() {
    string choice;
    double x,y;
    while (true) {
        cout << "\n\nCall function (hl for help) :"; cin >> choice;
        switch (choice) {
            case "hl":
                cout << "\nsn - sin\ncs - cosine\npi - pi\nex - power of e\nfc - factorial\npw - power of given number\nab - absolute value of given number\nnr - nth root of given num\n10 - nth power of 10";
                break;
            case "sn":
                cout << "Enter angle : "; cin >> x;
                cout << sin(x);
                break;
            case "cs":
                cout << "Enter angle : "; cin >> x;
                cout << cos(x);
                break;
            case "pi":
                cout << "Enter angle : "; cin >> x;
                cout << pi(x);
                break;
            case "ex":
                cout << "Enter exponent : "; cin >> x;
                cout << exp(x);
                break;
            case "fc":
                cout << "Enter number : "; cin >> x;
                cout << fact(x);
                break;
            case "pw":
                cout << "Enter base and exponent : "; cin >> x >> y;
                cout << sin(x);
                break;
            case "ab":
                cout << "Enter number : "; cin >> x;
                cout << abs(x);
                break;
            case "nr":
                cout << "Enter base and root : "; cin >> x >> y;
                cout << nthRoot(x,y);
                break;
            case "10":
                cout << "Enter exponent of 10 : "; cin >> x;
                cout << pow10l(x);
                break;
        }
    }
}
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
    return (a>-1)? a : nan;
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

int main() {
    cout
}
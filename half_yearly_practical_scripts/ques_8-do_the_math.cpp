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
#include <iomanip>
#include <string.h>
using namespace std;

int abs(int x) {
    return (x > 0)? x : -x;
}
long double abs(long double x) {
    return (x > 0)? x : -x;
}

long double pow_int(long double b, int e) {
    long double res = 1;
    if (e > 0) {
        while (e) {
            if (e % 2) 
                res *= b;
            e /= 2;
            b *= b;
        }
    } else {
        e *= -1;
        while (e) {
            if (e % 2) 
                res *= b;
            e /= 2;
            b *= b;
        }
        res = 1/res;
    }
    return res;
}

long double pow10(int e) {
    return pow_int(10,e);
}

long double sqrt(long double n) {
    long double r = 1, r_old = 0;
    while ((r != r_old) && n>0) {
        r_old = r;
        r -= (r - n/r)/2; // Babylonian / Newton's method
    }
    return (n>0) ? r : 0; //return 0 if non-positive number
}

long double cbrt(long double n) {
    long double r = 1, r_old = 0;
    while ((r != r_old) && n>0) {
        r_old = r;
        r -= (r - n/(r*r))/3; // Newton's method
    }
    return r;
}

long double fact(long double x) {
    if (x < 0) return 0;
    long double f = 1;
    for (int i = 2; i <= x; ++i) f *= i;
    return f;
}

long double exp(long double x) {
    long double a = 0, a_old = -1;
    for (int i = 0; a != a_old; ++i) {
        a_old = a;
        a += pow_int(x, i) / fact(i); // Taylor series for e^x
    }
    return a;
}

long double ln(long double x) {
    if (x <= 0) return -exp(-1280);
    long double a = 0, a_old = 1, base = (x-1)/(x+1);
    for (int i = 1; a != a_old; i += 2) {
        a_old = a;
        a += 2 * pow_int(base, i) / i;
        // a -= 1 - x / exp(a); //Newton's method for ln x
        // cout << a << endl;
        // e = exp(a);
        // a -= 2*(e - a)/ (e + a); //Halley's method (full is 2(e^x - a) * de^x / (2* (de^x)^2 - (e^x - a)*d^2(e^x)))
    }
    return a;
}
//Shortcuts
long double log(long double x, long double b) {
    return ln(x) / ln(b); //Change of base formula
}
long double log10(long double x) {
    return log(x,10);
}
long double log2(long double x) {
    return log(x,2);
}

//Hyberbolic Trig functions
long double sinh(long double x) {
    return (exp(x) - exp(-x))/2;
}
long double cosh(long double x) {
    return (exp(x) + exp(-x))/2;
}
long double tanh(long double x) {
    return sinh(x)/tanh(x);
}
long double coth(long double x) {
    return cosh(x) / sinh(x);
}
long double sech(long double x) {
    return 1 / cosh(x);
}
long double cosech(long double x) {
    return 1 / sinh(x);
}long double csch(long double x) {return cosech(x);}

long double pi(int accuracy) {
    long double s = 0, term_1, term_2;
     // Chudnovsky series for pi, ((i % 2)?-1:1) alternates between -1 and 1; see here http://numbers.computation.free.fr/Constants/Pi/piramanujan.html
    for (int i = 0; i < accuracy; ++i) {
         term_1 = (fact(6 * i) / ( fact(i) * fact(i) * fact(i) * fact(3*i)));
         term_2 = (13591409.0L+545140134.0L*i) / (pow_int(640320.0L, (3*i + 1)) * sqrt(640320.0L));
         s += 12 * ((i % 2)?-1:1) * term_1 * term_2;
    }
    cout << s << endl;
    return 1/s;
}
//Trig functions
long double sin(long double x) {
    long double a = 0, a_old = -1;
    long double two_pie = 2*pi(314);
    x = (x / two_pie - long(x / two_pie)) * two_pie;
    for (int i = 1; a != a_old; ++i) {
        a_old = a;
        a += ((i % 2)?1:-1) * pow_int(x,2*i-1) / fact(2*i-1); //Taylor series for sin (All odd powers), ((i % 2)?1:-1) alternates between 1 and -1
    }
    return a;
}

long double cos(long double x) {
    long double a = 0, a_old = -1;
    long double two_pie = 2*pi(314);
    x = (x / two_pie - long(x / two_pie)) * two_pie;
    for (int i = 0; a != a_old; ++i) {
        a_old = a;
        a += ((i % 2)?-1:1) * pow_int(x,2*i) / fact(2*i); //Taylor series for cosin (All even powers), ((i % 2)?1:-1) alternates between 1 and -1
    }
    return a;
}
// Can't have polynomial expansions with asymptotes 
long double tan(long double x) {
    return sin(x) / cos(x);
}
long double cot(long double x) {
    return cos(x) / sin(x);
}
long double sec(long double x) {
    return 1 / cos(x);
}
long double cosec(long double x) {
    return 1 / sin(x);
}long double csc(long double x) {return cosec(x);}

// HE HAS ARRIVED. THE POWER FUNCTION
long double pow(long double b, long double e) {
    if (e < 0) 
        return pow(b, -e);
    else if 
        (e == 0) return 1;
    else 
        return exp((e * ln(b)));
}

int main() {
    string choice;
    long double x,y;
    while (true) {
        cout << "\n\nCall function (hl for help) : "; cin >> choice;
        for (char c : choice ) if (c <= 'Z' && c >= 'A') c += 32; // Turn all characters to lower
        if (choice == "hl")
            cout << "\ntrig - Trignometric functions\n"
                 <<  "h-trig - Hyperbolic trig functions\n"
                 <<  "pi - pi approximation\n"
                 <<  "exp - power of e\n"
                 <<  "ln - natural log\n"
                 <<  "log - log with any base\n"
                 <<  "log2 - log with base 2\n"
                 <<  "log10 - log with base 10\n"
                 <<  "sqrt - square root of num\n"
                 <<  "cbrt - cube root of num\n"
                 <<  "fact - factorial\n"
                 <<  "pow - power of given number\n"
                 <<  "abs - absolute value of given number\n"
                 <<  "pow10 - nth power of 10\n"
                 <<  "bye - exit\n";
        else if (choice == "trig") {
            trig:
            cout << "\n\nCall trig function (hl for help) : "; cin >> choice;
            for (char c : choice) if (c <= 'Z' && c >= 'A') c += 32; // Turn all characters to lower
            if (choice == "hl") {
                cout << "\nsin - sine\ncos - cosine\ntan - tangent\nsec - secant\ncosec/csc - cosecant\ncot - cotangent\n";
                goto trig;
            } else if (choice == "sin") {
                cout << "Enter circular angle : "; cin >> x;
                cout << setprecision(50) << sin(x);
            } else if (choice == "cos") {
                cout << "Enter circular angle : "; cin >> x;
                cout << setprecision(50) << cos(x);
            } else if (choice == "tan") {
                cout << "Enter circular angle : "; cin >> x;
                cout << setprecision(50) << tan(x);
            } else if (choice == "sec") {
                cout << "Enter circular angle : "; cin >> x;
                cout << setprecision(50) << sec(x);
            } else if (choice == "cosec" || choice == "csc") {
                cout << "Enter circular angle : "; cin >> x;
                cout << setprecision(50) << cosec(x);
            } else if (choice == "cot") {
                cout << "Enter circular angle : "; cin >> x;
                cout << setprecision(50) << cot(x);
            } else cout << "That ain't no trig function\n";
        }
        else if (choice == "h-trig") {
            htrig:
            cout << "\n\nCall hyperbolic trig function (hl for help) : "; cin >> choice;
            for (char c : choice) if (c <= 'Z' && c >= 'A') c += 32; // Turn all characters to lower
            if (choice == "hl") {
                cout << "\nsinh - hyperbolic sine\ncosh - hyperbolic cosine\ntanh - hyperbolic tangent\nsech - hyperbolic secant\ncosech/csch - hyperbolic cosecant\ncoth - hyperbolic cotangent\n";
                goto htrig;
            } else if (choice == "sinh") {
                cout << "Enter hyperbolic angle : "; cin >> x;
                cout << setprecision(50) << sinh(x);
            } else if (choice == "cosh") {
                cout << "Enter hyperbolic angle : "; cin >> x;
                cout << setprecision(50) << cosh(x);
            } else if (choice == "tanh") {
                cout << "Enter hyperbolic angle : "; cin >> x;
                cout << setprecision(50) << tanh(x);
            } else if (choice == "sech") {
                cout << "Enter hyperbolic angle : "; cin >> x;
                cout << setprecision(50) << sech(x);
            } else if (choice == "cosech" || choice == "csch") {
                cout << "Enter hyperbolic angle : "; cin >> x;
                cout << setprecision(50) << cosech(x);
            } else if (choice == "coth") {
                cout << "Enter hyperbolic angle : "; cin >> x;
                cout << setprecision(50) << coth(x);
            } else cout << "That ain't no hyperbolic trig function\n";
        } 
        else if (choice == "pi") {
            cout << "Enter level of accuracy : "; cin >> x;
            cout << setprecision(50) << pi(x);
        } else if (choice == "exp") {
            cout << "Enter exponent : "; cin >> x;
            cout << setprecision(50) << exp(x);
        } else if (choice == "ln") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << ln(x);
        } else if (choice == "log") {
            cout << "Enter number and base : "; cin >> x >> y;
            cout << setprecision(50) << log(x,y);
        } else if (choice == "log2") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << log2(x);
        } else if (choice == "log10") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << log10(x);
        } else if (choice == "fact") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << fact(x);
        } else if (choice == "pow") {
            cout << "Enter base and exponent : "; cin >> x >> y;
            if (int(y) == y) 
                cout << setprecision(50) << pow_int(x,y);
            else 
                cout << setprecision(50) << pow(x,y);
        } else if (choice == "abs") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << abs(x);
        } else if (choice == "sqrt") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << sqrt(x);
        } else if (choice == "cbrt") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << cbrt(x);
        } else if (choice == "pow10") {
            cout << "Enter exponent of 10 : "; cin >> x;
            cout << setprecision(50) << pow10(x);
        } else if (choice == "bye") {
            cout << "Bye !!\n";
            break;
        } else cout << "Wrong choice!! Try Again\n";
    }
    {while (getchar() != '\n');
    getchar();}
}

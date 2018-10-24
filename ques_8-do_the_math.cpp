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

long double pow(long double b , int e) {
    long double r = 1;
    if (e > 0)
        for (int i = 0; i < e; ++i)
            r *= b;
    else if (e < 0)
        for (int i = (e *= -1 , 0); i < e; ++i)
            r /= b;
    return r;
}

long double pow10(int e) {
    return pow(10,e);
}

long double sqrt(long double n) {
    long double r = 1, r_old = 0;
    while ((r != r_old) && n>0) {
        r_old = r;
        r -= (r - n/r)/2; // Babylonian / Newton's method
    }
    return (n>0) ? r : 0; //return 0 if non-positive number
}

long double nthRoot(long double x, int n) {
    long double a = 1, a_old, power;
    cout << "yolo";
    while (a != a_old && x >= 0) {
        cout << "yplo";
        a = a_old;
        power = pow(a, (n - 1) );
        a -= (a - x / power) / n; //Newton's method generalised
    }
    cout << "polo";
    return (x < 0 && !(n % 2))? 0 : a; // Return answer
}

// long double powd(long double b, long double e) {
    // long double r;
    // e *= 1000000;
    // return nthRoot( pow(b, int(e)), 1000000);
// }

long double fact(long double x) {
    long double f = 1;
    for (int i = 2; i <= x; ++i) f *= i;
    return f;
}

long double exp(long double x) {
    long double a = 0, a_old = -1;
    for (int i = 0; a != a_old; ++i) {
        a_old = a;
        a += pow(x, i) / fact(i); // Taylor series for e^x
    }
    return a;
}

long double ln(long double x) {
    long double a = 1, a_old = 0, e;
    while (a != a_old && x > 0) {
        a_old = a;
       //a -= 1 - x / exp(a); //Newton's method for ln x
       e = exp(a);
       a -= 2*(e - a)/ (e + a); //Halley's method (full is 2(e^x - a) * de^x / (2* (de^x)^2 - (e^x - a)*d^2(e^x)))
    }
    return (x > 0)?a:-exp(-1280);
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
         term_2 = (13591409.0L+545140134.0L*i) / (pow(640320.0L, (3*i + 1)) * sqrt(640320.0L));
         s += 12 * ((i % 2)?-1:1) * term_1 * term_2;
    }
    cout << s << endl;
    return 1/s;
}
//Trig functions
long double sin(long double x) {
    long double a = 0, a_old = -1;
    x = (x / pi(4) - long(x / pi(4)))*pi(4);
    for (int i = 1; a != a_old; ++i) {
        a_old = a;
        a += ((i % 2)?1:-1) * pow(x,2*i-1) / fact(2*i-1); //Taylor series for sin (All odd powers), ((i % 2)?1:-1) alternates between 1 and -1
    }
    return a;
}

long double cos(long double x) {
    long double a = 0, a_old = -1;
    x = (x / pi(4) - long(x / pi(4)))*pi(4);
    for (int i = 0; a != a_old; ++i) {
        a_old = a;
        a += ((i % 2)?-1:1) * pow(x,2*i) / fact(2*i); //Taylor series for cosin (All even powers), ((i % 2)?1:-1) alternates between 1 and -1
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

int main() {
    string choice;
    long double x,y;
    while (true) {
        cout << "\n\nCall function (hl for help) : "; cin >> choice;
        for (char c : choice) if (c <= 'Z' && c >= 'A') c += 32; // Turn all characters to lower
        if (choice == "hl")
            cout << "\ntrig - Trignometric functions\nh-trig - Hyperbolic trig functions\npi - pi approximation\nexp - power of e\nsqrt - square root of num\nfact - factorial\npow - power of given number\nabs - absolute value of given number\nnroot - nth root of given num\npow10 - nth power of 10\nbye - exit\n";
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
        } else if (choice == "htrig") {
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
        } else if (choice == "pi") {
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
            cout << setprecision(50) << pow(x,y);
        } else if (choice == "abs") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << abs(x);
        } else if (choice == "sqrt") {
            cout << "Enter number : "; cin >> x;
            cout << setprecision(50) << sqrt(x);
        } else if (choice == "nroot") {
            cout << "Enter base and root : "; cin >> x >> y;
            cout << setprecision(50) << nthRoot(x,y);
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
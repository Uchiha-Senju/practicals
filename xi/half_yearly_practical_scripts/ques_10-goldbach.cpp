/*####################################################
##    
##    To play the Royal Game of Ur
##    Each player has seven pieces which need to
##    navigate through a board of twenty squares to
##    reach the end  without being kicked out by the
##    fellow player's pieces
##    https://www.youtube.com/watch?v=WZskjLq040I
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
####################################################*/

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
    int limit = 0;
    bool prime_sum_printed = false;
    while (limit <= 3) {
        cout << "Check till? "; cin >> limit;
    }
    for (int i = 4; i <= limit; i += 2) {
        for (int j = 2; j < i; ++j)
            if (isPrime(j) && isPrime(i-j)) {
                cout << i << " = " << j << " + " << (i-j) << endl;
                prime_sum_printed = true;
                break;
            }
        if (!prime_sum_printed) {
            cout << "GOLDBACK DISPROVEN! REPEAT, GOLDBACH DISPROVEN AT " << i;
            break;
        }
        prime_sum_printed = false;
    }
    while (getchar() != '\n');
    getchar();
}


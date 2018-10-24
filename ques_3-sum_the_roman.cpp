/*####################################################
##    
##    To take a matrix of Roman numerals and print
##    their sum e.g.
##    Input  : IV XI
##    Output : xV
##    Input  : CM VII
##    Output : CMVII
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
##    Time taken : 1 hour 50 minutes
##    
##    Problems encountered : strict v. slack !=,
##    wrong facing !=, dealing with the logic I wrote
##    45 minutes ago, funcs that take char pointers
##    instead of strings, int-int v. int-double 
##    effects in operands
##    
####################################################*/

#include <iostream>
#include <cstring>
using namespace std;

int pow(int b, int e){
    int pow = 1;
    while (e) {
        pow *= b;
        --e;
    }
    return pow;
}

int toNum_let(char k) {
    switch (k) {
        case 'M': return 1000; break;
        case 'D': return 500; break;
        case 'C': return 100; break;
        case 'L': return 50; break;
        case 'X': return 10; break;
        case 'V': return 5; break;
        case 'I': return 1; break;
        default : return 0; break;
    }
}

char toRoman_dig(int n) {
    switch (n) {
        case 1000: return 'M'; break;
        case 500: return 'D'; break;
        case 100: return 'C'; break;
        case 50: return 'L'; break;
        case 10: return 'X'; break;
        case 5: return 'V'; break;
        case 1: return 'I'; break;
        default : return char(434); break;
    }
}

int toNum(string k) {
    int n = 0; char c;
    for (int i = 0; i < strlen(&k[0]) - 1 ; ++i) {
        if (toNum_let(k[i]) < toNum_let(k[i+1])) n -= toNum_let(k[i]); //If next greater, subtract
        else if (toNum_let(k[i]) >= toNum_let(k[i+1])) n += toNum_let(k[i]); //If next smaller or equal, add
    }
    n += toNum_let(k [ strlen(&k[0]) - 1]); //Add last digit
    return n;
}

string toRoman(int n) {
    int no_dig = 0; string k = "";
    if (n != 0) for (; n == 0 || pow(10,no_dig) <= n; ++no_dig) ;
    else no_dig++;
    for (int i = no_dig; i > -1; --i) {
        if ( n/pow(10,i) != 4 &&  n/pow(10,i) != 9 && n/pow(10,i) < 5 && n/pow(10,i)) for (int l = 0; l<n/pow(10,i); ++l) k += toRoman_dig(pow(10,i));
        else if (n/pow(10,i) == 5) k += toRoman_dig(pow(10,i)*5);
        else if (n/pow(10,i) == 4) {
            k += toRoman_dig(pow(10,i)); k += toRoman_dig(pow(10,i)*5); //Print 4 as 5 - 1;
        } else if (n/pow(10,i) == 9) {
            k += toRoman_dig(pow(10,i)); k += toRoman_dig(pow(10,i+1)); //Print 9 as 10 - 1
        }
        else if (n/pow(10,i) > 5) {
            k += toRoman_dig(pow(10,i)*5); //Print hte 5 factor separatley
            for (int l = 0; l<n/pow(10,i)-5; ++l) k += toRoman_dig(pow(10,i));
        }
        n %= int(pow(10,i));
    }
    return k;
}

int main () {
    while (true) {
        int sum = 0;
        string roman[2];
        cout << "Enter two Roman numerals : "; cin >> roman[0];
        if (roman[0][0] == '0') break;
        cin >> roman[1];
        if (roman[1][0] == '0') break;
        for (int i = 0; i < 2; ++i) {
            for (char n : roman[i]) {
                if (int(n) > 96 && int(n) <  123) n = char(int(n)-32); // Turn all upper
                if (!((int(n) > 96 && int(n) <  123) || (int(n) > 64 && int(n) <  91)) )  {
                    cout << "INVALID INPUT" << endl;
                    return 1; // Abort if non letters present
                }
            }
            sum += toNum(roman[i]);
        }
        cout << toRoman(sum) << endl;
    }
    {while (getchar() != '\n');
    getchar();}
    /* times of struggle
    int n = 0;
    bool works = true;
    cout << works;
    while (n<3999) {
        works = works && n == toNum(toRoman(n));
        cout << n << "  " << toRoman(n) << "  " << toNum(toRoman(n)) << endl;
        ++n;
    }
    cout << works;*/
}


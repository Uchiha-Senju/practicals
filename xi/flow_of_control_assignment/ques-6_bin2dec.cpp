/*#####################################
##  
##  To convert given binary number to
##  decimal base
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    unsigned long long dec = 0, dec_palin = 0, pow2 = 1;
    int zero_trail = 0;
    char bit = ' '; 
    cout << "Enter binary number : ";// cin >> bin;
    //Get binary num but in palindrome
    for (int i = 0; (bit = getchar()) != '\n'; ++i) {
        if (bit == '1') (dec_palin += pow2) | (zero_trail = 0);
        else if (bit == '0') zero_trail++;
        else return 1;
        pow2 *= 2;
    }
    //Switch palindrome to orignal
    while (dec_palin > 0) {
        dec *= 2;
        dec += dec_palin % 2;
        dec_palin /= 2;
    }
    // Compensate for trailing zero error
    for (int i = 0; i < zero_trail; ++i) dec *= 2;
    cout << "Decimal number : " << dec << endl;
    //while (getchar() != '\n'); cin is already exhausted
    getchar();
    // When you feel amazing by deciding to use getchar to save on memory and forego limitations
    // but you have to revert to simpler times because you can't account for the ending zeros
    // Method  was to take bin number with the bits individually with getchar, but the result would be the palindrome as the number is from left to right and getchar would read right to left, so we would take the number's palindrome, but the palindrome wouldn't store data for any trailing zeros at the end :(
}

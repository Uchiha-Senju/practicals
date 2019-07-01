#include <iostream>
using namespace std;

//int terms = 0;

long fact(int n) {
    long res = n;
    for (int i = 2; i < n; ++i)
        res *= i;
    return res;
}

void printN_Nomial (int n) {
    cout << "(";
    for (char c = 'a'; c < 'a' + n; ++c) 
        cout << c << " + ";
    cout << "\b \b\b \b\b \b)"; // not "\b\b" as it is non-destructive
}

float choose(int n, int r) {
    float res = 1;
    if (n < 0 or r < 0 or r > n) return 0;
    for (int i = 0; i < r; ++i) 
        res *= float(n - i) / (i + 1);
    return res;
}

long sumAcrossArray(int arr[], int start, int end) {
    long res = 0;
    for (int i = start; i < end; ++i) 
        res += arr[i];
    return res;
}

float giveN_NomialCoefficient(int exponent, int no_terms, int var_powers[]) {
    // Cannot have more terms of a greater degree than initial expression
    if (sumAcrossArray(var_powers, 0 , no_terms) != exponent) return 0;
    
    // long res = fact(exponent);
    float res = 1;
    int max_n = exponent;
    // for (int i = 0; i < no_terms; ++i)
        // res /= fact(var_powers[i]);
    
    //Using alternate method of multiplying (n choose k) to avoid overflow
    for (int i = 0; i < no_terms - 1; ++i) {
        res *= choose(max_n, var_powers[i]);
        max_n -= var_powers[i];
    }
    return res;
}

void Get_N_Recursion(int exponent, int no_terms, int recursion_level, int max_recursion, int iterator_init, int iterator_max, int previous_iterators[]) { //, int iterator_jump) {
    if (recursion_level < max_recursion) 
        for (int i = iterator_init; i < iterator_max; ++i) {
            previous_iterators[recursion_level] = i;
            Get_N_Recursion(exponent, no_terms, (recursion_level + 1), max_recursion, 0, (iterator_max - i), previous_iterators);
        }
        
        
    else if (recursion_level == max_recursion) {
        
        // Print a term of the expansion
        previous_iterators[no_terms - 1] = exponent - sumAcrossArray(previous_iterators, 0, (no_terms - 1));
        long coeff = giveN_NomialCoefficient(exponent, no_terms, previous_iterators);
        if (coeff != 1)
            cout << coeff << '*';
        
        
        // for (int i = 0; i < no_terms; ++i) 
            // if (previous_iterators[i] == 1) 
                // cout << char('a' + i) << '*';
            // else if (previous_iterators[i] != 0)
                // cout << char('a' + i) << '^' << previous_iterators[i] << '*';
        // Alternate formatting, otherwise the same
        // now the end of previous_iterators corresponds to a, then b and so on since they get to max value first
        for (int i = no_terms - 1; i > -1; --i) 
            if (previous_iterators[i] == 1) 
                cout << char('a' + no_terms - i - 1) << '*';
            else if (previous_iterators[i] != 0)
                cout << char('a' + no_terms - i - 1) << '^' << previous_iterators[i] << '*';
            
        cout << "\b + ";
        //terms++;
    }
}

int main () {
    unsigned int no_terms, exponent;
    //unsigned int var_powers[26];
    //for (int i = 0; i < 26; ++i) var_powers[i] = 0;
    do {
        cout << "Give no. of terms : "; cin >> no_terms;
        if (no_terms < 1 or no_terms > 26) cout << "ERR : INSUFFICIENT SYMBOLS. MAX 26\n";
    } while (no_terms < 1 or no_terms > 26);
    
    cout << no_terms << "-nomial is : \n";
    printN_Nomial(no_terms);
    
    cout << "\nExponent : "; cin >> exponent;
    cout << "\n\nNo. of terms : " << choose((exponent + no_terms - 1), (no_terms - 1)) << "\n\n";
    
    if (exponent == 0) {
        cout << "Expansion is "; printN_Nomial(no_terms); cout << "^" << exponent << " = 1\n";
        
        while (getchar() != '\n');
        getchar();
        return 0;
    }
    cout << "Expansion is : \n\t"; printN_Nomial(no_terms); cout << "^" << exponent << " = ";
    
    //print out the trinomials
    int var_powers[no_terms];
    Get_N_Recursion(exponent, no_terms, 0, (no_terms - 1), 0, (exponent + 1), var_powers);
    
    cout << "\b \b\b \b\b \b\n";
    
    //cout << "\n\nNo. of terms : " << terms << "\n\n";
    
    while (getchar() != '\n');
    getchar();
    return 0;
}

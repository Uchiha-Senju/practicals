/*#####################################
##  
##  To select the greatest of three
##  numbers
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
using namespace std;

int main() {
    int n = 0, max;
    while (n <= 0) {
    cout << "Enter no. of numbers : "; cin >> n;}
    int num[n];
    cout << "Enter the numbers : ";
    for (int i = 0; i < n; ++i) 
        cin >> num[i];
    max = num[0];
    for (int i = 0; i < n; ++i) 
        if (max < num[i]) 
            max = num[i];
    cout << "Max number : " << max << endl;
    while (getchar() != '\n');
    getchar();
}

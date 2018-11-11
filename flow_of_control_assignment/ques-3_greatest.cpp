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
    float num[3], max;
    cout << "Enter the numbers : ";
    for (int i = 0; i < 3; ++i) 
        cin >> num[i];
    max = num[0];
    for (int i = 0; i < 3; ++i) 
        if (max < num[i]) 
            max = num[i];
    cout << "Max number : " << max << endl;
    while (getchar() != '\n');
    getchar();
}

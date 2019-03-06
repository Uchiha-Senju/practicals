/*#####################################
##  
##  
##  
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string text;
    char c;
    cout << "Enter string : ";
    while ((c =getchar()) != '\n') 
        text += c;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] >= 'A' && text[i] <= 'Z') text[i] += 32;
        else if (text[i] >= 'a' && text[i] <= 'z') text[i] -= 32;
    }
    cout << "Altered text : " << text;
    while (getchar() != '\n');
    getchar();
}

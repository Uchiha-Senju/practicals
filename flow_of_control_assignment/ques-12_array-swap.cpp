/*#####################################
##  
##  To reverse the values of an array
##  
##  By Varad Mahashabde
##  Copyright 2018
##  
#####################################*/

#include <iostream>
#include <string.h>
using namespace std;

int* reverse(int arr[], unsigned int arr_size) {
    int *rev = new int[arr_size];
    if (!rev) {
        cout << "Memory allocation error";
        exit(2);
    }
    for (int i = 0; i < arr_size; ++i) 
        rev[i] = arr[arr_size - (i + 1)];
    return rev;
}

int main() {
    string choice;
    int no_of_elements;
    cout << "Enter no. of elements in integer array : "; cin >> no_of_elements;
    cout << endl;
    
    int arr[no_of_elements], *rev = NULL
    ;
    for (int i = 0; i < no_of_elements; ++i) {
        cout << "Enter element " << i + 1 << " : "; cin >> arr[i];
    }
    
    cout << "Given array = [ " << arr[0];
    for (int i = 1; i < no_of_elements; ++i) 
        cout << ", " << arr[i];
    cout << "]" << endl;
    
    rev = reverse(arr, no_of_elements);
    
    cout << "Reversed array = [ " << *rev;
    for (int i = 1; i < no_of_elements; ++i) 
        cout << ", " << *(rev + i);
    cout << "]" << endl;
    
    while (getchar() !='\n');
    getchar();
}

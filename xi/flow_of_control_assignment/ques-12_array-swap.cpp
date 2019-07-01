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

// int* reverse(int arr[], unsigned int arr_size) {
    // int *rev = new int[arr_size];
    // if (!rev) {
        // cout << "Memory allocation error";
        // exit(2);
    // }
    // for (int i = 0; i < arr_size; ++i) 
        // rev[i] = arr[arr_size - (i + 1)];
    // return rev;
// }

void reverse(int arr[], unsigned int arr_size) {
    for (int i = 0; i < arr_size/2; ++i) {
        arr[i] += arr[arr_size - i - 1];
        arr[arr_size - i - 1] = arr[i] - arr[arr_size - i - 1];
        arr[i] -= arr[arr_size - i - 1];
    }
}

int main() {
    int no_of_elements;
    cout << "Enter no. of elements in integer array : "; cin >> no_of_elements;
    cout << endl;
    
    int arr[no_of_elements];//, *rev = NULL;
    cout << "Enter " << no_of_elements << " elements : ";
    for (int i = 0; i < no_of_elements; ++i) 
        cin >> arr[i];
    
    cout << "Given array = [";
    for (int i = 0; i < no_of_elements; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b]" << endl;
    
    //rev = 
    reverse(arr, no_of_elements);
    
    cout << "Reversed array = [";
    for (int i = 0; i < no_of_elements; ++i) 
        cout << arr[i] << ", ";
    cout << "\b\b]" << endl;
    
    while (getchar() !='\n');
    getchar();
}

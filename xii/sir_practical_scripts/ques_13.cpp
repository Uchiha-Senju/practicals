#include <iostream>
#include <limits>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int strcmp(const char* str1, const char* str2) {
  for (int i = 0; /*str[i] != '\0' and str2[i] != '\0'*/; ++i) {
    if (str1[i] > str2[i])
      return 1;
    else if (str1[i] < str2[i])
      return -1;
    else if (str1[i] == '\0' /*and str2[i] == '\0'*/)
      return 0;
  }
  // switch( 2*(str1[i] == '\0') + str2[i] == '\0' ) {
    // case 0 : // not posible, missed something
      // return str1 < str2;
      // break;
    // case 1 : // str1 longer than str2
      // return false;
    // case 2 : // str1 shorter than str2
      // return true;
    // case 3 : // equivalence
      // return false;
  // }
}

char* strcpy(char* str1, char* str2) {
  int i;
  for (i = 0; str2[i] != '\0'; ++i)
    str1[i] = str2[i];
  str1[i] = '\0';
  return str2;
}

template <typename arr_type>
void quick_sort(arr_type* arr, int start, int end, bool descending = false) {
  if (end - start <= 1 or start < 0) return;
  int pivot_point = end - 1; // default pivot location
  int pivot_location = start; // initial location of pivot
  arr_type temp; // for swapping
  
  //partition array into two halves based on the pivot number
  for (int i = start; i < end - 1; ++i) {
    if (descending ^ (arr[i] < arr[pivot_point]) ) {
      // swap i and pivot_location
      temp = arr[pivot_location];
      arr[pivot_location] = arr[i];
      arr[i] = temp;
      pivot_location++;
    }
  }
  
  // put pivot in it's place
  temp = arr[pivot_point];
  arr[pivot_point] = arr[pivot_location];
  arr[pivot_location] = temp;
  
  quick_sort(arr, start, pivot_location, descending);
  quick_sort(arr, pivot_location + 1, end, descending);
  return;
}

// template <> quick_sort<char*>
void quick_sort(char** arr, int start, int end, bool descending = false) {
  if (end - start <= 1 or start < 0) return;
  int pivot_point = end - 1; // default pivot location
  int pivot_location = start; // initial location of pivot
  char* temp; // for swapping
  
  //partition array into two halves based on the pivot number
  for (int i = start; i < end - 1; ++i) {
    if (descending ^ (strcmp(arr[i], arr[pivot_point]) == -1) ) {
      // swap i and pivot_location
      temp = arr[pivot_location];
      arr[pivot_location] = arr[i];
      arr[i] = temp;
      pivot_location++;
    }
  }
  
  // put pivot in it's place
  temp = arr[pivot_point];
  arr[pivot_point] = arr[pivot_location];
  arr[pivot_location] = temp;
  
  quick_sort(arr, start, pivot_location, descending);
  quick_sort(arr, pivot_location + 1, end, descending);
  return;
}

int main () {
  // srand(time(nullptr));
  
  // int arr[10];
  // for (int i = 0; i < 10; ++i) 
    // arr[i] = rand();
  
  // cout << "Random array : ";
  // for (int i = 0; i < 10; ++i) 
    // cout << arr[i] << ' ';
  // cout << "\n\n";
  
  // quick_sort<int>(arr, 0, 10, false);
  
  // cout << "Sorted array : ";
  // for (int i = 0; i < 10; ++i) 
    // cout << arr[i] << ' ';
  // cout << "\n\n";
  
  unsigned int no_of_elements, choice;
  cout << "Give array datatype : \n"
       << "int : 1\n"
       << "float : 2\n"
       << "char : 3\n"
       << "string : 4\n";
  cin >> choice;
  cout << "Give no. of elements in array : "; cin >> no_of_elements;
  
  choice = (choice - 1) % 4 + 1;
  
  if (choice == 1) {
    int* arr = new int[no_of_elements];
    
    cout << "Input array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cin >> arr[i];
    
    quick_sort<int>(arr, 0, no_of_elements, false);
    
    cout << "Sorted array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cout << arr[i] << " ";
  } else if (choice == 2) {
    float* arr = new float[no_of_elements];
    
    cout << "Input array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cin >> arr[i];
    
    quick_sort<float>(arr, 0, no_of_elements, false);
    
    cout << "Sorted array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cout << arr[i] << " ";
  } else if (choice == 3) {
    char* arr = new char[no_of_elements];
    
    cout << "Input array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cin >> arr[i];
    
    quick_sort<char>(arr, 0, no_of_elements, false);
    
    cout << "Sorted array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cout << arr[i] << " ";
  } else if (choice == 4) {
    char** arr = new char*[no_of_elements];
    int max_str_size;
    cout << "Maximum length of a string : "; cin >> max_str_size;
    for (int i = 0; i < no_of_elements; ++i)
      arr[i] = new char[max_str_size + 1];
    
    cin.ignore(1e5, '\n');
    cout << "Input array : ";
    for (int i = 0; i < no_of_elements; ++i)  
      cin.getline(arr[i], max_str_size + 1, '\n');
    
    quick_sort(arr, 0, no_of_elements, false);
    
    cout << "Sorted array : ";
    for (int i = 0; i < no_of_elements; ++i) 
      cout << arr[i] << " ";
  }
  
  while (getchar() != '\n');
  getchar();
  
  return 0;
}

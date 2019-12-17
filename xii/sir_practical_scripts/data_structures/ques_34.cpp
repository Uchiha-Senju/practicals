#include <iostream>
using namespace std;

int main() {
  int arr_size, *arr, **arr_2d;
  
  cout << "Enter array size : "; cin >> arr_size;
  arr = new int[arr_size];
  cout << "Enter array elements : "; for (int i = 0; i < arr_size; ++i) cin >> arr[i];
  
  arr_2d = new int*[arr_size];
  for (int i = 0; i < arr_size; ++i)
    arr_2d[i] = new int[arr_size];
  
  for (int i = 0; i < arr_size; ++i)
    for (int j = 0; j < arr_size; ++j)
      arr_2d[i][j] = (i + j < arr_size) ? arr[j] : 0;
  
  cout << "\n\nResultant 2d array : ";  
  for (int i = 0; i < arr_size; ++i) {
    cout << "\n ";
    for (int j = 0; j < arr_size; ++j)
      cout << ' ' << arr_2d[i][j];
  }
  cout << "\n\n";
  
  while (getchar() != '\n');
  getchar();
}
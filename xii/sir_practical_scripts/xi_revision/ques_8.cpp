#include <iostream>
using namespace std;

void swap(int arr[], int i_1, int i_2) {
  int temp = arr[i_1];
  arr[i_1] = arr[i_2];
  arr[i_2] = temp;
}

int main() {
  unsigned int arr_size;
  cout << "Array size? "; cin >> arr_size;
  int arr[arr_size];
  cout << "Array : "; for (int i = 0; i < arr_size; ++i) cin >> arr[i];

  for (int i = 0, j = arr_size/2 + arr_size % 2; j < arr_size; i++, j++) {\
    swap(arr, i , j);
  }

  cout << "\n\nSwapped Array : "; for (int i = 0; i < arr_size; ++i) cout << arr[i] << ' ';
  
  while (getchar() != '\n');
  getchar();
}

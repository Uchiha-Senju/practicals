#include <iostream>
using namespace std;

void quickSort(int* arr, int end, bool descending = false, int start = 0) {  
  if (end - start <= 1)
    return;
  
  int pivotPosition = start, temp;
  
  for (int i = start; i < end - 1; ++i) {
    if (arr[i] < arr[end - 1] xor descending) {
      temp = arr[i];
      arr[i] = arr[pivotPosition];
      arr[pivotPosition] = temp;
      pivotPosition++;
    }
  }
  
  temp = arr[end - 1];
  arr[end - 1] = arr[pivotPosition];
  arr[pivotPosition] = temp;
      
  quickSort(arr, pivotPosition, descending, start);
  quickSort(arr, end, descending, pivotPosition + 1);
}

int main() {
  unsigned int arr1_size, arr2_size;
  int *arr1, *arr2, *arr3;
  
  cout << "Enter size of array 1 : "; cin >> arr1_size;
  arr1 = new int[arr1_size];
  cout << "Enter Array 1 elements : "; for (int i = 0; i < arr1_size; ++i) cin >> arr1[i];
  
  cout << "Enter size of array 2 : "; cin >> arr2_size;
  arr2 = new int[arr2_size];
  cout << "Enter Array 2 elements : "; for (int i = 0; i < arr2_size; ++i) cin >> arr2[i];
  
  quickSort(arr1, arr1_size, false);
  quickSort(arr2, arr2_size, true);
  
  cout << "\n\nSorted Array 1 : [";
  for (int i = 0; i < arr1_size - 1; ++i) cout << arr1[i] << ", "; cout << arr1[arr1_size - 1] << "]\n";
  cout << "\n\nSorted Array 2 : [";
  for (int i = 0; i < arr2_size - 1; ++i) cout << arr2[i] << ", "; cout << arr2[arr2_size - 1] << "]\n";
  
  { // Merge arr1 and arr2
    arr3 = new int[arr1_size + arr2_size];
    int i, j, k;
    for (i = 0, j = arr2_size - 1, k = 0; i < arr1_size and j > -1; ++k)
      arr3[k] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j--];
    if (i == arr1_size)
      for (;j > -1; ++k, --j)
        arr3[k] = arr2[j];
    else 
      for (;i < arr1_size; ++k, ++i)
        arr3[k] = arr1[i];
  }
    
  cout << "\n\nMerger Array : [";
  for (int i = 0; i < arr1_size + arr2_size - 1; ++i) cout << arr3[i] << ", "; cout << arr3[arr1_size + arr2_size - 1] << "]\n";
  
  while (getchar() != '\n');
  getchar();
}
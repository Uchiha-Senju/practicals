#include <iostream>
using namespace std;


int main() {
  int size_arr, no_of_duplicates = 0;
  cout << "Give size of array : "; cin >> size_arr;
  int arr[size_arr];
  bool arr_tracker[size_arr];
  for (int i = 0; i < size_arr; ++i)
    arr_tracker[i] = true;

  // Get input
  cout << "Enter array : ";
  for (int i = 0; i < size_arr; ++i)
    cin >> arr[i];


  cout << "\nOriginal Array          : ";
  for (int i = 0; i < size_arr; ++i)
    cout << arr[i] << ' ';
  cout << '\n';
  // cout << "\nOriginal Array (shadow) : ";
  // for (int i = 0; i < size_arr; ++i)
    // cout << arr_tracker[i] << ' ';
  // cout << '\n';

  // Mark and remove them all duplicate entries
  for (int i = 0; i < size_arr; ++i) {
    int in_focus = arr[i];
    for (int j = i + 1; j < size_arr; ++j)
      if (arr[j] == in_focus) {
        arr_tracker[j] = false;
        no_of_duplicates++;
      }
  }

  // cout << "\nduplicate-removed Array          : ";
  // for (int i = 0; i < size_arr; ++i)
    // cout << arr[i] << ' ';
  // cout << '\n';
  // cout << "\nduplicate-removed Array (shadow) : ";
  // for (int i = 0; i < size_arr; ++i)
    // cout << arr_tracker[i] << ' ';
  // cout << '\n';

  for (int i = 0, j; i < size_arr - 1; ++i) {
    if (arr_tracker[i] == false) {
      // find next non-duplicate entry
      j = i + 1;
      while (j < size_arr) {
        if(arr_tracker[j] == true)
          break;
        else j++;
      }
      // No need  to cintinue if is all duplcates till the end of the array
      if (j == size_arr) break;
      
      // Swap values
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      // Swap duplication status
      arr_tracker[i] = true;
      arr_tracker[j] = false;
      
      // cout << "\nFinal Array          : ";
      // for (int i = 0; i < size_arr; ++i)
        // cout << arr[i] << ' ';
      // cout << '\n';
      // cout << "\nFinal Array (shadow) : ";
      // for (int i = 0; i < size_arr; ++i)
        // cout << arr_tracker[i] << ' ';
      // cout << '\n';
    }
  }
  cout << "\nFinal Array          : ";
  for (int i = 0; i < size_arr - no_of_duplicates; ++i)
    cout << arr[i] << ' ';
  cout << '\n';
  // cout << "\nFinal Array (shadow) : ";
  // for (int i = 0; i < size_arr  - no_of_duplicates; ++i)
    // cout << arr_tracker[i] << ' ';
  // cout << '\n';

  while(getchar() != '\n');
  getchar();  
}

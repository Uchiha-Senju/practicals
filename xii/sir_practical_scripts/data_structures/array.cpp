#include <iostream>

class Array {
  const unsigned int size;
  unsigned int length;
  int* const arr;
  
  public :
    int operator[](unsigned int index) {
      if (index >= length) 
        return 0;
      return arr[index];
    }
    Array() : size(0), arr(nullptr) { length = 0;}
    Array(unsigned arr_size) : size(arr_size), arr(new int[size]) {
      length = 0;
      if (arr == nullptr) 
        new(this) Array();
    }
    
    unsigned int len() {return length;}
    void display(std::ostream& out_stream) {
      out_stream << '[';
      if (length != 0)
        out_stream << arr[0];
      for (int i = 1; i < length; ++i)
        out_stream << ", " << arr[i];
      out_stream << ']';
    }
    bool append(int value) {
      if (length >= size) {
        length = size;
        return false;
      }
      arr[length] = value;
      ++length;
      return true;
    }
    bool insert(int value, int index) {
      if (index < 0)
        index = length + index;
      if (index == length) 
        return append(value);
      else if (index > length or index < 0)
        return false;
      for (int i = length; i > index; --i) 
        arr[i] = arr[i - 1];
      arr[index] = value;
      ++length;
      return true;
    }
    bool remove(unsigned int index) {
      if (index < 0)
        index = length - index;
      if (index >= length or index < 0)
        return false;
      for (int i = index; i < length - 1; ++i)
        arr[i] = arr[i + 1];
      --length;
      return true;
    }
    void selectionSort(bool ascending = true) {
      for (int i = length - 1; i > 0; --i) {
        int max_index = 0;
        for (int j = 0; j <= i; ++j)
          if (ascending and arr[j] > arr[max_index] or not ascending and arr[j] < arr[max_index])
            max_index = j;
        int temp = arr[max_index];
        arr[max_index] = arr[i];
        arr[i] = temp;
      }
    }
    void insertionSort(bool ascending = true) {
      for (int i = 1; i < length; ++i) {
        int temp = arr[i], j;
        for (j = i - 1; ascending and arr[j] < temp or not ascending and arr[j] > temp; --j)
          arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
    void bubbleSort(bool ascending = true) {
      for (bool have_swapped = false; have_swapped; have_swapped = false) {
        for (int j = 0; j < length - 1; ++j) {
          if (ascending and arr[j] > arr[j+1] or not ascending and arr[j] < arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            have_swapped = true;
          }
        }
      }
    }
    int linearSearch(int value) {
      for (int i = 0; i < length; ++i) 
        if (arr[i] == value)
          return i;
      return -1;
    }
    int binarySearch(int value) {
      unsigned int lower_bound = 0, upper_bound = length, mid = (lower_bound + upper_bound) / 2;
      bubbleSort(true);
      while (upper_bound - lower_bound > 1) {
        if (arr[mid] > value)
          upper_bound = mid;
        else if (arr[mid] < value)
          lower_bound = mid + 1;
        else 
          return mid;
        mid = (lower_bound + upper_bound) / 2;
      }
      if (upper_bound <= lower_bound)
        return -1;
    }
};
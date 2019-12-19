#include <iostream>
using namespace std;

template <typename T = int>
class StackWithArray {
  T* arr;
  const int size;
  int top;
  
  public :
    StackWithArray() : size(0), arr(nullptr), top(0) {}
    StackWithArray(int stack_size) : size(stack_size), top(0) {
      arr = new T[size];
    }
    StackWithArray(int stack_size, T* old_arr) : StackWithArray(stack_size) {
      top = size;
      for (int i = 0; i < size; ++i)
        arr[i] = old_arr[i];
    }
    StackWithArray(const StackWithArray<T>& old_swa) : StackWithArray(old_swa.size, old_swa.arr) {
      top = old_swa.top;
    }
    
    T pop() {
      if (top == 0)
        return T();
      return arr[--top];
    }
    bool push(const T& new_data) {
      if (top == size)
        return false;
      return arr[top++] = new_data, true;
    }
    T peek() {
      if (top == 0)
        return T();
      return arr[top - 1];
    }
    void display(ostream& out_stream) {
      out_stream << '[';
      for (int i = 0; i < top - 1; ++i)
        out_stream << arr[i] << ", ";
      if (top != 0)
        out_stream << arr[top - 1];
      out_stream << ']';
    }
    int max_size() {return size;}
    int current_size() {return top;}
};

int main () {
  int size;
  char choice;
  
  cout << "Enter stack size : "; cin >> size;
  StackWithArray<int> stack(size);
  
  do {
    cout << "\n\nEnter your choice : "
         << "\n\tu - Push to stack"
         << "\n\to - Pop from stack"
         << "\n\te - Peek on the stack"
         << "\n\td - Display stack"
         << "\n\ts - Get current size of stack"
         << "\n\tq - Quit"
         << "\nWhat is your choice? ";
    cin >> choice;
    
    switch(choice) {
      case 'u' : case 'U' :
        int temp;
        cout << "\nEnter integer value : "; cin >> temp;
        if(not stack.push(temp))
          cout << "AllocationError : Stack is full";
        break;
      
      case 'o' : case 'O' :
        cout << "\nValue that was on the stack : " << stack.pop();
        break;
      
      case 'e' : case 'E' :
        cout << "\nValue that is on the stacl : " << stack.peek();
        break;
      
      case 'd' : case 'D' :
        cout << "\nStack contents : "; stack.display(cout);
        break;
      
      case 's' : case 'S' :
        cout << "\nCurrent size of stack : " << stack.current_size();
        break;
        
      case 'q' : case 'Q' : break;
      
      default :
        cout << "\nInvalid option. Please try sgain";
        break;
    }
  } while (choice != 'q' and choice != 'Q');
  cout << "\nBYE!";
}
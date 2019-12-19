#include <iostream>
using namespace std;

template <typename T = int>
class QueueWithArray {
  T* arr;
  const int length;
  int top;
  int tail;
  
  public :
    QueueWithArray() : length(0), arr(nullptr), top(0), tail(0) {}
    QueueWithArray(int queue_length) : length(queue_length), top(-1), tail(-1) {
      arr = new T[length];
    }
    QueueWithArray(int queue_length, T* old_arr) : QueueWithArray(queue_length) {
      tail = top = 0;
      for (int i = 0; i < length; ++i)
        arr[i] = old_arr[i];
    }
    QueueWithArray(const QueueWithArray<T>& old_qwa) : QueueWithArray(old_qwa.length, old_qwa.arr) {
      top = old_qwa.top;
      tail = old_qwa.tail;
    }
    
    T pop() {
      if (top == -1)
        return T();
      int old_first = top;
      top = (top + 1) % length;
      if (top == tail)
        top = (tail = -1);
      return arr[old_first]; 
    }
    bool append(const T& new_data) {
      if (tail == -1)
        return (tail = 1), (top = 0), arr[0] = new_data, true;
      if (tail == top)
        return false;
      arr[tail] = new_data;
      tail = (tail + 1) % length;
      return true; 
    }
    T peek() {
      if (top == -1)
        return T();
      return arr[top];
    }
    void display(ostream& out_stream) {
      out_stream << '[';
      if (tail != -1) {
        for (int i = top; i < tail + length - 1; ++i)
          out_stream << arr[i % length] << ", ";
        out_stream << arr[(tail + length - 1) % length];
      }
      out_stream << ']';
    }
    int max_length() {return length;}
    int current_length() {
      if (tail == -1)
        return 0;
      if (tail == top) 
        return length;
      return (tail - top + length) % length;
    }
};

int main () {
  int length;
  char choice;
  
  cout << "Enter queue length : "; cin >> length;
  QueueWithArray<int> queue(length);
  
  do {
    cout << "\n\nEnter your choice : "
         << "\n\ta - Append to the tail of the queue"
         << "\n\tp - Pop from the top of the queue"
         << "\n\te - Peek on the top of the queue"
         << "\n\td - Display queue"
         << "\n\ts - Get current length of queue"
         << "\n\tq - Quit"
         << "\nWhat is your choice? ";
    cin >> choice;
    
    switch(choice) {
      case 'a' : case 'A' :
        int temp;
        cout << "\nEnter integer value : "; cin >> temp;
        if(not queue.append(temp))
          cout << "AllocationError : Queue is full";
        break;
      
      case 'p' : case 'P' :
        cout << "\nValue that was on the queue : " << queue.pop();
        break;
      
      case 'e' : case 'E' :
        cout << "\nValue that is on the queue : " << queue.peek();
        break;
      
      case 'd' : case 'D' :
        cout << "\nQueue contents : "; queue.display(cout);
        break;
      
      case 's' : case 'S' :
        cout << "\nCurrent length of queue : " << queue.current_length();
        break;
        
      case 'q' : case 'Q' : break;
      
      default :
        cout << "\nInvalid option. Please try sgain";
        break;
    }
  } while (choice != 'q' and choice != 'Q');
  cout << "\nBYE!";
}
#include <iostream>
using namespace std;

template <typename T = int>
class LinkedQueue {
  struct Node {
    T data;
    Node* previous;
    Node* next;
    
    Node() : data(), previous(nullptr), next(nullptr) {}
    Node(T& new_data, Node* prev = nullptr, Node* nxt = nullptr) : data(new_data), previous(prev), next(nxt) {}
    ~Node() {
      previous = next = nullptr;
      data.~T();
    }
    
    Node* makeNext(T& new_data) {
      Node* new_next = new Node(new_data, this);
      if (new_next != nullptr)
        next = new_next;
      return new_next;
    }
  };
  
  Node* top;
  Node* tail;
  
  public :
    LinkedQueue() : top(nullptr), tail(nullptr) {}
    LinkedQueue(int queue_length, T* old_arr) {
      tail = top = new Node(old_arr[0]);
      for (int i = 1; i < queue_length; ++i)
        tail = tail->makeNext(old_arr[i]);
    }
    LinkedQueue(LinkedQueue<T>& old_lq) {
      Node* leach_point = old_lq.top;
      tail = top = new Node(leach_point->data);
      leach_point = leach_point->next;
      while (leach_point != nullptr) {
        tail = tail->makeNext(leach_point->data);
        leach_point = leach_point->next;
      }
    }
    
    int length() {
      int length = 0;
      Node* read_head = top;
      while (read_head != nullptr) {
        read_head = read_head->next;
        length++;
      }
    }
    T pop() {
      if (top == nullptr)
        return T();
      Node* old_top = top;
      if (top == tail) {
        top = tail = nullptr;
      } else {
        top = top->next;
        top->previous = nullptr;
      }
      return old_top->data;
    }
    bool append(T& new_data) {
      if (tail == nullptr) {
        top = tail = new Node(new_data);
        return tail != nullptr;
      }
      Node* new_tail = tail->makeNext(new_data);
      if (new_tail == nullptr)
        return false;
      tail = new_tail;
      return true;
    }
    T peek() {
      if (tail == nullptr) 
        return T();
      return tail->data;
    }
    bool is_ok() {
      if (top == nullptr)
        return true;
      Node* read_head = top;
      while (read_head != nullptr and read_head != tail)
        read_head = read_head->next;
      if (read_head == nullptr)
        return false;
      return true;
    }
    void display(ostream& out_stream) {
      if (not is_ok()) 
        out_stream << "Queue Corrupted";
      out_stream << '[';
      Node* read_head = top;
      if (read_head != nullptr) {
        out_stream << read_head->data;
        read_head = read_head->next;
        while (read_head != nullptr) {
          out_stream << ", " << read_head->data;
          read_head = read_head->next;
        }
      }
      out_stream << ']';
    }
};

int main () {
  char choice;
  
  LinkedQueue<int> queue;
  
  do {
    cout << "\n\nEnter your choice : "
         << "\n\tu - Place at the tail of the queue"
         << "\n\to - Pop from the top of the queue"
         << "\n\te - Peek on the top of the queue"
         << "\n\td - Display queue"
         << "\n\ts - Get current length of queue"
         << "\n\tq - Quit"
         << "\nWhat is your choice? ";
    cin >> choice;
    
    switch(choice) {
      case 'u' : case 'U' :
        int temp;
        cout << "\nEnter integer value : "; cin >> temp;
        if(not queue.append(temp))
          cout << "AllocationError : Queue is unable to allocate for more data";
        break;
      
      case 'o' : case 'O' :
        cout << "\nValue that was on the queue : " << queue.pop();
        break;
      
      case 'e' : case 'E' :
        cout << "\nValue that is on the queue : " << queue.peek();
        break;
      
      case 'd' : case 'D' :
        cout << "\nStack contents : "; queue.display(cout);
        break;
      
      case 's' : case 'S' :
        cout << "\nCurrent length of queue : " << queue.length();
        break;
        
      case 'q' : case 'Q' : break;
      
      default :
        cout << "\nInvalid option. Please try sgain";
        break;
    }
  } while (choice != 'q' and choice != 'Q');
  cout << "\nBYE!";
}
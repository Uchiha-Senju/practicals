#include <iostream>
using namespace std;

template <typename T = int>
class LinkedStack {
  struct Node {
    T data;
    Node* previous;
    Node* next;
    
    Node() : data(), previous(nullptr), next(nullptr) {}
    Node(const T& new_data, Node* prev = nullptr, Node* nxt = nullptr) : data(new_data), previous(prev), next(nxt) {}
    ~Node() {
      previous = next = nullptr;
      data.~T();
    }
    
    Node* makeNext(const T& new_data) {
      Node* new_next = new Node(new_data, this);
      if (new_next != nullptr)
        next = new_next;
      return new_next;
    }
  };
  
  Node* top;
  Node* bottom;
  
  public :
    LinkedStack() : top(nullptr), bottom(nullptr) {}
    LinkedStack(int stack_size, T* old_arr) {
      bottom = top = new Node(old_arr[0]);
      for (int i = 1; i < stack_size; ++i)
        top = top->makeNext(old_arr[i]);
    }
    LinkedStack(const LinkedStack<T>& old_ls) {
      Node* leach_point = old_ls.top;
      bottom = top = new Node(leach_point->data);
      leach_point = leach_point->next;
      while (leach_point != nullptr) {
        bottom = bottom->makeNext(leach_point->data);
        leach_point = leach_point->next;
      }
    }
    
    bool isEmpty() {
      return top == nullptr;
    }
    int size() {
      int size = 0;
      Node* read_head = bottom;
      while (read_head != nullptr)
        read_head = read_head->next, size++;
      return size;
    }
    T pop() {
      if (top == nullptr)
        return T();
      Node* old_top = top;
      if (top == bottom) {
        top = bottom = nullptr;
      } else {
        top = top->previous;
        top->next = nullptr;
      }
      return old_top->data;
    }
    bool push(const T& new_data) {
      if (top == nullptr) {
        top = bottom = new Node(new_data);
        return top != nullptr;
      }
      Node* new_top = top->makeNext(new_data);
      if (new_top == nullptr)
        return false;
      top = new_top;
      return true;
    }
    T peek() {
      if (top == nullptr) 
        return T();
      return top->data;
    }
    bool isOk() {
      if (bottom == nullptr)
        return true;
      Node* read_head = bottom;
      while (read_head != nullptr and read_head != top)
        read_head = read_head->next;
      if (read_head == nullptr)
        return false;
      return true;
    }
    void display(ostream& out_stream) {
      if (not isOk())
        out_stream << "Stack Corrupted";
      Node* read_head = bottom;
      out_stream << '[';
      if (bottom != nullptr) {
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

int main() {
  long long number, smol_factor;
  LinkedStack<long long> factors;
  
  cout << "\nRange : [-2^63, 2^63 - 1] ~= [-9.22 quintillion, 9.22 quintillion]";
  cout << "\nEnter number to be factorized : "; cin >> number;
  /*cout << "Got number " << number << '\n';*/
  
  if (number < 0) {
    factors.push(-1);
    number *= -1;
  } else
    factors.push(1);
  while (number > 1) {
    for (smol_factor = 2 ; number % smol_factor != 0; ++smol_factor);
    number /= smol_factor;
    factors.push(smol_factor);
  }
  
  cout << "Factorization = " << factors.pop();
  while(not factors.isEmpty()) cout << " x " << factors.pop();
  
  while(getchar() != '\n');
  getchar();
}

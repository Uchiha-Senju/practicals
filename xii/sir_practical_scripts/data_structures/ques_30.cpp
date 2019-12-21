#include <iostream>
#include <iomanip>
#include <limits>
#include <string.h>
using namespace std;

class Student {
  public :
    char Name[50];
    unsigned int Roll_no;
    
    Student() {}
    void copy(const Student& stu) {
      int i;
      for (i = 0; stu.Name[i] != '\0' and  i < 50; ++i) {
        Name[i] = stu.Name[i];
      }
      Name[i] = '\0';
      Roll_no = stu.Roll_no;
    }
    Student(const Student& stu) {
      copy(stu);
    }
    Student& operator=(const Student& stu) {
      copy(stu);
      return *this;
    }
    
    void display(ostream& out_stream) {
      out_stream << "\tName : " << Name << '\n';
      out_stream << "\tRoll no. : " << Roll_no << '\n';
    }
    void getData(istream& in_stream, ostream& out_stream) {
      out_stream << "\tName : "; 
      in_stream.ignore(std::numeric_limits<streamsize>::max(), '\n');
      in_stream.getline(Name, 50);
      out_stream << "\tRoll no. : "; in_stream >> Roll_no;
    }
};

class Functor {
  public :
    virtual bool operator()(Student&, Student&) = 0;
};

class NameComp : public Functor {
  public :
    bool operator()(Student& a, Student& b) {
      return strcmp(a.Name, b.Name) < 0;
    }
};

class RollComp : public Functor {
  public :
    bool operator()(Student& a, Student& b) {
      return a.Roll_no < b.Roll_no;
    }
};


class LinkedList {
  class Node {
    public :
      Student student;
      Node* next;
      Node* previous;
      const int check;
      
      Node(const Student& stu, Node* prev) : check(0x1234abcd) {
        student = stu;
        next = nullptr;
        previous = prev;
      }
      Node(Node* prev) : check(0x1234abcd) {
        next = nullptr;
        previous = prev;
      }
      Node* makeNext(const Student& stu) {
        Node* new_next = new Node(stu, this);
        if (new_next != nullptr) next = new_next;
        return new_next;
      }
      Node* makeNext(){
        Node* new_next = new Node(this);
        if (new_next != nullptr) next = new_next;
        return new_next;
      }
  };

  Node* first;
  Node* last;
  unsigned int length;
  
  Node* getNode(int index) {
    if (index < 0) 
      index = index % length + length;
    else
      index = index % length;
    Node* cur;
    if (2 * index < length) {
      cur = first;
      for (int i = 1; i <=index; i++) {
        cur = cur->next;
      }
    } else {
      cur = last;
      for (int i = length - 2; i >= index; i--) {
        cur = cur->previous;
      }
    }
    return cur;
  }
  
  public: 
    LinkedList(unsigned int len) {
      length = len;
      first = new Node(nullptr);
      last = first;
      for (int i = 1; i < length; ++i) {
        last = last->makeNext();
      }
    }
    LinkedList() {
      first = nullptr;
      last = nullptr;
      length = 0;
    }
    
    unsigned int len() {
      return length;
    }
    Student& operator[] (int index) {
      return getNode(index)->student;
    }
    bool append(const Student& stu) {
      if (last == nullptr) {
        last = new Node(stu, nullptr);
        first = last;
        if (last == nullptr)
          return false;
      } else {
        Node* new_last = last->makeNext(stu);
        if (new_last == nullptr) return false;
        last = new_last;
      }
      ++length;
      return true;
    }
    bool prepend(const Student& stu) {
      if (last == nullptr) {
        first = last = new Node(stu, nullptr);
        if (first == nullptr)
          return false;
      } else {
        Node* new_node = new Node(stu, nullptr);
        if (new_node == nullptr)
          return false;
        new_node->next = first;
        first->previous = new_node;
        first = new_node;
      }
      ++length;
      return true;
    }
    void remove(unsigned int index) {
      Node* cur = getNode(index);
      if (cur == nullptr)
        return;
      cur->next->previous = cur->previous;
      cur->previous->next = cur->next;
      delete cur;
      --length;
    }
    bool insert(unsigned int index, const Student& stu) {
      if (index == length) 
        return append(stu);
      else if (index == 0) 
        return prepend(stu);
      
      Node* cur = getNode(index);
      if (cur == nullptr)
        return false;
      Node* new_node = new Node(stu, nullptr);
      if (new_node == nullptr)
        return false;
      
      new_node->next = cur;
      new_node->previous = cur->previous;
      new_node->previous->next = new_node;
      cur->previous = new_node;
      ++length;
    }
    void truncate(unsigned int end) {
      Node* cur = last;
      Node* final_node;
      for (int i = length - 1; i >= end; --i) {
        final_node = cur->previous;
        delete cur;
        cur = final_node;
      }
      final_node->next = nullptr;
      last = final_node;
      length = end;
    }
    void slice(unsigned int start, unsigned int end, unsigned int step = 1) {
      if (start >= end)
        return;
      truncate(end);
      
      Node* cur = first;
      Node* final_node;
      for (int i = 0; i < start; ++i) {
        final_node = cur->next;
        delete cur;
        cur = final_node;
      }
      final_node->previous = nullptr;
      first = final_node;
      length = end - start;
      if (step != 1 or step != 0) {
        for (int i = 0, offset = 0; i < length; ++i) {
          if (i + offset % step != 0) {
            remove(i);
            ++offset; --i;
          }
        }
        length = length / step;
      }
    }
    void swap(unsigned int i_1, unsigned int i_2) {
      Node* temp;
      // Ensure that i_1 <= i_2 
      if (i_1 > i_2) {
        unsigned int temp = i_1;
        i_1 = i_2;
        i_2 = temp;
      }
      if (i_1 == i_2) return;
      Node* node_1 = getNode(i_1);
      Node* node_2 = getNode(i_2);
      if (node_1 == nullptr or node_2 == nullptr) 
        return;
      
      // Check if list markers need to be changed
      if (i_1 == 0)
        first = node_2;
      else if (i_1 == length - 1)
        last = node_2;
      if (i_2 == 0)
        first = node_1;
      else if (i_2 == length - 1)
        last = node_1;
      // Alternate behaviour for adjacent swaps
      if (i_1 + 1 == i_2) {
        node_1->next = node_2->next;
        node_2->previous = node_1->previous;
        
        node_1->previous = node_2;
        node_2->next = node_1;
        
        if (node_1->next != nullptr) node_1->next->previous = node_1;
        if (node_2->previous != nullptr) node_2->previous->next = node_2;
        
        return;
      }
      // Standard swap behaviour
      temp = node_1->previous;
      node_1->previous = node_2->previous;
      node_2->previous = temp;
      
      temp = node_1->next;
      node_1->next = node_2->next;
      node_2->next = temp;
      // Correct neighbours addresses
      if (node_1->next != nullptr) node_1->next->previous = node_1;
      if (node_1->previous != nullptr) node_1->previous->next = node_1;
      
      if (node_2->next != nullptr) node_2->next->previous = node_2;
      if (node_2->previous != nullptr) node_2->previous->next = node_2;
    }
    void sort(Functor& func) {
      class Dummy {
        public : 
          void quickSort(LinkedList& arr, unsigned int start, unsigned int end, Functor& func) {
            if (end - start <= 1) 
              return;
            int pivotIndex = start;
            for (int i = start; i < end - 1; ++i) {
              if (func(arr[i], arr[end - 1])) {
                arr.swap(i, pivotIndex);
                ++pivotIndex;
              }
            }
            arr.swap(pivotIndex, end - 1);
            quickSort(arr, start, pivotIndex, func);
            quickSort(arr, pivotIndex + 1, end, func);
          }
      } dummy_dum_dum;
      dummy_dum_dum.quickSort(*this, 0, length, func);
    }
};

class Records {
  public : 
    LinkedList list;
    Records() : list() {};
    
    void displayRecord(unsigned int index, ostream& out_stream) {
      list[index].display(out_stream);
    }
    void displayAll(ostream& out_stream) {
      out_stream << "\n\n Index                                                Name     Roll no\n";
      out_stream <<     " =====  ==================================================  ==========\n";
      for (int i = 0; i < list.len(); ++i)
        out_stream << " " << setw(5) << i << setw(52) << list[i].Name << setw(12) << list[i].Roll_no << '\n';
      out_stream << "\n\n";
    }
    void sortByName() {
      NameComp dummy_dum;
      list.sort(dummy_dum);
    }
    void sortByRoll() {
      RollComp dummy_dum;
      list.sort(dummy_dum);
    }
};

int main() {
  Records records;
  Student stu;
  unsigned int number;
  char choice;
  do {
    cout << "\n\nEnter choice : ";
    cin >> choice;
    
    switch(choice) {
      case '1' :
        records.displayAll(cout);
        break;
      case '2' :
        cout << "\nInsert at index (0-" << records.list.len() << ") : "; cin >> number;
        cout << "Enter details : \n";
        stu.getData(cin, cout);
        records.list.insert(number, stu);
        break;
      case '3' :
        cout << "\nRemove from index (0-" << records.list.len() - 1 << ") : "; cin >> number;
        records.list.remove(number);
        break;
      case '4' : {
        cout << "\nEnter the name to be searched : ";
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cin.getline(stu.Name, 50);
        bool found = false;
        for (int i = 0; i < records.list.len() and not found; ++i) {
          if (strcmp(stu.Name, records.list[i].Name) == 0) {
            found = true;
            cout << "Index " << i << " : \n";
            records.list[i].display(cout);
          }
        }
        if (not found) {
          cout << "No such record found\n";
        }
        break;
      }
      case '5' : {
        cout << "\nEnter the roll no. to be searched : "; cin >> stu.Roll_no;
        bool found = false;
        for (int i = 0; i < records.list.len() and not found; ++i) {
          if (stu.Roll_no == records.list[i].Roll_no) {
            found = true;
            cout << "Index " << i << " : \n";
            records.list[i].display(cout);
          }
        }
        if (not found) {
          cout << "No such record found\n";
        }
        break;
      }
      case '6' :
        records.sortByName();
        break;
      case '7' :
        records.sortByRoll();
        break;
      case '8' :
        cout << "\t1 - Display Records\n"
             << "\t2 - Insert Record\n"
             << "\t3 - Remove Record\n"
             << "\t4 - Search by Name\n"
             << "\t5 - Search by Roll no.\n"
             << "\t6 - Sort by Name\n"
             << "\t7 - Sort by Roll no.\n"
             << "\t8 - Print this help message\n"
             << "\t9 - Exit\n";
        break;
      case '9' :
        cout << "\tBye\n";
        break;
      default :
        cout << "\tInvalid option, use '8' for help \n\n";
    }
  } while (choice != '9');
}
#if !defined(VARAD_LIST_H_INCLUDED)
  #define VARAD_LIST_H_INCLUDED
  
  namespace list_h {
    const int check_num 0x1234abcd;
    
    template <class T>
    class Functor {
      virtual bool function(T& a, T& b) = 0;
      inline bool operator(T& a, T& b) {
        return function(a, b);
      }
    }
  }
  
  
  template <class T>
  class list {
    class Node {
      public :
        T data;
        Node* next;
        Node* previous;
        const int check;
        
        Node(const T& new_data, Node* prev) : check(list_h::check_num) {
          data = new_data;
          next = nullptr;
          previous = prev;
        }
        Node(Node* prev) : check(list_h::check_num) {
          next = nullptr;
          previous = prev;
        }
        Node(Node& old_node, Node* prev = nullptr) {
          Node(old_node.data, prev)
        }
        ~Node() {
          data.~T();
          next = last = nullptr;
          int* check_overwrite = new int(&check);
          check_overwrite = 0;
        }
        
        bool isOk() {
          return check == list_h::check_num;
        }
        Node* makeNext(const T& new_data) {
          Node* new_next = new Node(new_data, this);
          if (new_next != nullptr) next = new_next;
          return new_next;
        }
        Node* makeNext() {
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
      list(T* data_arr, unsigned int len) {
        length = len;
        first = new Node(data_arr[0]););
        if (first == nullptr)
          return;
        last = first;
        for (int i = 1; i < length; ++i) {
          Node* new_last = last->makeNext(data_arr[i]);
          if (new_last == nullptr)
            i = length;
          else
            last = new_last;
        }
      }
      list(unsigned int len) {
        length = len;
        first = new Node(nullptr);
        if (first == nullptr)
          return;
        last = first;
        for (int i = 1; i < length; ++i) {
          Node* new_last = last->makeNext();
          if (new_last == nullptr)
            i = length;
          else
            last = new_last;
        }
      }
      list() {
        first = nullptr;
        last = nullptr;
        length = 0;
      }
      list(list& old_list) {
        length = list.length;
        if (length != 0) {
          Node* read_head = old_list.first;
          last = first = new Node(*read_head, nullptr);
          if (first == nullptr)
            return;
          read_head = read_head->next;
          while (read_head != nullptr) {
            Node* new_last = last->makeNext(read_head->data);
            if (new_last == nullptr)
              read_head = nullptr;
            else 
              last = new_last;
          }
        } else {
          first = last = nullptr;
        }
      }
      ~list() {
        if (length != 0) {
          length = 0;
          Node* read_head = first->next;
          first.~Node(); delete first;
          while (read_head != nullptr) {
            first = read_head; read_head = read_head->next;
            first.~Node(); delete first;
          }
          first = last = nullptr;
        }
      }
      
      class Iterator() {
        const list& parent_list;
        Node* current;
        public :
          int position;
                
          Iterator first() {
            current = parent_list.first;
            position = 0
          }
          Iterator last() {
            current = parent_list.last;
            position = length - 1
          }
          bool hasEnded() {
            return current == nullptr or position >= length or position < 0;
          }
          bool operator==(Node* node) {
            return current == node;
          }
          bool operator==(Iterator& i) {
            return current == i.current;
          }
          bool operator!=(Node* node) {
            return not current == node;
          }
          bool operator!=(Iterator& i) {
            return not current == i.current;
          }
          Iterator& operator++() {
            current = current->next;
            return *this;
          }
          Iterator& operator--() {
            current = current->prev;
            return *this;
          }
          Iterator& operator+(int i) {
            Iterator new_iterator(*this);
            if (i < 0)
              for(; i < 0; i++)
                new_iterator--;
            else (i > 0)
              for(; i > 0; i--)
                new_iterator++;
            return new_iterator;
          }
          Iterator& operator-(int i) {
            return *this + (-i);
          }
          
          
          T& operator() {
            return current->data;
          }
          
          Iterator(list& papa, bool start_at_first = true) : parent_list(papa) {
            if (start_at_first)
              first();
            else 
              last();
          };
          Iterator(Iterator& i) : parent_list(i.parent_list), current(i.current), position(i.position) {}
          Iterator& operator=(Iterator& i) {
            if (&parent_list == &(i.parent_list)) {
              current = i.current;
              position = i.position;
            }
            return *this;
          }
      }
      
      unsigned int len() {
        return length;
      }
      T& operator[] (int index) {
        return getNode(index)->data;
      }
      bool append(const T& new_data) {
        if (last == nullptr) {
          last = new Node(new_data, nullptr);
          first = last;
          if (last == nullptr)
            return false;
        } else {
          Node* new_last = last->makeNext(new_data);
          if (new_last == nullptr) return false;
          last = new_last;
        }
        ++length;
        return true;
      }
      bool prepend(const T& new_data) {
        if (last == nullptr) {
          first = last = new Node(new_data, nullptr);
          if (first == nullptr)
            return false;
        } else {
          Node* new_node = new Node(new_data, nullptr);
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
      bool insert(unsigned int index, const T& new_data) {
        if (index == length) 
          return append(new_data);
        else if (index == 0) 
          return prepend(new_data);
        
        Node* cur = getNode(index);
        if (cur == nullptr)
          return false;
        Node* new_node = new Node(new_data, nullptr);
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
            void quickSort(LinkedList& arr, unsigned int start, unsigned int end, list_h::Functor<T>& func) {
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
      int includes(T& search_data) {
        for (Iterator i(*this); not i.hasEnded(); i++) 
          if (i() == search_data and i.position < length)
            return position;
        
        return -1;
      }
  };
#endif
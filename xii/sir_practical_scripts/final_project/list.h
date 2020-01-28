#if !defined(VARAD_LIST_H_INCLUDED)
  #define VARAD_LIST_H_INCLUDED
  
  namespace list_h {
    const int check_num = 0x1234abcd;
    
    // Make type const if it is a pointer
    template <class T>
    struct AddConstToType {
      typedef T type;
    };
    template <class T>
    struct AddConstToType<T*> {
      typedef const T* type;
    };
    
    template <class T>
    class BinaryFunctor {
      public :
        virtual bool function(const typename AddConstToType<T>::type& a, const typename AddConstToType<T>::type& b) const = 0;
        inline bool operator()(const typename AddConstToType<T>::type& a, const typename AddConstToType<T>::type& b) const {
          return function(a, b);
        }
    };
  }
  
  
  template <class T>
  class List {
    protected :
      class Node {
        public :
          T data;
          Node* next;
          Node* previous;
          const int check;
          
          Node() : check(list_h::check_num) {}
          // Weird cast of const T new_data to T so that it can be copied to data
          Node(const typename list_h::AddConstToType<T>::type& new_data, Node* prev, Node* nxt = nullptr)
            : check(list_h::check_num), data((T)new_data), previous(prev), next(nxt) {}
          Node(Node* prev) : check(list_h::check_num), previous(prev), next(nullptr) {}
          Node(const Node& old_node, Node* prev = nullptr) : Node(old_node.data, prev) {}
          ~Node() {
            data.~T();
            next = previous = nullptr;
          }
          
          bool isOk() const {
            return check == list_h::check_num;
          }
          Node* makeNext(const typename list_h::AddConstToType<T>::type& new_data) {
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
      
      Node* getNode(int index) const {
        if (length == 0)
          index = 0;
        else if (index < 0)
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
      
      void reCalculateLength() {
        length = 0;
        for(Node* read_head = first; read_head != nullptr; read_head = read_head->next, ++length);
      }
      
    public: 
      class Iterator {
        friend class List;
        
        const List& parent_list;
        Node* current;
        
        public :
          int position;

        private :
          // Custom Constructor for exact copying
          Iterator(const List& pops, Node* cur, int pos) : parent_list(pops), current(cur), position(pos) {}
        
        public :
          // Basic functions
          void first() {
            current = parent_list.first;
            position = 0;
          }
          void last() {
            current = parent_list.last;
            position = parent_list.length - 1;
          }          
          Iterator(const List& papa, bool start_at_first = true) : parent_list(papa) {
            if (start_at_first)
              first();
            else 
              last();
          };
          // Constructors
          Iterator(const Iterator& i) : parent_list(i.parent_list), current(i.current), position(i.position) {}
          Iterator& operator=(const Iterator& i) {
            if (&parent_list == &(i.parent_list)) {
              current = i.current;
              position = i.position;
            }/* else {
              ~Iterator();
              new(this) Iterator(i);
            }*/
            return *this;
          }
        
          bool hasEnded() const {
            return current == nullptr or position >= parent_list.length or position < 0;
          }
          bool operator==(const Node* const node) const {
            return current == node;
          }
          bool operator==(const Iterator& i) const {
            return current == i.current;
          }
          bool operator!=(const Node* const node) const {
            return not current == node;
          }
          bool operator!=(const Iterator& i) const {
            return not current == i.current;
          }
          Iterator& operator++() {
            if (current != nullptr) current = current->next;
            ++position;
            return *this;
          }
          Iterator& operator++(int) {
            return ++(*this);
          }
          inline Iterator& operator--() {
            if (current != nullptr) current = current->previous;
            --position;
            return *this;
          }
          inline Iterator& operator--(int) {
            return --(*this);
          }
          Iterator operator+(int index) {
            Node* new_current = current;
            if (index < 0)
              for(int i = index; i < 0; i++) {
                new_current = new_current->previous;
                if (new_current == nullptr)
                  break;
              }
            else 
              for (int i = index; i > 0; i--) {
                new_current = new_current->next;
                if (new_current == nullptr)
                  break;
              }
            return Iterator(parent_list, new_current, position + index);
          }
          inline Iterator operator-(int i) {
            return *this + (-i);
          }
          
          T& operator()() const {
            return current->data;
          }
      };
      // Basic Functions
      inline unsigned int len() const {
        return length;
      }
      T& operator[] (int index) const {
        return getNode(index)->data;
      }
      bool append(const typename list_h::AddConstToType<T>::type& new_data) {
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
      bool prepend(const typename list_h::AddConstToType<T>::type& new_data) {
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
    private :
      void removeByPointer(Node* node) {
        if (node == nullptr)
          return;
        // Neighbour management
        if (node->next != nullptr) node->next->previous = node->previous;
        if (node->previous != nullptr) node->previous->next = node->next;
        // Boundary conditions
        if (node == first)
          first = node->next;
        if (node == last)
          last = node->previous;
        // Guillotine
        delete node;
        --length;
      }
    public :
      void remove(unsigned int index) {
        removeByPointer(getNode(index));
      }
      void remove(Iterator iter) {
        if (not iter.hasEnded())
          removeByPointer(iter.current);
      }
      // Constructors
      List() : first(nullptr), last(nullptr), length(0) {}
      List(const T* const data_arr, unsigned int len) : List() {
        for (int i = 0; i < len; ++i)
          if (not append(data_arr[i]))
            break;
      }
      List(unsigned int len) : List() {
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
      List& operator=(const List& old_list) {
        length = old_list.length;
        if (length != 0) {
          for (Iterator i(old_list); not i.hasEnded(); ++i)
            if (not append(i()))
              break;
        } else {
          first = last = nullptr;
        }
        return *this;
      }
      List(const List& old_list) : List() {
        *this = old_list;
      }
      ~List() {
        if (length != 0) {
          for (Iterator i(*this, false); not i.hasEnded(); ) {
            Node* current = i.current;
            --i;
            delete current;
          }
          first = last = nullptr;
        }
      }
      
      bool insert(unsigned int index, const typename list_h::AddConstToType<T>::type& new_data) {
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
        if (new_node->previous != nullptr) new_node->previous->next = new_node;
        cur->previous = new_node;
        ++length;
      }
      void truncate(int end) {
        // Domain folding
        if (length == 0)
          end = 0;
        else if (end < 0)
          end = end % length + length;
        else
          end = end % length;
        
        Iterator i(*this);
        for ( i.last(); not i.hasEnded() and i.position >= end; ) {
          Node* current = i.current;
          --i;
          delete current;
        }
        // Loose ends management
        last = i.current;
        if (i.current != nullptr) i.current->next = nullptr;
        length = end;
      }
      void slice(int start, int end, unsigned int step = 1) {
        // Domain folding
        if (length == 0)
          end = 0;
        else if (end < 0)
          end = end % length + length;
        else
          end = end % length;
        if (length == 0)
          start = 0;
        else if (start < 0)
          start = start % length + length;
        else
          start = start % length;
        
        if (start >= end)
          return;
        truncate(end);
        
        Iterator i(*this);
        for ( i.first(); not i.hasEnded() and i.position < start; ) {
          Node* current = i.current;
          ++i;
          delete current;
        }
        // Loose ends management
        first = i.current;
        if (i.current != nullptr) i.current->prev = nullptr;
        length -= start;
        // No iterators here because the list is dynamically changing
        if (step != 1 or step != 0) {
          for (int i = 0, offset = 0; i < length; ++i) {
            if ((i + offset) % step != 0) {
              remove(i);
              ++offset; --i;
            }
          }
          reCalculateLength();
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
      void sort(const list_h::BinaryFunctor<T>& func) {
        class Dummy {
          public : 
            void quickSort(List& arr, unsigned int start, unsigned int end, const list_h::BinaryFunctor<T>& func) {
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
      int includes(const typename list_h::AddConstToType<T>::type& search_data) const {
        for (Iterator i(*this); not i.hasEnded(); i++) 
          if (i() == search_data and i.position < length)
            return i.position;
        
        return -1;
      }
  };
#endif
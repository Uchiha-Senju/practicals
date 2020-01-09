#if ! defined(VARAD_SET_H_INCLUDED)
  #define VARAD_SET_H_INCLUDED
  
  namespace set_h {
    const int check_num = 0x1234abcd;
    
    // Add const to type if it is a pointer
    template <class T>
    struct AddConstToType {
      typedef T type;
    };
    template <class T>
    struct AddConstToType<T*> {
      typedef const T* type;
    };
    
    template <class T>
    class UnaryFunctor {
      public :
        virtual bool function(const typename AddConstToType<T>::type& a) const = 0;
        inline bool operator()(const typename AddConstToType<T>::type& a) const {
          return function(a);
        }
    };
  }
  
  template <typename T>
  class Set  {
    protected :
      class Node {
        public :
          T data;
          Node* next;
          Node* previous;
          const int check;
          
          Node() : check(set_h::check_num) {}
          // Weird cast of const T new_data to T so that it can be copied to data
          Node(const typename set_h::AddConstToType<T>::type& new_data, Node* prev, Node* nxt = nullptr)
            : check(set_h::check_num), data((T)new_data), previous(prev), next(nxt) {}
          Node(Node* prev) : check(set_h::check_num), previous(prev), next(nullptr) {}
          Node(const Node& old_node, Node* prev = nullptr) : Node(old_node.data, prev) {}
          ~Node() {
            data.~T();
            next = previous = nullptr;
          }
          
          bool isOk() const {
            return check == set_h::check_num;
          }
          Node* makeNext(const typename set_h::AddConstToType<T>::type& new_data) {
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
      
    public:       
      class Iterator {
        friend class Set;
        
        const Set& parent_set;
        Node* current;
        
        public :
          int position;
          
        private :
          Iterator(const Set& pops, Node* cur, int pos) : parent_set(pops), current(cur), position(pos) {}
        
        public :
        // Basic Functions
          Iterator first() {
            current = parent_set.first;
            position = 0;
          }
          Iterator last() {
            current = parent_set.last;
            position = parent_set.length - 1;
          }
          // Constructors
          Iterator(const Set& papa, bool start_at_first = true) : parent_set(papa) {
            if (start_at_first)
              first();
            else 
              last();
          };
          Iterator(const Iterator& i) : parent_set(i.parent_set), current(i.current), position(i.position) {}
          Iterator& operator=(const Iterator& i) {
            if (&parent_set == &(i.parent_set)) {
              current = i.current;
              position = i.position;
            }
            return *this;
          }
        
          bool hasEnded() const {
            return current == nullptr or position >= parent_set.length or position < 0;
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
            return Iterator(parent_set, new_current, position + index);
          }
          inline Iterator operator-(int i) {
            return *this + (-i);
          }
          
          T& operator()() const {
            return current->data;
          }
      };
      // Basic Functions
      inline unsigned int size() const {
        return length;
      }
      bool contains(const typename set_h::AddConstToType<T>::type& search_data) const {
        for (Iterator i(*this); not i.hasEnded(); i++) 
          if (i() == search_data and i.position < length)
            return true;
        
        return false;
      }
      bool add(const typename set_h::AddConstToType<T>::type& new_data) {
        if (last == nullptr) {
          last = new Node(new_data, nullptr);
          first = last;
          if (last == nullptr)
            return false;
          ++length;
        } else if (not contains(new_data)) {
          Node* new_last = last->makeNext(new_data);
          if (new_last == nullptr) return false;
          last = new_last;
          ++length;
        }
        return true;
      }
      void remove(const typename set_h::AddConstToType<T>::type& new_data) {
        Iterator i(*this);
        for (; not (i.hasEnded() or new_data == i()); (new_data == i()) ? i : ++i);
        if (i.hasEnded())
          return;
        
        Node* cur = i.current;
        if (cur == nullptr)
          return;
        if (cur->next != nullptr) cur->next->previous = cur->previous;
        if (cur->previous != nullptr) cur->previous->next = cur->next;
        
        if (cur == first)
          first = cur->next;
        if (cur == last)
          last = cur->previous;
        
        delete cur;
        --length;
      }
      // Constructors
      Set() : first(nullptr), last(nullptr), length(0) {}
      Set(const T* const data_arr, unsigned int len) : Set() {
        for (int i = 0; i < len; ++i)
          add(data_arr[i]);
      }
      Set& operator=(const Set& old_set) {
        length = old_set.length;
        if (length != 0) {
          for (Iterator i(old_set); not i.hasEnded(); ++i)
            if (not add(i()))
              break;
        } else {
          first = last = nullptr;
        }
        return *this;
      }
      Set(const Set& old_set) : Set() {
        *this = old_set;
      }
      ~Set() {
        if (length != 0) {
          for (Iterator i(*this, false); not i.hasEnded(); ) {
            Node* current = i.current;
            --i;
            delete current;
          }
          first = last = nullptr;
        }
      }
      
      bool isASubset(const Set& maybe_subset) const {
        for (Iterator i(maybe_subset); not i.hasEnded(); i++)
          if (not contains(i()))
            return false;
        return true;
      }
      bool operator==(const Set& B) const {
        if (not isASubset(B))
          return false;
        return size() == B.size();
      }
      bool isAProperSubset(const Set& maybe_subset) const {
        if (not isASubset(maybe_subset))
          return false;
        return size() != maybe_subset.size();
      }
      Set subset(const set_h::UnaryFunctor<T>& func) const {
        Set subset;
        for (Iterator i(*this); not i.hasEnded(); i++)
          if (func(i()))
            subset.add(i());
        return subset;
      }
      Set intersection(const Set& B) const {
        class Dummy : public set_h::UnaryFunctor<T> {
          const Set& other;
          Dummy(const Set& another) : other(another) {}
          bool function (const typename set_h::AddConstToType<T>::type& a) const {
            return other.contains(a);
          }
        } dummy_dum(B);
        return subset(dummy_dum);
      }
      Set join(const Set& B) const {
        Set join(B);
        for (Iterator i(*this); not i.hasEnded(); i++)
          join.add(i());
        return join;
      }
      bool disjoint(const Set& B) const {
        for (Iterator i(*this); not i.hasEnded(); i++)
          if (B.contains(i()))
            return false;
        return true;
      }
      Set difference(const Set& B) const {
        class Dummy : public set_h::UnaryFunctor<T> {
          const Set& other;
          Dummy(const Set& another) : other(another) {}
          bool function (const typename set_h::AddConstToType<T>::type& a) const {
            return not other.contains(a);
          }
        } dummy_dum(B);
        return subset(dummy_dum);
      }
      Set symmetric_difference(const Set& B) const {
        Set sym_diff(B);
        for (Iterator i(*this); not i.hasEnded(); i++)
          if (not B.contains(i()))
            sym_diff.add(i());
        for (Iterator i(B); not i.hasEnded(); i++)
          if (not contains(i()))
            sym_diff.add(i());
        return sym_diff;
      }
  };
#endif
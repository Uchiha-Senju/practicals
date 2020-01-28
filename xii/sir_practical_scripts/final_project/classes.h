#if ! defined(VARAD_CLASSES_H_INCLUDED)
  #define VARAD_CLASSES_H_INCLUDED
  
  #include <iostream>
  #include <limits>
  
  struct Subject {
    char name[51];
    unsigned short code;
    
    Subject() : code(0) {name[0] = '\0';}
    Subject(unsigned short c) : code(c) {name[0] = '\0';}
    Subject(unsigned short c, std::string n) : code(c) {
      int i;
      for (std::string::iterator it = (i = 0, n.begin()); it != n.end() and i < 50; ++i, ++it)
        name[i] = *it;
      name[i] = '\0';
    }
    Subject(unsigned short c, char* n) : code(c) {
      int i;
      for (int i = 0 ; i < 50 and n[i] != '\0'; ++i)
        name[i] = n[i];
      name[i] = '\0';
    }
    Subject& operator=(const Subject& s) {
      code = s.code;
      int i;
      for (i = 0; int(i) < 50 and s.name[i] != '\0'; ++i)
        name[i] = s.name[i];
      name[i] = '\0';
      return *this;
    }
    Subject(const Subject& s) {
      *this = s;
    }
    
    bool operator==(const Subject& s) const {
      return code == s.code;
    }
  };

  struct Student {
    char name[50];
    unsigned short roll_no;
    unsigned short subjects[6];
    
    
    void display(std::ostream& out_strm) {
      out_strm << "\n\tName : " << name;
      out_strm << "\n\tRoll no. : " << roll_no;
      out_strm << "\n\tSubjects : ";
      for (int i = 0; i < 5; ++i)
        out_strm << subjects[i] << ", ";
      out_strm << subjects[5];
    }
    void getData(std::istream& in_strm, std::ostream& out_strm) {
      out_strm << "\nEnter Student Details :";
      in_strm.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      out_strm << "\n\tName : "; in_strm.getline(name, 20);
      out_strm << "\tRoll no. : "; in_strm >> roll_no;
      out_strm << "\tSubject codes : "; for (int i = 0; i < 6; ++i) in_strm >> subjects[i];
    }
  };
  
#endif
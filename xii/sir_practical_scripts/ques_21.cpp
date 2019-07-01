#include <iostream>
#include <iomanip>
using namespace std;

enum Stream {COMPUTER_SCIENCE, ELECTRONICS, MECHANICAL, ELECTRICAL, CHEMICAL, CIVIL, NONE};

const char* stream_name(Stream stream) {
  switch(stream) {
    case COMPUTER_SCIENCE :
      return "Computer Science";
      break;
    case ELECTRONICS :
      return "Electronics";
      break;
    case MECHANICAL :
      return "Mechanical";
      break;
    case ELECTRICAL :
      return "Electrical";
      break;
    case CHEMICAL :
      return "Chemical";
      break;
    case CIVIL :
      return "Civil";
      break;
    case NONE :
      return "";
      break;
  }
}

class Student {
  char name[30];
  unsigned roll_num;
  unsigned marks[5];
  Stream stream;
  
  public :
  Student() {
    this->name[0] = '\0';
    this->roll_num = 0;
    for (int i = 0 ; i < 5; ++i)
      this->marks[i] = 0;
    this->stream = NONE;
  }
  
  void getInput(istream& input_stream, ostream& display_stream, const char* pre_str) {
    input_stream.ignore(std::numeric_limits<streamsize>::max(), '\n');
    input_stream.clear();
    display_stream << pre_str << "Name : ";
    input_stream.getline(this->name, 30, '\n');
    
    display_stream << pre_str << "Roll no. : ";
    while (!(input_stream >> this->roll_num)) {
      input_stream.ignore(1);
      input_stream.clear();
    }
    display_stream << pre_str << "Marks : ";
    for (int i = 0; i < 5; ++i) {
      while (!(input_stream >> this->marks[i])) {
        input_stream.ignore(1);
        input_stream.clear();
      }
    }
    this->assignStream();
  }
  void printSelf(ostream& display_stream, int name_space_num, int roll_space_num, int mark_space_num, int stream_space_num) {
    display_stream << setw(roll_space_num) << this->roll_num << '.';
    
    display_stream << setw(name_space_num) << this->name;
    
    for (int i = 0; i < 5; ++i) 
      display_stream << setw(mark_space_num) << this->marks[i]; 
    
    cout << setw(stream_space_num) << stream_name(this->stream);
  }
  unsigned long total() {
    unsigned long sum = 0;
    for (int i = 0; i < 5; ++i)
      sum += this->marks[i];
    return sum;
  }
  float average() {
    return this->total() / float(5);
  }
  Stream assignStream() {
    float average_marks = this->average();
    if (average_marks < 70) 
      this->stream = NONE;
    else if (average_marks < 75) 
      this->stream = CIVIL;
    else if (average_marks < 80) 
      this->stream = CHEMICAL;
    else if (average_marks < 85) 
      this->stream = ELECTRICAL;
    else if (average_marks < 90) 
      this->stream = MECHANICAL;
    else if (average_marks < 95) 
      this->stream = ELECTRONICS;
    else 
      this->stream = COMPUTER_SCIENCE;
    return this->stream;
  }
};

class WorkingStudent : public Student {
  char job[20];
  char office_address[50];
  
  public :
  WorkingStudent() : Student() {
    
    this->job[0] = '\0';
    this->office_address[0] = '\0';
  }
  
  void getInput(istream& input_stream, ostream& display_stream, const char* pre_str) {
    this->Student::getInput(input_stream, display_stream, pre_str);
    
    input_stream.ignore(std::numeric_limits<streamsize>::max(), '\n');
    input_stream.clear();
    display_stream << pre_str << "Job : ";
    input_stream.getline(this->job, 20, '\n');
    
    input_stream.ignore(std::numeric_limits<streamsize>::max(), '\n');
    input_stream.clear();
    display_stream << pre_str << "Office Address : ";
    input_stream.getline(this->office_address, 50, '\n');
    
  }
  void printSelf(ostream& display_stream, int name_space_num, int roll_space_num, int mark_space_num, int stream_space_num, int job_space_num, int off_addr_space_num) {
    this->Student::printSelf(display_stream, name_space_num, roll_space_num, mark_space_num, stream_space_num);
    
    display_stream << setw(job_space_num) << this->job;
    
    display_stream << setw(off_addr_space_num) << this->office_address;
  }
};

int main() {
  WorkingStudent stu_arr[20];
  unsigned short no_of_students;
  cout << "No. of students? ";
  do {
    while (!(cin >> no_of_students)) cin.clear();
    if (no_of_students > 20) 
      cout << "ERR : input out of range (0<, <=20)";
  } while (no_of_students > 20);
  
  cout << "Enter student details : ";
  for (int i = 0; i < no_of_students; ++i) {
    char format_string[] = "\t\t";
    cout << "\n\tStudent " << (i + 1) << " : \n";
    stu_arr[i].getInput(cin, cout, format_string);
  }
  
  cout << "Student Data : \n";
  cout << " Sr.no.  Name                           Phys  Chem  Math  Engl  Comp  Stream            Job                   Office Address\n"
       << " ------  -----------------------------  ----  ----  ----  ----  ----  ----------------  --------------------  --------------------------------------------------\n";
  for (int i = 0; i < no_of_students; ++i) {
    stu_arr[i].printSelf(cout, 31, 6, 6, 18, 22, 52);
    cout << '\n';
  }
  
  while(getchar() != '\n');
  getchar();
  
  return 0;
}

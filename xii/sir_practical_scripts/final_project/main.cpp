#include <string.h>
#include <iostream>
#include <fstream>
#include "graph.h"
#include "set.h"
#include "classes.h"

namespace commands {
  struct Command {
    const char code;
    const std::string description;
  };
  const Command display =              {'d', "Display current subject sets"};
  const Command add =                  {'a', "Add a subject set"};
  const Command remove =               {'r', "Remove a subject set"};
  const Command name =                 {'n', "Add names to subjects"};
  const Command connect =              {'c', "Connect two subjects"};
  const Command disconnect =           {'k', "Disconnect two subjects"};
  const Command procedurally_connect = {'p', "Connect any two sets with a common subject"};
  const Command read_file =            {'f', "Wipe current subject sets and read all subject sets from a student records file"};
  const Command color_graph =          {'l', "Determine the coloring i.e. exam distribution of the subjects"};
  const Command help =                 {'h', "Print this help message"};
  const Command quit =                 {'q', "Quit the program"};
  
  enum CommandEnumerator {
    FIRST,
    display_num,
    add_num,
    remove_num,
    name_num,
    connect_num,
    disconnect_num,
    procedurally_connect_num,
    read_file_num,
    color_graph_num,
    help_num,
    quit_num,
    LAST
  };
  
  CommandEnumerator getCommandEnumerator(const char com) {
    if (com == display.code) 
      return CommandEnumerator::display_num;
    else if (com == add.code) 
      return CommandEnumerator::add_num;
    else if (com == remove.code) 
      return CommandEnumerator::remove_num;
    else if (com == name.code) 
      return CommandEnumerator::name_num;
    else if (com == connect.code) 
      return CommandEnumerator::connect_num;
    else if (com == disconnect.code) 
      return CommandEnumerator::disconnect_num;
    else if (com == procedurally_connect.code) 
      return CommandEnumerator::procedurally_connect_num;
    else if (com == read_file.code)
      return CommandEnumerator::read_file_num;
    else if (com == color_graph.code) 
      return CommandEnumerator::color_graph_num;
    else if (com == help.code) 
      return CommandEnumerator::help_num;
    else if (com == quit.code) 
      return CommandEnumerator::quit_num; 
  }
  const Command& getCommand(const CommandEnumerator com) {
    if (com == CommandEnumerator::display_num) 
      return display;
    else if (com == CommandEnumerator::add_num) 
      return add;
    else if (com == CommandEnumerator::remove_num) 
      return remove;
    else if (com == CommandEnumerator::name_num) 
      return name;
    else if (com == CommandEnumerator::connect_num) 
      return connect;
    else if (com == CommandEnumerator::disconnect_num) 
      return disconnect;
    else if (com == CommandEnumerator::procedurally_connect_num) 
      return procedurally_connect;
    else if (com == CommandEnumerator::read_file_num)
      return read_file;
    else if (com == CommandEnumerator::color_graph_num) 
      return color_graph;
    else if (com == CommandEnumerator::help_num) 
      return help;
    else if (com == CommandEnumerator::quit_num) 
      return quit; 
  } 
}

class Dummy : public graph_h::BinaryFunctor<Subject> {
  Set<Set<Subject>>& subject_choices;
  public :
    Dummy(Set<Set<Subject>>& sc) : subject_choices(sc) {}
    bool function(const Subject& a, const Subject& b) const {
      Set<Subject> a_b_set;
      a_b_set.add(a), a_b_set.add(b);
      for (Set<Set<Subject>>::Iterator i(subject_choices); not i.hasEnded(); ++i) 
        if (i().isASubset(a_b_set))
          return true;
      return false;
    }
};

int main () {
  short code;
  char user_choice;
  
  Graph<Subject> subjects;
  Set<Set<Subject>> subject_choices;
  
  Dummy  dummy_dum(subject_choices);
  
  do {
    std::cout << "\n\nEnter your choice : "; std:: cin >> user_choice;
    
    switch ( commands::getCommandEnumerator(user_choice) ) {
      case commands::CommandEnumerator::display_num :
        std::cout << "\nIndex  Code  Name                                                Connections (indices)";
        std::cout << "\n=====  ====  ==================================================  =====================";
        
        for (typename List<Graph<Subject>::Vertex>::Iterator i(subjects.vertices); not i.hasEnded(); ++i) {
          std::cout << '\n' << std::setw(5) << i.position << "  " << std::setw(4) << i().data.code << "  " << std::setw(50) << i().data.name << "  ";
          for (typename List<Graph<Subject>::Vertex*>::Iterator j(i().edges); not j.hasEnded(); ++j)
            std::cout << subjects.vertices.includes(*j()) << ", ";
        }
        break;
      case commands::CommandEnumerator::add_num : {
        std::cout << "Enter the 6 subject codes in the set to be added (00 - null) : ";
        Set<Subject> subject_combo;
        for (int i = 0; i < 6; ++i) {
          std::cin >> code;
          subject_combo.add(Subject(code));
          subjects.makeVertex(Subject(code));
        }
        subject_choices.add(subject_combo);
      }
        break;
      case commands::CommandEnumerator::remove_num : {
        std::cout << "Enter the 6 subject codes in the set to be removed (00 - null) : ";
        Set<Subject> subject_combo;
        for (int i = 0; i < 6; ++i) {
          std::cin >> code;
          subject_combo.add(Subject(code));
        }
        subject_choices.remove(subject_combo);
      }
        break;
      case commands::CommandEnumerator::name_num : {
        char c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (List<Graph<Subject>::Vertex>::Iterator i(subjects.vertices); not i.hasEnded(); ++i) {
          std::cout << "Name of subject with code " << i().data.code << " : ";
          std::cin.getline(i().data.name, sizeof(i().data.name));
        }
      }
        break;
      case commands::CommandEnumerator::connect_num : {
        int i, j;
        std::cout << "\nEnter indices of the subjects to connect : "; std::cin >> i >> j;
        subjects.connectVertices(i, j);
      }
        break;
      case commands::CommandEnumerator::disconnect_num : {
        int i, j;
        std::cout << "\nEnter indices of the subjects to disconnect : "; std::cin >> i >> j;
        subjects.disconnectVertices(i, j);
      }
        break;
      case commands::CommandEnumerator::procedurally_connect_num : {
        std::cout << "Connecting any two subjects featuring in the same subject set...";
        subjects.makeConnections(dummy_dum);
      }
        break;
      case commands::CommandEnumerator::read_file_num : {
        char file_name[51];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter the file name of the records file : "; std::cin.getline(file_name, 51);
        
        Student stu;
        Set<Subject> subject_set;
        std::ifstream records(file_name, std::ios::binary | std::ios::in);
        if (not (records.is_open() and records.good())) {
          records.close();
          std::cerr << "FileError : cannot open file stream \"" << file_name << "\"";
          return 1;
        }
        records.seekg(0, std::ios::beg);
        // Wipe everything clean
        subjects.vertices.truncate(0);
        subject_choices = Set<Set<Subject>>();
        // Load all the subject sets one by one
        while( records.read((char*)(&stu), sizeof(Student))) {
          for (int i = 0; i < 6; ++i)
            subject_set.add(Subject(stu.subjects[i]));
          subject_choices.add(subject_set);
        }
        
        // Get a set of all subjects
        Set<Subject> all_subjects;
        for (Set<Set<Subject>>::Iterator i(subject_choices); not i.hasEnded(); ++i) 
          all_subjects = all_subjects.join(i());;
        // Make a new one
        for (Set<Subject>::Iterator i(all_subjects); not i.hasEnded(); ++i) 
          subjects.makeVertex(i());
        subjects.makeConnections(dummy_dum);
        // Connect vertices
        subjects.makeConnections(dummy_dum);
      }
        break;
      case commands::CommandEnumerator::color_graph_num : {        
        List<List<Graph<Subject>::Vertex*>> color_scheme = subjects.colorVertices();
        for (typename List<List<Graph<Subject>::Vertex*>>::Iterator i(color_scheme); not i.hasEnded(); ++i) {
          std::cout << "\nDay " << i.position + 1 << " - ";
          for (typename List<Graph<Subject>::Vertex*>::Iterator j(i()); not j.hasEnded(); ++j) 
            std::cout << j()->data.code << ", ";
        }
      }
        break;
      case commands::CommandEnumerator::help_num :
        for (commands::CommandEnumerator com = commands::CommandEnumerator::FIRST; (com = commands::CommandEnumerator(com + 1)) != commands::CommandEnumerator::LAST;) {
          const commands::Command& command = commands::getCommand(com);
          std::cout << "\n\t" << command.code << " - " << command.description;
        }
          std::cout << '\n';
        break;
      case commands::CommandEnumerator::quit_num :
        std::cout << "\nBye!!\n";
        break;
      default : 
        std::cout << "\nInvalid Option. Enter \'" << commands::help.code << "\' for a help message";
        break;
      
    }
  } while (user_choice != commands::quit.code);
}
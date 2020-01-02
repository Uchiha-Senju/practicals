#include "graph.h"
#include <iostream>
using namespace std;

namespace commands {
  const char display = 'd';
  const char add = 'a';
  const char remove = 'r';
  const char connect = 'c';
  const char disconnect = 'k';
  const char procedural_connect = 'p';
  const char color = 'l';
  const char help = 'h';
  const char quit = 'q';
}

class intAreCoprime : public graph_h::Functor<int> {
  bool function(const int& a, const int& b) const {
    int big_num = (a>b) ? a : b;
    int small_num = (not (a>b)) ? a : b;
    while (not (small_num == 1 or small_num == 0)){
      int temp = small_num;
      small_num = big_num % small_num;
      big_num = temp;
    }
    return small_num != 1;
  }
};

int main() {
  Graph<int> graph;
  
  int number, number_2;
  char choice;
  do {
    cout << "\n\nEnter choice : ";
    cin >> choice;
    
    switch(choice) {
      case commands::display :
        graph.displayVertices(cout);
        break;
      case commands::add :
        cout << "\nEnter value to be inserted : ";
        cin >> number;
        graph.makeVertex(number);
        break;
      case commands::remove :
        cout << "\nRemove from index (0-" << graph.vertices.len() - 1 << ") : "; cin >> number;
        graph.removeVertex(number);
        break;
      case commands::connect : 
        cout << "\nEnter indices of the vertices to connect : "; cin >> number >> number_2;
        graph.connectVertices(number, number_2);
        break;
      case commands::disconnect : 
        cout << "\nEnter indices of the vertices to disconnect : "; cin >> number >> number_2;
        graph.disconnectVertices(number, number_2);
        break;
      case commands::procedural_connect : {
          cout << "\nConnecting by relative prime-ness";
          intAreCoprime dummy;
          graph.makeConnections(dummy);
        }
        break;
      case commands::color : {
        list<list<Graph<int>::Vertex*>> color_scheme = graph.colorVertices();
        for (typename list<list<Graph<int>::Vertex*>>::Iterator i(color_scheme); not i.hasEnded(); ++i) {
          cout << "\nColor " << i.position << " - ";
          for (typename list<Graph<int>::Vertex*>::Iterator j(i()); not j.hasEnded(); ++j) 
            cout << graph.vertices.includes(*(j())) << ", ";
        }
      }
        break;
      case commands::help :
        cout << "\t" << commands::display << " - Display Vertices with connections\n"
             << "\t" << commands::add << " - Add Vertex\n"
             << "\t" << commands::remove << " - Remove Vertex\n"
             << "\t" << commands::connect << " - Connect two vertices\n"
             << "\t" << commands::disconnect << " - Disconnect two vertices\n"
             << "\t" << commands::procedural_connect << " - Connect vertices by relative prime-ness\n"
             << "\t" << commands::color << " - Color graph\n"
             << "\t" << commands::help << " - Print this help message\n"
             << "\t" << commands::quit << " - QUIT";
        break;
      case commands::quit :
        cout << "\tBye\n";
        break;
      default :
        cout << "\tInvalid option, use \'" << commands::help << "\' for help \n\n";
    }
  } while (choice != commands::quit);
  
}
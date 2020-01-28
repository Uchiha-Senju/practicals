#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "vector.h"
#include "cls.h"
#include <time.h>
using namespace std;

// source - https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
void sleep_ms(int k) {
  
#if defined _WIN32
  Sleep(k);
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) ||  defined (__APPLE__)
  usleep(1000*k);
#endif

}

class World;
class Cell;

class Cell {
  bool current_state;
  bool future_state;
  World* worldspace;
  Vector2<unsigned short> location;
  
  public : 
  
  Cell () {
    this->location = Vector2<unsigned short>();
    this->current_state = false;
    this->future_state = false;
    this->worldspace = nullptr;
  }
  Cell (Vector2<unsigned short> location, bool current_state, World* worldspace) {
    this->location = location;
    this->current_state = current_state;
    this->future_state = false;
    this->worldspace = worldspace;
  }
  
  bool isAlive() {
    return current_state;
  };
  void prepareUpdate(); 
  void applyUpdate() {
    this->current_state = this->future_state;
  };
  
  friend World;
};

class World {
  int width, height;
  Cell **globe;
  bool loop_around;
  public :
  unsigned int max_neighbours, min_neighbours, birth_neighbours;
  
  World(unsigned int width, unsigned int height, unsigned int max_neighbours, unsigned int min_neighbours, unsigned int birth_neighbours, bool loop_around) {
    this->width = width;
    this->height = height;
    this->max_neighbours = max_neighbours;
    this->min_neighbours = min_neighbours;
    this->birth_neighbours = birth_neighbours;
    this->loop_around = loop_around;
    // Initialize globe as a 2D Cell array
    this->globe = new Cell*[width];
    for (int i = 0; i < height; ++i)
      this->globe[i] = new Cell[height];
    
    for (int i = 0; i < width; ++i) 
      for (int j = 0; j < height; ++j) {
        globe[i][j] = Cell( Vector2<unsigned short>(i,j), false, this);
      }
  };
  ~World() {
    for (int i = 0; i < this->width; ++i)
      delete this->globe[i];
    delete this->globe;
  }
  
  // Return an array of cells
  Cell** getNeighbours(Cell &cell) {
    Cell** neighbours = new Cell*[8];
    const int range[] = {-1, 0, 1};
    int i = 0;
    // Store pointers to neighbour cells in an array
    for (int x_off : range) {
      for (int y_off : range) {
        if (x_off != 0 or y_off != 0) {
          int x = (x_off + cell.location.x);
          int y = (y_off + cell.location.y);
          
          if (loop_around) {
            // implementing loop around
            x = (x + this->width) % this->width;
            y = (y + this->height) % this->height;
          } else {
            if (x < 0 or x >= this->width or y < 0 or y >= this->height) {
              // if cell address is out of bounds, replace with nullptr
              neighbours[i] = nullptr;
              ++i; continue;
            }
          }
          
          neighbours[i] = &(this->globe[x][y]);
          ++i;
        }
      }
    }
    
    return neighbours;
  };
  
  void update() {
    for (int i = 0; i < width; ++i) 
      for (int j = 0; j < height; ++j)
        this->globe[i][j].prepareUpdate();
    
    
    for (int i = 0; i < width; ++i) 
      for (int j = 0; j < height; ++j)
        this->globe[i][j].applyUpdate();
  };
  
  void render(ostream& display_stream) {
    for (int i = 2 * this->width + 2; i > 0; --i) 
      display_stream << '-';
    display_stream << '\n';
    
    for (int i = 0; i < this->width; ++i) {
      display_stream << '|';
      for (int j = 0; j < this->height; ++j) {
        if (this->globe[i][j].isAlive())
          display_stream << char(475) << char(475); // ASCII block character
        else 
          display_stream << "  ";
      }
      display_stream << '|' << '\n';
    }
    
    for (int i = 2 * this->width + 2; i > 0; --i) 
      display_stream << '-';
    display_stream << "\n\n";
  }
  
  // Begin life/activity
  void generate(bool random_gen, istream& input_stream, ostream& display_stream, int seed = -1) {
    if (seed == -1)
      seed = time(nullptr);
    
    if (random_gen) {
      this->seedByRandom(seed);
      char c = '\0';
      this->render(display_stream);
      display_stream << "Start? ";
      // while (input_stream)
      //  input_stream.get(c);
      // input_stream.clear();
      // input_stream.get(c);
          
      while (getchar() != '\n');
      getchar();
    } else {
      this->seedByHand(input_stream, display_stream);
    }
  }
  
  void seedByHand(istream& input_stream, ostream& display_stream) {
    while (true) {
      this->render(display_stream);
      
      int x, y;
      do {
        display_stream << "Enter index of cell to operate upon : ";
        input_stream >> x >> y;
        if (x < 1 or x > this->width or y < 1 or y > this->height) 
          display_stream << "\tERR : Cell index out of bounds\n";
      } while (x < 1 or x > this->width or y < 1 or y > this->height);
      
      char choice;
      display_stream << "\tCell " << x << " " << y << " : " << ((this->globe[x - 1][y - 1].isAlive())?"Alive":"Dead") << '\n';
      display_stream << "\t\tAlter? ";
      input_stream >> choice;
      if (choice == 'n' or choice == 'N')
        break;
      else if (choice == 'y' or choice == 'Y') {
        display_stream << "Set state as? ";
        input_stream >> choice;
        if (choice == 't' or choice == 'T' or choice == 'a' or choice == 'A')
          this->globe[x - 1][y - 1].current_state = true;
        else if (choice == 'f' or choice == 'F' or choice == 'd' or choice == 'D')
          this->globe[x - 1][y - 1].current_state = false;
      }
      display_stream << "\n\n";
    }
    
    this->render(display_stream);
  }
  
  void seedByRandom(int seed) {
    srand(seed);
    
    for (int i = 0; i < width; ++i) 
      for (int j = 0 ; j < height; ++j)
        this->globe[i][j].current_state = floor(2 * float(rand()) / RAND_MAX);
  }
  
};

void Cell::prepareUpdate() {
  Cell** neighbours = this->worldspace->getNeighbours(*this); // An array of pointers to neighbouring Cells
  int living_neighbours = 0;
  
  for (int i = 0; i < 8; ++i)
    if (neighbours[i] != nullptr) // if neighbour is valid
      if (neighbours[i]->isAlive())
        living_neighbours++;
  
  //std::cout << "\nCell " << this->location.x + 1 << " " << this->location.y + 1 << " - " << living_neighbours << ". ";
  
  // Die if it is too crowdy or isolated, or come to life if the neighbours meet the conditions
  if (living_neighbours > this->worldspace->max_neighbours or living_neighbours < this->worldspace->min_neighbours) {
    this->future_state = false;
    //std::cout << "Verdict - die\n";
  }
  else if (living_neighbours == this->worldspace->birth_neighbours) {
    this->future_state = true;
    //std::cout << "Verdict - live\n";
  } else {
    this->future_state = this->current_state;
    //std::cout << "Verdict - continue\n";
  }
  
}

int main () {
  int w, h, min, max, birth, tick_time;
  char choice; bool loop = false, rand_gen = true;
  std::cout << "Give initial parameters : \n";
  std::cout << "\tWidth : "; std::cin >> w;
  std::cout << "\tHeight : "; std::cin >> h;
  std::cout << "\tMinimum neighbours : "; std::cin >> min;
  std::cout << "\tMaximum neighbours : "; std::cin >> max;
  std::cout << "\tNeighbours for reproduction : "; std::cin >> birth;
  std::cout << "\tLoop around edges (y/n)? "; std::cin >> choice;
  if (choice == 'y' or choice == 'Y')
    loop = true;
  std::cout << "\tTime between ticks (milliseconds) : "; std::cin >> tick_time;
  std::cout << "Randomly generate world or create by hand (r/h)? "; std::cin >> choice;
  if (choice == 'h' or choice == 'H') 
    rand_gen = false;
  
  World isekai = World(w, h, max, min, birth, loop);
  
  isekai.generate(rand_gen, std::cin, std::cout);
  
  while (true) {
    ClearScreen();
    isekai.update();
    isekai.render(std::cout);
    sleep_ms(tick_time);
  }
  
  return 0;
}

/*####################################################
##    
##    To make the game of life
##    A cell dies of isolation if no one is around
##    A cell dies of over crowding if too many cells
##    surround
##    Golden mean
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
##    Start time : 1 hour + 10:27
##    
####################################################*/

#include <iostream>
using namespace std;

int rows, cols;
int min_neighbours = 0, max_neighbours = 0, neighbours_for_new = 3;
int block = 475;;;

;class ConwayGame {
    private : 
        bool land[30][30];
        int min_neighbours, max_neighbours, neighbours_for_new;
        char alive_block, dead_block;
    public : 
        void __init__(int min_n,int max_n, int n_f_n, char a_b, char d_b) {
            min_neighbours = min_n;
            max_neighbours = max_n;
            neighbours_for_new = n_f_n;
            alive_block = a_b;
            dead_block = d_b;
        }        
        void cleanLand() {
            for (int i = 0; i < 30; ++i) 
                for (int j = 0; j < 30; ++j)
                    land[i][j] = false;
        }
        void setCellState(int x, int y, bool isAlive) {
            if (x < 30 && y < 30) 
                land[x][y] = isAlive;
        }
        void computeNextDay() {
            bool next_land[30][30];
            int alive_neighbours;
            for (int i = 0; i < 30; ++i)
                for (int j = 0; j < 30; ++j) {
                    for (int i_off = -1; i_off <= 1; ++i_off)
                        for (int j_off = -1; j_off <= 1; ++j_off)
                            alive_neighbours += int( land[ (30 + i + i_off)%30 ][  (30 + j + j_off)%30 ]);
                    alive_neighbours -= int(land[i][j]);
                    if (alive_neighbours < min_neighbours || alive_neighbours > max_neighbours)
                        next_land[i][j] = false;
                    else if (alive_neighbours >= neighbours_for_new)
                        next_land[i][j] = true;
                    else
                        next_land[i][j] = land[i][j];
                }
            for (int i = 0; i < 30; ++i)
                for (int j = 0; j < 30; ++j) 
                    land[i][j] = next_land[i][j];
        }
        void drawLand() {
            cout << '\n';
            // for (int i = -15; i < 30 + 15; ++i) {
            for (int i = 0; i < 30; ++i) {
                // for (int j = -15; j < 30 + 15; ++j) 
                for (int j = 0; j < 30; ++j)
                    if ( land[ (30 + i)%30 ][  (30 + j)%30 ]) 
                        cout << alive_block << alive_block;
                    else
                        cout << dead_block << dead_block;
                cout << '\n';
            }
        }
};

bool evolveWorld(bool world[]) {
    int range[] = {-1,0,1};
    bool nextWorld[rows * cols], same_state = true, all_dead = true; //Make next world
    for (int i = 0; i < rows * cols; ++i) nextWorld[i] = false; // Also initialize the next world to empty, STUPID!!
    
    for (int x = 0, y = 0, neighbour_count = 0; x < rows && y < cols || (neighbour_count = 0); ++x,++y) {
        //Check for surrounding cells, loop to the other side if they are out of range, and also not count if both offsets are 0 (same cell)
        for(int x_off : range) for (int y_off : range)
            if (world[((y + y_off + cols/2) % cols) * cols + ((x + x_off + rows/2) % rows)] && (y_off || x_off)) neighbour_count++;
        // Apply the rules
        if (neighbour_count < min_neighbours) nextWorld[y * cols + x] = false; // check for isolation
        if (neighbour_count > max_neighbours) nextWorld[y * cols + x] = false; // check for overcrowding
        if (neighbour_count = neighbours_for_new) nextWorld[y * cols + x] = true; // check if cell can be occupied
        
        same_state &= nextWorld[y * cols + x] == world[y * cols + x]; // Check if all cells is unchanged
    }
    for (int i = 0; i < rows * cols; ++i) world[i] = nextWorld[i];
    for (bool k : nextWorld) all_dead &= !k; // check if all cells are dead
    return same_state || all_dead;
}

void drawWorld(bool world[]) {
    // Print world but with surrounding area to clearly show the loop around
    // for (int x = 0; x < 2*cols; ++x) {
        // for (int y = 0; y < 2*rows; ++y) {
            // if (world[((y + cols/2) % cols) * cols + ((x + rows/2) % rows)]) cout << char(block) << char(block);
            // else cout << char(432) << char(432);
        // }
        // cout << endl;
    // }
    // Print world but without surrounding area
    for (int x = 0; x < cols; ++x) {
        for (int y = 0; y < rows; ++y) {
            if (world[y * cols + x]) cout << char(block) << char(block);
            else cout << char(432) << char(432);
        }
        cout << endl;
    }
    cout << endl;
}

void daysOfCreation(ConwayGame world) {
    int x, y;
    bool end = false;
    char choice;
    //while (getchar() == '\n'); // Clear all characters in input buffer until newline
    while (true) {
        world.drawLand();
        cout << "Enter if spawn cell (s) or kill cell (k) (e to end creation mode) : ";
        cin >> choice;
        switch (choice) {
            case 's':
                cout << "Enter the coordinates of the cell (x y) : "; cin >> x >> y;
                world.setCellState(x, y, true);
                break;
            case 'k':
                cout << "Enter the coordinates of the cell (x y) : "; cin >> x >> y;
                world.setCellState(x, y, false);
                break;
            case 'e':
                end = true;
                break;
        }
        if (end) break;
        system("CLS");
    }
}

int main() {
    // cout << "Enter gird size (rows cols) : "; cin >> rows >> cols;
    ConwayGame world;
    world.cleanLand();
    while (neighbours_for_new > max_neighbours || neighbours_for_new < min_neighbours) {
        cout << "Enter minimum and maximum no. of allowed neighbours, and no. of neighbours for reproduction : ";
        cin >> min_neighbours >> max_neighbours >> neighbours_for_new;
    }
    world.__init__(min_neighbours, max_neighbours, neighbours_for_new, char(475), char(432));
    bool end;
    //cout << "Choose cell type (42 for *, 434 for " << char(434) << ", 475 for " << char(475) <<" , 510 for " << char(510)  << ", etc.): "; cin >> block;
    system("CLS");
    daysOfCreation(world);
    system("CLS");
    world.setCellState(11,11,true);
    world.setCellState(12,12,true);
    world.setCellState(12,11,true);
    world.setCellState(11,12,true);
    world.drawLand();
    while(getchar()!= '\n');
    while (true) {
        world.computeNextDay();
        system("CLS");
        world.drawLand();
        while(getchar()!= '\n');
    }
    {while (getchar() != '\n');
    getchar();}
}

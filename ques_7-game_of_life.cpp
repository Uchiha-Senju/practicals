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
int block = 475;

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

void daysOfCreation(bool world[]) {
    int x, y;
    bool end = false;
    char choice;
    //while (getchar() == '\n'); // Clear all characters in input buffer until newline
    while (true) {
        drawWorld(world);
        cout << "Enter if spawn cell (s) or kill cell (k) (e to end creation mode) : ";
        cin >> choice;
        switch (choice) {
            case 's':
                cout << "Enter the coordinates of the cell (x y) : "; cin >> x >> y;
                world[y * cols + x] = true;
                break;
            case 'k':
                cout << "Enter the coordinates of the cell (x y) : "; cin >> x >> y;
                world[y * cols + x] = false;
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
    cout << "Enter gird size (rows cols) : "; cin >> rows >> cols;
    while (neighbours_for_new > max_neighbours || neighbours_for_new < min_neighbours) {
        cout << "Enter minimum and maximum no. of allowed neighbours, and no. of neighbours for reproduction : ";
        cin >> min_neighbours >> max_neighbours >> neighbours_for_new;
    }
    bool world[rows*cols], end;
    for (int i = 0; i < rows * cols; ++i) world[i] = false;
    //cout << "Choose cell type (42 for *, 434 for " << char(434) << ", 475 for " << char(475) <<" , 510 for " << char(510)  << ", etc.): "; cin >> block;
    system("CLS");
    daysOfCreation(world);
    system("CLS");
    drawWorld(world);
    while (true) {
        // system("CLS");
        end = evolveWorld(world);
        drawWorld(world);
        if (end) break;
    }
    {while (getchar() != '\n');
    getchar();}
}

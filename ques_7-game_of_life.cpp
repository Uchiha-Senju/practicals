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
int min_neighbours, max_neighbours, neighbours_for_new;
int block = 475;

bool evolveWorld(bool world[]) {
    int range[] = {-1,0,1};
    bool nextWorld[rows * cols], same_state = true, all_dead = true; //Make next world
    for (int x = 0, y = 0, neighbour_count = 0; x < rows && y < cols || (neighbour_count = 0); ++x,++y) {
        for(int x_off : range) for (int y_off : range)
            if (x + x_off > 0 && x + x_off < rows && y + y_off > 0 && y + y_off < cols)
                if (world[(y + y_off) * cols + x + x_off]) neighbour_count++; // check for surrounding cells
        if (neighbour_count < min_neighbours) nextWorld[y * cols + x] = false; // check for isolation
        if (neighbour_count > max_neighbours) nextWorld[y * cols + x] = false; // check for overcrowding
        if (neighbour_count = neighbours_for_new) nextWorld[y * cols + x] = true; // check if cell can be occupied
        
        same_state &= nextWorld[y * cols + x] == world[y * cols + x]; // Check is state is constant
    }
    for (int i = 0; i < rows * cols; ++i) world[i] = nextWorld[i];
    for (bool k : nextWorld) all_dead &= !k; // check if all sells are dead
    return same_state || all_dead;
}

void drawWorld(bool world[]) {
    for (int x = 1; x < cols; ++x) {
        for (int y = 1; y < rows; ++y) {
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
    while (true) {
        cout << "yolo" << endl;
        drawWorld(world);
        cout << "Enter if spawn cell (s) or kill cell (k) (q to quit) : ";
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
            // case 'g':
                // cout << "Enter the coordinates of the upper leftmost cell (x y) : "; cin >> x >> y;
                // world[y][x] = f;
                // break;
            // case 'p':
                // cout << "Enter the coordinates of the upper leftmost (x y) : "; cin >> x >> y;
                // world[y][x] = false;
                // break;
            case 'q':
                end = true;
                break;
        }
        if (end) break;
    }
}

int main() {
    cout << "Enter gird size (rows cols) : "; cin >> rows >> cols;
    cout << "Enter minimum no. of allowed neighbours : "; cin >> min_neighbours;
    cout << "Enter maximum no. of allowed neighbours : "; cin >> max_neighbours;
    cout << "Enter no. of neighbours for new cell : "; cin >> neighbours_for_new;
    rows += 2; cols += 2; //Add some buffer area aroung the grid
    bool world[rows*cols], end;
    for (bool k : world) k = false;
    //cout << "Choose cell type (42 for *, 434 for " << char(434) << ", 475 for " << char(475) <<" , 510 for " << char(510)  << ", etc.): "; cin >> block;
    daysOfCreation(world);
    drawWorld(world);
    while (true) {
        end = evolveWorld(world);
        drawWorld(world);
        //if (end) break;
    }
    getchar();
}

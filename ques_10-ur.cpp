<<<<<<< HEAD
/*####################################################
##    
##    To play the Royal Game of Ur
##    Each player has seven pieces which need to
##    navigate through a board of twenty squares to
##    reach the end  without being kicked out by the
##    fellow player's pieces
##    https://www.youtube.com/watch?v=WZskjLq040I
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
####################################################*/

#include <iostream>
using namespace std;

struct Player {
  int token_positions[16];  // Vector2 positions for all tokens
  int tokens_off; // No. of tokens *off* the board
  int token_on;  // No. of token *on* the board
};

int main () {
    char choice;
    cout << "WELCOME\n"; cin >> choice;
    cout << "Come, let us play the Royal Game Of Ur\n"; getc();
    cout << "Also known as the Game of the Twenty Squares, it is a game of the ancient time, invented by the Sumerians, played for over three millenia\n"; getchar();
    cout << "\nWnat to how it works (Y/N) ? "; cin >> choice;
    if (choice >= 'a' && choice <= 'z') choice -= 32;
    if (choice == 'Y') {
        cout << "\nAlthough the game has been found from Mesopotamia to Crete, Egypt to Sri Lanka, tha actual rules of the game are actually not known. Even though a cuneiform (clay tablet) written by Itti-Marduk-balālu was found describing some of the rules, these pertained to gambling and didn't include the basic rules, as it was presumed that \"everybody just knew how to play\". However, Irving Finkel, the curator of the British Mueseum, was able to work the most probable rules of the game, based on the pieces found with it, shape of the board, the rules described in the cuneiform for the more complex version.\n\n";
        cout << "Both the players take turns to place their token on the board\n\n";
    }
}
=======
/*####################################################
##    
##    To play the Royal Game of Ur
##    Each player has seven pieces which need to
##    navigate through a board of twenty squares to
##    reach the end  without being kicked out by the
##    fellow player's pieces
##    https://www.youtube.com/watch?v=WZskjLq040I
##    
##    By Varad Mahashabde
##    Copyright 2018
##    
####################################################*/

#include <iostream>
using namespace std;

struct Player {
  int token_positions[16];  // Vector2 positions for all tokens
  int tokens_off; // No. of tokens *off* the board
  int token_on;  // No. of token *on* the board
};

int main () {
    char choice;
    cout << "WELCOME\n"; cin >> choice;
    cout << "Come, let us play the Royal Game Of Ur\n"; getc();
    cout << "Also known as the Game of the Twenty Squares, it is a game of the ancient time, invented by the Sumerians, played for over three millenia\n"; getchar();
    cout << "\nWnat to how it works (Y/N) ? "; cin >> choice;
    if (choice >= 'a' && choice <= 'z') choice -= 32;
    if (choice == 'Y') {
        cout << "\nAlthough the game has been found from Mesopotamia to Crete, Egypt to Sri Lanka, tha actual rules of the game are actually not known. Even though a cuneiform (clay tablet) written by Itti-Marduk-balālu was found describing some of the rules, these pertained to gambling and didn't include the basic rules, as it was presumed that \"everybody just knew how to play\". However, Irving Finkel, the curator of the British Mueseum, was able to work the most probable rules of the game, based on the pieces found with it, shape of the board, the rules described in the cuneiform for the more complex version.\n\n";
        cout << "Both the players take turns to place their token on the board\n\n";
    }
}
>>>>>>> 3d3738b8316a28aa4c86d79ba32748ca934503f7

#include <iostream>

#include "fork.hpp"

// allows you to not use ""
using namespace std;


// Create the User interface, design and implement, test edge cases
// Edge cases include invalid input, restarting, finding a path to end from user location.
// Test all the functionality together
// determine the flow of the game Start screen -> directions -> play -> end screen -> credits

const string CLEARCONSOLE = "\033[2J";

 
void credits();

// MAIN MENU 
void menu() {
    cout << " Welcome to Fork!" << endl; 
    cout << "     1. Play"  << endl;
    cout << "     2. Read New Game" << endl;
    cout << "     3. Credits" << endl;
    int i = 0;
    cin >> i;
     
    if (i == 1) {
        cout << CLEARCONSOLE;
        cout << "Execute loaded game here" << endl;
    }
    if (i == 2) {
        cout << CLEARCONSOLE;
        cout << "Read new game here" << endl;
    }
    if (i == 3) {
        cout << CLEARCONSOLE;
            credits();
    } 
    if (i < 1 || i > 3) {
        cout << CLEARCONSOLE;
        menu();
        cout << "Enter a valid value please" << endl;
    }
}
//CREDITS
void credits() {
    cout << "Team: Charles Lewis, Mingjun Liu, Michael Chew, Cooper Miller" << endl;
    cout << "Enter the R key to return back to main menu" << endl;
    char i = 'q';
    cin >> i;
    if (i == 'R') {
        cout << CLEARCONSOLE;
        menu();
    }
}

int main() {
    
    menu();
    Fork test("semi-complex-story.txt");
    // test.printAdj_();
    cout << test.nodesToEndNode();


    
}




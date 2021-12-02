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
    cout << "     4. Exit" << endl;
    string i = "";
    int option= 0;
        while (std::cin >> i) {
        try {
             option = stoi(i);
        } catch (std::invalid_argument const& ex) {
             option = 5;
        }
        if (option == 1) {
            cout << CLEARCONSOLE;
            cout << "Execute loaded game here" << endl;
        }
        if (option == 2) {
            cout << CLEARCONSOLE;
            cout << "Read new game here" << endl;
        }
        if (option == 3) {
            cout << CLEARCONSOLE;
                credits();
        } 
        if (option == 4) {
                return;
        } 
        if (option < 1 || option > 4) {
            cout << CLEARCONSOLE;
            cout << "Enter a valid value please" << endl;
            menu();
        }
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
    
  //  cout << test.nodesToEndNode();


    
}




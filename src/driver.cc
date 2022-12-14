#include <iostream>

#include "fork.hpp"

// allows you to not use ""
using namespace std;


// Create the User interface, design and implement, test edge cases.
// Edge cases include invalid input, restarting, finding a path to end from user location.
// Test all the functionality together.
// determine the flow of the game Start screen -> directions -> play -> end screen -> credits.

const string CLEARCONSOLE = "\033[2J";

string current_location = "";


void credits();

void new_game();

void loaded_game();

// MAIN MENU 
void menu() {
    cout << CLEARCONSOLE << endl;
    cout << " Welcome to Fork!" << endl;
    cout << "     1. Play" << endl;
    cout << "     2. Read New Game" << endl;
    cout << "     3. Credits" << endl;
    cout << "     4. Exit" << endl;
    cout << endl;
    cout << endl;
    cout << "To select an option, please press a number listed above followed by enter." << endl;
    string i = "";
    int option = 0;
    while (std::cin >> i) {
        try {
            option = stoi(i);
        } catch (std::invalid_argument const &ex) {
            option = 5;
        }
        if (option == 1) {
            cout << CLEARCONSOLE;
            cout << "Execute loaded game here" << endl;
            loaded_game();
        }
        if (option == 2) {
            cout << CLEARCONSOLE;
            cout << "Read new game here" << endl;
            new_game();
        }
        if (option == 3) {
            cout << CLEARCONSOLE;
            credits();
        }
        if (option == 4) {
            return;
            exit(-1);
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
    if (i == 'R' || i == 'r') {
        cout << CLEARCONSOLE;
        menu();
    }
}

//NEW_GAME
//Start new game and use BFS to find the path to the end
//Show the info when we arrive each node.
void new_game() {
    Fork new_game("forkStory.txt");
    current_location = "";
    cout << CLEARCONSOLE;
    cout << new_game.getStartingAction() << endl;
    while (new_game.getCurrentAction() != new_game.getEndingAction()) {
        cout << new_game.getNodeInfo() << endl;

        int i = 1;
        vector<string> current_actions;
        cout << "Enter 0 to save and return to Main Menu" << endl;
        for (string action: new_game.getCurrentActions()) {
            current_actions.push_back(action);
            cout << "Option " << i << ": " << action << endl;
            i++;
        }

        int option = -1;
        cin >> option;
        if (option < 0 || option > i) {
            cout << CLEARCONSOLE;
            cout << "Enter a valid value please" << endl;
            cout << new_game.getCurrentAction() << endl;
            int i = 1;
            for (auto it = current_actions.begin(); it != current_actions.end(); it++, i++) {
                cout << "Option " << i << ": " << *it << endl;
            }
            break;
        }
        switch (option) {
            case 0 : {
                cout << CLEARCONSOLE;
                menu();
                break;
            }
            case 1 : {
                new_game.setCurrentAction(current_actions[0]);
                current_location = current_actions[0];
                cout << CLEARCONSOLE;
                cout << new_game.getCurrentAction() << endl;
                break;
            }

            case 2: {
                new_game.setCurrentAction(current_actions[1]);
                current_location = current_actions[1];
                cout << CLEARCONSOLE;
                cout << new_game.getCurrentAction() << endl;
                break;
            }

            case 3: {
                new_game.setCurrentAction(current_actions[2]);
                current_location = current_actions[2];
                cout << CLEARCONSOLE;
                cout << new_game.getCurrentAction() << endl;
                break;
            }

            case 4: {
                new_game.setCurrentAction(current_actions[3]);
                current_location = current_actions[3];
                cout << CLEARCONSOLE;
                cout << new_game.getCurrentAction() << endl;
                break;
            }

            case 5: {
                new_game.setCurrentAction(current_actions[4]);
                current_location = current_actions[4];
                cout << CLEARCONSOLE;
                cout << new_game.getCurrentAction() << endl;
                break;
            }
        }
    }

    if (new_game.getCurrentAction() == new_game.getEndingAction()) {
        cout << "You Won!" << endl;
        cout << "Press any key to continue" << endl;
        string i = "";
        cin >> i;
        cout << CLEARCONSOLE;
        credits();
    }

}

//LOADED_GAME
void loaded_game() {
    Fork loaded_game("forkStory.txt");
    if (current_location != "") loaded_game.setCurrentAction(current_location);
    cout << CLEARCONSOLE;
    cout << loaded_game.getCurrentAction() << endl;
    while (loaded_game.getCurrentAction() != loaded_game.getEndingAction()) {
        cout << loaded_game.getNodeInfo() << endl;

        int i = 1;
        vector<string> current_actions;
        cout << "Enter 0 to save and return to Main Menu" << endl;
        for (string action: loaded_game.getCurrentActions()) {
            current_actions.push_back(action);
            cout << "Option " << i << ": " << action << endl;
            i++;
        }

        int option = -1;
        cin >> option;
        if (option < 0 || option > i) {
            cout << CLEARCONSOLE;
            cout << "Enter a valid value please" << endl;
            cout << loaded_game.getCurrentAction() << endl;
            int i = 1;
            for (auto it = current_actions.begin(); it != current_actions.end(); it++, i++) {
                cout << "Option " << i << ": " << *it << endl;
            }
            break;
        }
        switch (option) {
            case 0 : {
                cout << CLEARCONSOLE;
                menu();
                break;
            }
            case 1 : {
                loaded_game.setCurrentAction(current_actions[0]);
                current_location = current_actions[0];
                cout << CLEARCONSOLE;
                cout << loaded_game.getCurrentAction() << endl;
                break;
            }

            case 2: {
                loaded_game.setCurrentAction(current_actions[1]);
                current_location = current_actions[1];
                cout << CLEARCONSOLE;
                cout << loaded_game.getCurrentAction() << endl;
                break;
            }

            case 3: {
                loaded_game.setCurrentAction(current_actions[2]);
                current_location = current_actions[2];
                cout << CLEARCONSOLE;
                cout << loaded_game.getCurrentAction() << endl;
                break;
            }

            case 4: {
                loaded_game.setCurrentAction(current_actions[3]);
                current_location = current_actions[3];
                cout << CLEARCONSOLE;
                cout << loaded_game.getCurrentAction() << endl;
                break;
            }

            case 5: {
                loaded_game.setCurrentAction(current_actions[4]);
                current_location = current_actions[4];
                cout << CLEARCONSOLE;
                cout << loaded_game.getCurrentAction() << endl;
                break;
            }
        }
    }

    if (loaded_game.getCurrentAction() == loaded_game.getEndingAction()) {
        cout << "You Won!" << endl;
        cout << "Press any key to continue" << endl;
        string i = "";
        cin >> i;
        cout << CLEARCONSOLE;
        credits();
    }
}

int main() {

    menu();

    //  cout << test.nodesToEndNode();

}
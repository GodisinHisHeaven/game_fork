#include <iostream>

#include "fork.hpp"

// allows you to not use "std::"
using namespace std;


// Create the User interface, design and implement, test edge cases
// Edge cases include invalid input, restarting, finding a path to end from user location.
// Test all the functionality together
// determine the flow of the game Start screen -> directions -> play -> end screen -> credits

int main() {
    Fork test("semi-complex-story.txt");
    // test.printAdj_();
    cout << test.nodesToEndNode();


    
}
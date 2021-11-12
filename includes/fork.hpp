#ifndef FORK_HPP
#define FORK_HPP

#include "node.hpp"
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
// set imported from "node.hpp"


// fork will be all backend, driver.cc will be used to create the user interface with terminal
// user doesn't interact with this file
// add more public member functions as needed
class Fork {
public:

    // take in filename and read it do adj_
    // this is where the file reading occurs
    Fork(std::string filename);

    // deallocate memory that is dynamically allocated
    // if you use standard libraries such as queue, map, vector, this is already taken care of
    ~Fork();

    // returns path to end
    // "action -> action -> action"
    // use bfs
    std::string findEndNode();

    // put the user at the starting action
    void restart();

    // copy game from one to another
    Fork& operator=(const DNAstrand& rhs);

private:
    // add more as needed

    // stored adj list
    std::map<std::string, std::set<std::string>> adj_;

    // keep track of where the user is located!
    std::string currentAction;

    // used for restarting the game.
    std::string startingAction;
};

#endif
#ifndef FORK_HPP
#define FORK_HPP

#include "node.hpp"
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>
// set imported from "node.hpp"


// fork will be all backend, driver.cc will be used to create the user interface with terminal
// user doesn't interact with this file
// add more public member functions as needed
class Fork {
public:

    // take in filename and read it do adj_
    // this is where the file reading occurs
    // @param filename to be read by constructor
    Fork(std::string filename);

    // deallocate memory that is dynamically allocated
    // if you use standard libraries such as queue, map, vector, this is already taken care of
    ~Fork();

    // returns path to end
    // "action -> action -> action"
    // use bfs or dfs
    // @return returns path to end node
    std::string findEndNode();


    // counts distance from node to end node
    // @return returns number of nodes to end node
    int nodesToEndNode();

    // put the user at the starting action
    // @return puts the user at the start by changing 'currentAction'
    void restart();

    // copy game from one to another
    Fork& operator=(const Fork& rhs);

    // for debugging purposes
    // prints adjacenecy list
    void printAdj_();

    // prints with same formatting as file
    void printOriginal();

    // getters to return private member variabes;
    std::map<std::string, Node<std::string>*> getAdj_() { return adj_; }

    std::string getCurrentAction() { return currentAction; }

    std::string getStartingAction() { return startingAction; }

    std::string getEndingAction() { return endingAction; }

    // removes trailing white space
    // @param str to be trimmed
    // @return returns string with no white space at the end
    friend std::string trim(std::string str);
private:
    // add more as needed

    // stored adj list
    // maps strings to a set of nodes
    std::map<std::string, Node<std::string>*> adj_;

    // keep track of where the user is located!
    // set by constructor
    // at start of game, startingAction == currentAction
    std::string currentAction;

    // used for restarting the game.
    // set by constructor
    std::string startingAction;

    // compare with this to see if end node is reached
    // set by constructor
    std::string endingAction;
};

#endif
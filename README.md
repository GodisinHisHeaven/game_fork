# final-project-team
final-project-team created by GitHub Classroom
## Fork

## How To Run
1. run    `make exec`
2. run `./bin/exec`
3. type in your input and play!

### Summary
The inspiration for this project is a game called Zork. This is a text based game to be implemented through the standard C++ library and played through interfacing with the terminal. The user is to start from a set starting location. After, the user traverses through nodes in a graph that tell a story to the user, and the user’s goal is to get to what is considered the end node. This is set in each game. The game will be loaded in via text file, which will be a formatted text file to be read in through standard input. Because this game is loaded in through a text file, this allows anyone to create a game through the interface, allowing for many stories to be played in a single format. The underlying implementation for this game is going to be an adjacency list, storing each of the nodes as well as the member variables to keep track of the player’s movements. The game is complete once the player reaches the end node.

### Features
- Functioning UI for the user
- Story (formatted text file)
    - {info} {action1} {action2} {action3} {action4}
        - Each node will have 4 options/actions for the player to choose from  
        - Info: tells the user a piece of the story or what’s going on at that node
        - Actions: lets the user traverse the graph. All actions have to be unique
- Find path to ending based of the players current node and their action (using bfs)
- Option to restart at beginning 


### Plan / Roadmap
We plan to follow the schedule / task delegations on the Group Project Agreement

Here is a possible roadmap for completing the work (subject to change):
1. Complete story and story building (Everyone)
2. Create the file reading structure (Charles)
3. Determine the flow of the game Start screen -> directions -> play -> end screen -> credits (Mingjun)
4. Design and implement adjacency list to store nodes (Michael)
5. Implement and test basic traversal, including edge cases (Cooper)
6. Create the User interface (Cooper / Mingjun)
7. Design and implement, test edge cases (Charles)
8. Test all the functionality together using Catch2 (Michael)
9. If time permits, implementation of other features to enhance user experience will be done (Everyone)


### Third-party Library
[<map>](https://www.cplusplus.com/reference/map/map/)
[<set>](https://www.cplusplus.com/reference/set/set/)
[<vector>](https://www.cplusplus.com/reference/vector/vector/)
[<sstream>](https://www.cplusplus.com/reference/sstream/)
[<algorithm>](https://www.cplusplus.com/reference/algorithm/)
[<queue>](https://www.cplusplus.com/reference/queue/queue/)
[<iostream>](https://www.cplusplus.com/reference/iostream/)
[<fstream>](https://www.cplusplus.com/reference/fstream/)
[<cstring>](https://www.cplusplus.com/reference/cstring/)

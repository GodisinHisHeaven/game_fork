#include "fork.hpp"

#include <stdexcept>

Fork::Fork(std::string filename) {
    std::fstream file;
    file.open(filename);

    for( std::string line; getline( file, line ); ) {
        Node<std::string> *temp = new Node<std::string>;
        std::string NodeName = "";
        if (line[0] != '#' && line != "") {
            size_t pos1 = line.find_first_of(':');
            // std::cout << ">>" << line.substr(0,pos1) << "<<";
            NodeName = line.substr(0,pos1);

            line = line.substr(pos1 + 1);
            pos1 = line.find_first_of(':');
            // std::cout << ">>" << line.substr(0,pos1) << "<<";
            temp -> data = line.substr(0, pos1);

            line = line.substr(pos1 + 1);
            while (pos1 != std::string::npos) {
                pos1 = line.find_first_of('|');
                // std::cout << ">>" << line.substr(0,pos1) << "<<";
                temp -> actions.emplace(line.substr(0,pos1));
                line = line.substr(pos1 + 1);
            }
        }
        // std::cout << std::endl;
        //add to adj list;
        if (NodeName != "") {
            adj_[NodeName] = (temp);
        } else {
            delete temp;
        }
        
    }
}

void Fork::printAdj_() {
    for (auto x: adj_) {
        std::cout << "Node Name:" << x.first <<std::endl;
        std::cout << "Node Info:" << x.second -> data <<std::endl;
        std::cout << "Adjacent Nodes:";
        for (auto y: x.second->actions) {
            std::cout << y << " ";
        }
        std::cout << "\n" << std::endl;
    }
}

Fork::~Fork() {
    for (auto x: adj_) {
        delete x.second;
    }
}
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

            // trim off the comment if there is one
            if (line.find_first_of("#") != std::string::npos) {
                line = line.substr(0, line.find_first_of("#"));
            }
            // trim trailing white space
            line = trim(line);
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

std::string Fork::trim(std::string str) {
    // std::cout << "initial string:" << str.size() << std::endl;
    int ind = str.size() - 1;
    while (ind != 0) {
        if (str[ind] != ' ') {
            // std::cout << "charbreak:" << str[ind] << "<<" << std::endl;
            break;
        }
        ind--;
    }
    // std::cout << "final string:" << str.substr(0,ind) << "<<" << std::endl;
    return str.substr(0,ind + 1);
}

void Fork::printAdj_() {
    for (auto x: adj_) {
        std::cout << "Node Name:" << x.first <<std::endl;
        std::cout << "Node Info:" << x.second -> data <<std::endl;
        std::cout << "Adjacent Nodes:";
        for (auto y: x.second->actions) {
            std::cout << y << ", ";
        }
        std::cout << "\n" << std::endl;
    }
}

void Fork::printOriginal() {
    for (auto x: adj_) {
        std::cout << x.first << ":" << x.second -> data << ":";
        std::string temp = "";
        for (auto y: x.second->actions) {
            temp += y + "|";
            // std::cout << y << "|";
        }
        std::cout << temp.substr(0,temp.size()-1) << std::endl;
    }
}

Fork::~Fork() {
    for (auto x: adj_) {
        delete x.second;
    }
}
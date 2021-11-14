#include "fork.hpp"

#include <stdexcept>

Fork::Fork(std::string filename) {
    std::fstream file;
    file.open(filename);

    for( std::string line; getline( file, line ); ) {
        if (line[0] != '#') {
            size_t pos1 = line.find_first_of(':');
            std::cout << ">>" << line.substr(0,pos1) << "<<";

            line = line.substr(pos1 + 1);
            pos1 = line.find_first_of(':');
            std::cout << ">>" << line.substr(0,pos1) << "<<";

            line = line.substr(pos1 + 1);
            while (pos1 != std::string::npos) {
                pos1 = line.find_first_of('|');
                std::cout << ">>" << line.substr(0,pos1) << "<<";
                line = line.substr(pos1 + 1);
            }
        }
    }
}

Fork::~Fork() {

}
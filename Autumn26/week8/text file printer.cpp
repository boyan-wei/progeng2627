#include <iostream>
#include <fstream>

// argc is the number of command line arguments
// argv is an array of C-style strings
// we'll see what this means more in detail later on

int main(int argc, char* argv[]){

    std::ifstream infile; 
    infile.open(argv[1]);
    std::string out;

    while (infile>> out){
        std::cout << out << std::endl;
    }
    
}
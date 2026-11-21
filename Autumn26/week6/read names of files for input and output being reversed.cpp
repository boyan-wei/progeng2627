#include <iostream>
#include <fstream>
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main(){
    std::ifstream infile; 

    std::string inputfile;
    std::cin>> inputfile;

    infile.open(inputfile);

    std::vector<int> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }

    infile.close(); 

    // TODO: print the content of v in reversed order
    // onto a different text file

    //here is the output, copied from earlier example

    std::ofstream outfile;
    // outfile is not a special name


    std::string outputfile;
    std::cin >> outputfile;

    outfile.open(outputfile);
    // this will associate outfile to a file called output.txt
    // if the file doesn't exist it is created
    // if the file already exists it will be overwritten!

    if(!outfile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    // need to output the vector in reverse order

    for(int i=v.size()-1; i>=0; i -- ){
        outfile << v[i] << std::endl;
    }
    
    // prints on the output file

    outfile.close();

}







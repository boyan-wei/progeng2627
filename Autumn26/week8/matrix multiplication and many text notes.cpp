#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// useful for manipulation of strings
#include <sstream>

// to set precision when printing
#include <iomanip>

std::vector<double> line_to_vector(std::string s){ // a function that returns a vector with input being a string

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    // we can use a stringstream as if it were a stream object 
    // such as std::cout or something of type
    // std::ifstream or std::ofstream

    ss << s; //s becomes a string stream
    while(ss >> tmp){
        // std::stod converts from string to double
        out.push_back(std::stod(tmp)); // while ss still has values, pushback - coverted to double - into out vector
    }
    return out; // out is now a vector containing s but each number is at a different position and as a double
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file){ // function returning a vector of a vector which input is a string

    std::ifstream infile; // create an infile
    infile.open(input_file); // open the file which is called what we put in the function
    if(!infile.is_open()){
        std::cout << "error opening file " << input_file << std::endl;
        std::exit(EXIT_FAILURE); // in case of failiure
    }

    std::string line;
    std::vector<std::vector<double>> out;

    // std::getline reads a whole line as a string
    // by default the separator is the newline
    // rather than any whitespace
    while(std::getline(infile, line)){ // in the file, looking at a line rather than space, while stops when there is no more new lines to read
                                       // pushes each line into the string line
        out.push_back(line_to_vector(line)); // calls previous function to store a string of numbers into a vector after streaming.
                                            // pushes the vector into out. so each line has a vector of values,
                                            // and the next line is in a new row (new position) in the out vector creating a matrix
    }

    return out;
}

// sum of two matrices
std::vector<std::vector<double>> // function returning vector of vector (matrix) 
matrix_sum
(
    const std::vector<std::vector<double>>& m1,//inputs needed are two matrices, & means they will be unchanged
    const std::vector<std::vector<double>>& m2 // & means dont make a copy - so changes do change, const means cannot make change
                                                // so here we use actual but do not change the matrix, we do this as copying takes a lot oftime
)
{ 

    std::vector<std::vector<double>> out;

    for(int i = 0; i < m1.size(); i++){ // for the number of rows m1size means how many positions in the outside (how many vectors inside)

        std::vector<double> row; // declare a vector called row
        for(int j = 0; j < m1[0].size(); j++){  // for indside each row for the collumns (the vecotrs in each position of outside vector)
                                                // for the size of each row

            // bidimensional indexing
            row.push_back(m1[i][j] + m2[i][j]);//put the sum of each coordinate (i,j row,column) into out matrix row position
            // pushback always adds the value to the furthest right 
        }
        out.push_back(row); //after each row, push back in outside vector to create a new row
                            // matrix is out(row[])
    }

    return out;

}

// first need a collumn selector. 
// a row selector is already easily attainable. that is just m[i] as the outside matrix is a row
std::vector<double> collumnselect(const std::vector<std::vector<double>>& Min, int collumn){
    std::vector<double> collumnout;
    for(int i =0; i<Min.size(); i++){
        collumnout.push_back(Min[i][collumn]);
    }

    return collumnout; // creates a vector which is the column of the m2
}


// scalar multiplication of 2 matrices. this is m1row*m2column at a specific values points
std::vector <std::vector<double>> product(
    const std::vector <std::vector<double>>& m1,
    const std::vector <std::vector<double>>& m2
){
    std::vector <std::vector<double>> out;

    for(int i =0; i<m1.size(); i++){
        std::vector<double> row;
        for(int j=0; j <m2[0].size();j++){
            // for each value do row*collumn
            double total = 0;
            for(int count=0; count< m1[i].size();count++){
                std::vector<double> m2collumn = collumnselect(m2,j);
                total = total + m1[i][count] * m2collumn[count]; // go through each position at row i of m1 * each position in collumn vector
            }
            
            row.push_back(total);
            
            // put that into (row,collumn)
            // once done go to next row and repeat
        }
        out.push_back(row);
    //put each row into a row in out
    // new line when row is finished
    }
    return out;

}








std::string matrix_to_string(std::vector<std::vector<double>> m){// function output a string which input is a matrix to output matrix in text style

    std::stringstream out; // to stream a string
    // to set precision when printing
    out << std::fixed << std::setprecision(2); // setprecision2 means 2 sf, fixed means after decimal place. so it is 2dp (displayed but not actual)

    for(int i = 0; i < m.size(); i++){  // for the number of positions on outside matrix (number of rows)
        for(int j = 0; j < m[0].size(); j++){ // for each position in the vector at position of vector outside
            out << (m[i][j]) << "\t"; // put this value (row,collumn) into out. // add a tab '/t' after each push
        }
        out << "\n"; // make a new line after each row is done, so looks like an actual representation of a matrix but on text string 
    }

    // getting the std::string representation 
    // of this std::stringstream object
    return out.str(); //make out - a ss- into a string. initially used ss as we could control SF
}

int main(int argc, char* argv[]){ // uses inputs from terminal. argc counts how many arguements are used, argv can select values in the vector

    if(argc != 3){ // we need to values as two vectors are used only
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }
// the two inputs from terminal are the files for the two matrices
    std::vector<std::vector<double>> m1 = read_matrix_from_file(argv[1]); //m1 vector is arg1 file. which uses readfromfile func 
    std::vector<std::vector<double>> m2 = read_matrix_from_file(argv[2]); // pushing the values into m1

    std::vector<std::vector<double>> m3 = matrix_sum(m1, m2); // m3 is sum of m1 m2

    std::cout << matrix_to_string(m1) << std::endl; // so we can output the matrix into a text style 
    std::cout << "+" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m3) << std::endl;


    std::vector<std::vector<double>> m4 = product(m1,m2);
    
    
    std::cout << matrix_to_string(m1) << std::endl; // so we can output the matrix into a text style 
    std::cout << "*" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m4) << std::endl;

}   
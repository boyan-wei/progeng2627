#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

// in this program we are going to represent the sudoku as a one dimensional vector
// linearised by row, for instance the 4x4 sudoku: 
// 1 2 3 4
// 4 1 2 76
// 4 4 4 1
// 9 4 1 -7
// will be represented as: 
// 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7

// function twod_to_oned maps two-dimensional indices to a one-dimensional one 
// it takes in input:
// - the two indices row and col of a two dimensional data structure
// - the length of the row, rowlen
// it returns:
// - the corresponding one-dimensional index

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen+col;
} // this finds the correct index if we input a row and collumn, in the 1 d vector




// function mfind
// takes in input:
// - a vector of integers v
// - an integer n
// returns:
// the index of the element n in v, if n is in v
// -1 if n is not in v
// for instance:
// v: 3 2 5; n: 2 | return: 1
// v: 3 1 2; n: -6 | return: -1
// v: 1 1 -12 1 5; n: 5 | return: 4

int mfind(int n, const std::vector<int>& v){
    int position_of_n = -1;
    for ( int i=0; i<v.size();i++){ // loop going through all values of v 
        if(n==v[i]){ // if value at position i = value we want then set the position at this point
            position_of_n = i;
        }
    }
    return position_of_n;
}

// function check_sequence
// takes in input:
// - a vector of integers v
// returns:
// - true if v contains all the numbers from 1 to v.size() and false otherwise
// for instance:
// v: 3 2 5 | return: false
// v: 3 1 2 | return: true
// v: 1 1 -12 1 5 | return: false
// note that check_sequence must (meaningfully) use function mfind
bool check_sequence(const std::vector<int>& v){
    bool check = true;
    // we want all numbers from 1 to vsize at least once
    for(int i = 1; i<v.size()+1;i++){
        int mfind_value = mfind(i,v);
        if(mfind_value == -1){
            check=false;
        }
    }
    return check;
}

// function get_row
// takes in input:
// - a row index r
// - a one dimensional vector 'in' representing a sudoku
// provides in output:
// - a vector out containing the r-th row of in
// for example:
// r: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 2 3 4
// r: 3; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 9 4 1 -7
// note that this function must (meaningfully) use function twod_to_oned
void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    // sqrt in.size() is row and length 
    
    for(int i = 0; i<std::sqrt(in.size()); i++ ){
        out.push_back(in[twod_to_oned(r,0, std::sqrt(in.size()))+i]);
    }

}

// function get_col
// like get_row but for columns
// for example: 
// c: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 4 4 9
// note that this function must (meaningfully) use function twod_to_oned
void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
    
    for(int i = 0; i<std::sqrt(in.size()); i++){
        out.push_back(in[twod_to_oned(0,c,std::sqrt(in.size()))+i*std::sqrt(in.size())]);
    }


}

// function get_subsq
// like the two functions above but for subsquares
// we consider subsquares to be indexed from left to right
// and then from top to bottom 
// for example:
// subs: 0; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 1 2 4 1
// subs: 1; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 3 4 2 76
// subs: 2; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 4 4 9 4
// subs: 3; in: 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7 | out: 4 1 1 -7
// note that this function must (meaningfully) use function twod_to_oned
void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
    int row_length = std::sqrt(in.size());
    int sublength = std::sqrt(row_length); //== subcolumnlength
    int start_row = (subs/sublength)*sublength;
    int start_column = (subs%sublength )*sublength;
    // we want a loop to go at start, then add i to find the next in row, then a j when to go down a column. so j is on the outside

    // subs finds the subsquare number. 
    for(int j=0; j<sublength ; j++){ //columns
        for(int i =0; i < sublength; i++){ // will loop on the adding of the row
        out.push_back(in[twod_to_oned(start_row+j,start_column+i, row_length) ]) ; // so for ij = 00, will start at correct place. then add 1 to 
        // the column in the row for the correct amount as calculated in sublength, then set to zero and add to j going down a column
       
       
        // subsquare will start at 0 or 2, if 9x9 then 0 or 3. so want to int divide by sqrt then * again
        //column we want 0101 or 2323 if sub =1 or 3, if 9x9, want 012012... so see %. then *sqrt row
        }
    }// then we want an i function which will add i
    //i= 0, 1, 4,5 for 4x4, or 0,1,2, 9,10,11, 18,19,20 for 9x9. and i is  0,1,2,3 or 0,1,2,3,4,5,6,7,8
}

// function valid_sudoku 
// takes in input:
// - a one dimensional vector representing a sudoku
// returns:
// - a boolean which is true if the sudoku is valid and false if it isn't valid

// write your code where indicated
// i.e. within the two remaining incomplete 'for' loops
// do not alter anything else

bool valid_sudoku(const std::vector<int>& g){ // takes in a 1d vector of the sudoko outputs a boolean   
    int side = std::sqrt(g.size());  // side of suduko is sqrt size of 1d
    std::vector<int> seq; // define a vector of integers called seq

    // for each row...
    for(int i = 0; i < side; i++){
        seq.clear(); //clear before every row
        get_row(i, g, seq); // get row i from 1d suduko g and output that row into seq

        if(!check_sequence(seq)){ // checks if the row is valid. - one of every number
            return false; // if check_sequence is not true then return valid_suduko as false
        }
    }

    // for each column...
    for(int i = 0; i < side; i++){
        seq.clear();
        get_col(i,g,seq);

        if (!check_sequence(seq))
        {
            return false;
        }
        
    }

    // for each subsquare...
   for(int i = 0; i < side; i++){
        // subsquare follows same rules as a row and such
        seq.clear();
        get_subsq(i,g,seq);

        if(!check_sequence(seq)){
            return false;
        }
    }

    // if the program execution gets to here it means that 
    // it hasn't executed a "return false" above
    // so the sudoku is valid:

    return true;
}

int main(int argc, char* argv[]){

    if(argc != 2){ //the ./a is an arguement at position 0
        std::cout << "one argument needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> s; // define vector of integers s

    // beginning of block of code reading the sudoku from the text file

    std::ifstream infile;
    infile.open(argv[1]); // input arguement should be a text file of the suduko

    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp; //define temp as integer

    while(infile >> tmp){  // read infile and put into tmp 
        s.push_back(tmp); // put the value of tmp into vector. keep doing until no more in infile 
    }
    // end of block of code reading the sudoku from the text file
    // we now have the content of the sudoku in vector s

    // the suduko is now a 1d. 2dto1d function uses a 1d vector but uses input of 2d coords to find

    int side = std::sqrt(s.size());
    // assuming it is a valid square grid in terms of size
    // (if it isn't, the program will not work properly, which is expected)

    // printing the content of the sudoku (as a square);
    // the sudoku is stored as a one-dimensional vector
    // but the vector can be indexed using two indices
    // by converting the indices of a two dimensional representation
    // into the corresponding one-dimensional index (using our function twod_to_oned)

    for(int i = 0; i < side; i++){ // the vector s is 1d, but this is how we are displaying output into an actual 2d. using 2dto1d 
        for(int j = 0; j < side; j++){ // to find the value in the 1d and then prinitng makes it in the 2d strcuture
            std::cout << s[twod_to_oned(i, j, side)] << " ";
        }
        std::cout << std::endl;
    }

    // calling the function checking if the sudoku is a valid one:

    bool valid = valid_sudoku(s);

    if(valid){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "not valid" << std::endl; 
    }

}
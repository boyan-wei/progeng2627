#include <iostream>
#include <string>

int main(){

    double temp_in, temp_out;
    std::string unit_in, unit_out;

    

    // stage 1: input

    std::cin >> temp_in >> unit_in;

    const double tCtoF = (temp_in* 1.8) +32, tFtoC= (temp_in-32) * (5/9.0);

    bool valid_unit = true;
    // we assume the user will input a valid unit

    // stage 2: data processing

    if(unit_in == "C" || "c"){
        unit_out = "F";
        temp_out = tCtoF;

    }
    else if(unit_in == "F" || "f"){
        unit_out = "C";
        temp_out = tFtoC;
    }
    else{
        valid_unit = false;
        // if the user inputs an invalid unit name
        // we update this variable
    }

    // stage 3: output 

    if(valid_unit){
        std::cout << temp_out << " " << unit_out << std::endl;
    }
    else{
        std::cout << "error, unit not recognised" << std::endl;
    }

}
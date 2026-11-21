#include <iostream>
#include <fstream>
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

// search function
int search_vector(std::string s, const std::vector<std::string>& vin){
// s is the string we are looking for
    int index = -1;
    for(int i = 0; i<vin.size();i++){
        if(s==vin[i]){
            index = i;
        }
    }
    return index;
}


//function of union
void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    // vin1 and vin2 will be the 2 warehouse vectors
    vout=vin1;

    // need to check so use search function. if return is -1 then there is no repeat 
    // need to loop for all indexes in vin2
    for(int i = 0 ; i<vin2.size();i++){
        if(search_vector(vin2[i],vout) == -1){ // will search for the value in vin2 at postition i compared to vout
            vout.push_back(vin2[i]);
        }
    }// so for each index, if no repeats then put into vout. if there is a repeat we just move on to next i    
        
}

// function of intersection
void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    // vin1 and vin2 are the 2 warehouse vectors, vout is the intersection
    // let vin 1 be the main vector. for each index of vin1 we need to check for a repeat. if there is a repeat, add it to vout
    for(int i = 0; i<vin1.size();i++){
        if(search_vector(vin1[i],vin2)!=-1){
            vout.push_back(vin1[i]); // using an index from vin1, we check if repeat in vin2. if yes then add to vout.
            //no need to check vin 2 because it would be unique
        }
    }
}


int main(){

    //here is the reading and transferring to vectors
    std::ifstream infile1, infile2; 
    infile1.open("warehouse1.txt");
    infile2.open("warehouse2.txt");

    std::vector<std::string> warehouse1contents, warehouse2contents;

    //this checks whether the files are fine 
    if(!infile1.is_open()|| !infile2.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string warehouse1item, warehouse2item;


    // this adds items to vectors
    while(infile1 >> warehouse1item){
        warehouse1contents.push_back(warehouse1item); 
        //this creates a vector containing all the warehouse 1 items
    }
    while(infile2 >> warehouse2item){
        warehouse2contents.push_back(warehouse2item); 
        //this creates a vector containing all the warehouse 2 items
    }

    infile1.close();
    infile2.close(); 


    // calling vectors here
    std::vector<std::string> union_output, intersection_output;
    // for union
    union_vector(warehouse1contents,warehouse2contents,union_output);
    // for intersection
    intersection_vector(warehouse1contents,warehouse2contents,intersection_output);

    

    // here will be the output, will update vectors from the function and then will be written down here

    std::ofstream intersection, unionn;
    
    unionn.open("union.txt");
    intersection.open("intersection.txt");
    // this will associate uinionn to a file called union

    if(!unionn.is_open()|| !intersection.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    
    // just loop the vector outs onto file
    for(int i=0; i<union_output.size(); i ++ ){
        unionn << union_output[i] << std::endl;
    }
    
    for(int i=0; i<intersection_output.size(); i ++ ){
        intersection << intersection_output[i] << std::endl;
    }

    unionn.close();
    intersection.close();

}







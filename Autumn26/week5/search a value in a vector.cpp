#include <iostream>
#include <vector>

// return index of smallest value
// -1 ifvector is empty 

int search_vector(int n, const std::vector<double>& vin){
    int index = -1;
    for(int i=0;i< vin.size();i++){
        if(vin[i] == n)
        index = i;
    }
    return index;
}


int main(){
    std::vector<double> v{3,0.5,-1};
    std::vector<double> v1{};
    std::vector<double> v2{3,0.5,-1, 7, 0, 9};



    std::cout<< search_vector(3, v)<< std::endl;   
    std::cout<< search_vector(3, v1)<< std::endl;   

}
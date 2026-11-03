#include <iostream>
#include <vector>

// return index of smallest value
// -1 ifvector is empty 

int min_vector_element(const std::vector<double>& vin){
    int index=-1, largest =0;
    for(int i=0; i< vin.size(); i++ ){   
        if(vin[i]>largest){
            largest = vin[i];
            index = i;
        }

    }
    return index;
}

int main(){
    std::vector<double> v{3,0.5,-1};
    std::vector<double> v1{};
    std::vector<double> v2{3,0.5,-1, 7, 0, 9};



    std::cout<< min_vector_element(v)<< std::endl;   
    std::cout<< min_vector_element(v1)<< std::endl;   
    std::cout<< min_vector_element(v2)<<std::endl;   

}
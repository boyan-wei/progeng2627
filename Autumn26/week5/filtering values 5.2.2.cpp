#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout){

//vout is vin which has values less than t
    for(int i = 0; i<vin.size(); i++){
        if(vin[i]<t){
            vout.push_back(vin[i]);
        }
    }

}


int main(){
    // this program will not work as expected...
    std::vector<double> vin{1,7,3,4,5,6,7,2,3,12}, vout{};
    int t = 4;
    filter_v(vin,t,vout);
    

    for(int i = 0; i < vout.size(); i++){
    std::cout << vout[i] << " ";
    }

    
}
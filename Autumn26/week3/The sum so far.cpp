#include <iostream>

int main(){
     
    int n, initial, i=1; 
    double avg;
    std::cout << "enter a number:" << std::endl;
    std::cin >> initial;
    

    while(n != 0){
    
        std::cout << "the average so far is:" << std::endl << initial << std::endl;
    
        std::cout << "enter a number:" << std::endl;
        std::cin >> n;
        i = i+1;
        initial = (initial + n) / i ;

    }
}
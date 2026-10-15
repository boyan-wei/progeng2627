#include <iostream>

int main(){
     
    double n, initial, i=1.0000; 
    double avg ;
    std::cout << "enter a number:" << std::endl;
    std::cin >> initial;
    

    while(n != 0){
        avg = (initial)/ i;
        std::cout << "the average so far is:" << std::endl << avg << std::endl;
    
        std::cout << "enter a number:" << std::endl;
        std::cin >> n;
        initial = initial + n ; 
        i = i+1;
      

    }
}
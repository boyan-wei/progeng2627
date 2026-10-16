#include <iostream>
int main(){
    int n, steps=0, max;
    std::cin >> n;
    max = n;

    while( n != 1){
       
        if (n%2 == 0){
            n = n /2;
        }
        else if(n%2 == 1){
            n = 3*n +1;
           
        }
        std::cout << n <<std::endl;
        if (n>max){
            max = n;
        }

        steps = steps +1;

    }
    std::cout <<"the number of steps is: " << steps << std::endl;
    std::cout <<"the largest number in the sequence is: " << max << std::endl;
    
}

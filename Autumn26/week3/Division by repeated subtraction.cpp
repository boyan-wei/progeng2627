#include <iostream>

int main(){
     
    int a, b ; //for form a/b
    int count = 0;
    std::cin >> a >> b;
    

    while(a>=b){
        a = a - b; 
        count = count + 1;
    }
    
    std::cout<< "the answer to " << a + b*count << " divided by " << b << " is"<< std::endl;
    std::cout<< count << " remainder " << a; 
}
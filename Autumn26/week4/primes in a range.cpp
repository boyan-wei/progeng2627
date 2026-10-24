#include <iostream>

bool smallest_factor(int n){
    bool found_factor = true;
    for(int cf = 2; cf < n; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...

            found_factor = false;
            //...it means we have found a factor!
            return found_factor;
        }
    }
return found_factor;    
}

int main(){
    int a,b;
    std::cin >> a >>b;
    for (int i=a; i<=b ; i ++){
        if(smallest_factor(i)){
        std::cout<< i << std::endl;
        }
    }
}
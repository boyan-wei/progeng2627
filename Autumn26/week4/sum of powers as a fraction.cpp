#include <iostream>

double mypow(double base, int n){
    double result=0, sum=1; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            sum = sum * base;
        }
    result = result + sum;
    sum=1;
    }

    return result;
}

int main(){
    double base;
    int n;
    std::cin>> base >> n;
    std::cout << mypow(base,n);
}
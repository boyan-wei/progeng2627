#include <iostream>
int main(){
    int n,x = 1; //x is total sum
    std::cin >> n;
    for(int i = 0; i < n; i++){
        x=x*(n-i);
    }
    std::cout << n << "! is " << x;
}
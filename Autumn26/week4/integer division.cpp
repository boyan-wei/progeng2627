#include <iostream>


void division(int a, int b, int& quotient, int& remainder){
    quotient = a / b;
    remainder = a%b;    

}



int main(){
    int a,b,q,r;
    std::cin >> a >> b;
    division(a,b,q,r);
    std::cout<<a << " divided by "<<b<<" is " <<q << " remainder " << r << std::endl;
}
#include <iostream>

int main(){
    double temp, ftemp;

    std::cout << "what is the temperature?" << std:: endl;
    std::cin >> temp;

    ftemp = (temp * 1.8) + 32;

    std::cout <<"the temperature in farenheit is " << ftemp;
}
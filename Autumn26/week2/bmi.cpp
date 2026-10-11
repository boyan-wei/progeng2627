#include <iostream>

int main(){
    double w, h, bmi;

    std::cout << "what is your weight?" << std:: endl;
    std::cin >> w;

    std::cout << "what is your height?" << std:: endl;
    std::cin >> h;


    bmi = (h*h) / w ;

    std::cout <<"your bmi is " << bmi ;
}
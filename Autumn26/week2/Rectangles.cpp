#include <iostream>

int main(){
    double w, l, p, a;

    std::cout << "what is the length?" << std:: endl;
    std::cin >> w;

    std::cout << "what is the length?" << std:: endl;
    std::cin >> l;

    p = 2*l +2*w;
    a = l*w;

    std::cout <<"the perimeter is " << p << " the area is " << a;
}
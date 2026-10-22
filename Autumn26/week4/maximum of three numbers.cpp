#include <iostream>

double largest(double one, double two, double three){
    double out;
    if(one>two){
        if (one>three){
            out=one;
        }
        else{
           out=three; 
        }
    } 
    else {
        if (two>three){
            out = two;
        }
        else {
            out = three;
        }
    }
    return out;
}

int main(){
    double one,two,three;
    std::cin >> one >> two >>three;
    std::cout << largest(one,two,three);

}
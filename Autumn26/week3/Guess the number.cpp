#include <iostream>
int main(){

    // need an algorithm
    // will take highest and lowest stored and always guess the middle
    // so will need to store highest and lowest
    // there however is no upper bound so lets start with 0 and 100. 
    // also we dont want to guess non-integers

    int min = 0, max = 100, guess;
    bool win = false; // win is when computer guesses number
    std::string input; // input is either h or l for higher or lower
    

    while(win == false){ //keep going until the answer is found
        guess = (min+ max)/2; // defines guess 
        std::cout<< "is your number (yes) "<< guess << " or is it higher (h) or (l)" << std::endl;
        std::cin >> input;
        if(input == "h"){
            min = guess;
        }
        else if (input == "l"){
            max = guess;
        }
        else if (input == "yes"){
            win = true;
        }



    }
    
}
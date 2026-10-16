#include <iostream>

int main(){
    int n;
    std::cin >> n;

    // n times we draw one row
    // note that we need a different variable
    // for the loop counter
    for(int c2 = 1; c2 < n+1; c2++){

        // the following loop draws one row
        for(int c = 1; c < n+1; c++){
            std::cout << c2 * c << "\t"; 
            // there is no << std::endl
            // because we want them on the same row
        }

        std::cout << std::endl;
        // we go on a newline after each row

    }

}
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v; 

    int n, in,s;
    std::cout<< "please enter n:";
    std::cin>>n ;

    for(int i = 0; i<n ; i++ ){
        std::cout << "please enter a number:";
        std::cin >> in;
        v.push_back(in);
    }

    int count = 0;
    std::cin >> s;
    for(int i = 0; i<n ; i++ ){
        if(v[i]==s){
            count = count +1;
        }
    }
    std::cout<< "there are " << count << " occurrences of " << s;
}
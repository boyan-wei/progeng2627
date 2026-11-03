#include <iostream>
#include <vector>

int main(){
    std::vector<int> v; 

    int n, in,t;
    std::cin>>n ;

    for(int i = 0; i<n ; i++ ){
    std::cin >> in;
    v.push_back(in);
    }

    std::cin >> t;
    for(int i = 0; i<n ; i++ ){
        if(v[i]<t){
            std::cout << v[i] << std::endl;
        }
    }
}
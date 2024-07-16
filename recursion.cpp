#include <iostream>
using namespace std;

void reachHome(int src , int dest){
    if (src < dest){
        if (src == dest)
            return ;
        cout << ++src << " ";
        reachHome(src , dest) ;
    }else{
        if (src == dest)
            return ;
        cout << --src << " ";
        reachHome(src , dest) ;
    }
}

void fibonacci(int range){
    
}

int main(){
    int src = 20;
    int dest = 10;
    reachHome(src , dest) ;
    return 0;
}
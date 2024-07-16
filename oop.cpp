#include <iostream>
using namespace std;

class Demo{
    private:
        static int all;
};

int Demo::all = 112;

int main(){
    cout << Demo::all << endl;
    return 0;
}
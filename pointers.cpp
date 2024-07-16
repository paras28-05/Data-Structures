#include <iostream>
using namespace std;

int main(){
    // char str[] = "Piyush Goyal";
    char ch = 'z';
    char* ptr = &ch;
    cout << ptr << endl;
    char* str2 = "piyush";
    cout << str2 << endl;
    return 0;
}
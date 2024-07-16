#include <iostream>
using namespace std;

char max_count(string str){
    int count[26] = {0}; // this statement reserves 26 spaces and stores 0 in each space
    for (int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        count[ch - 'a']++;
    }
    for (int i=0;i<26;i++){
        cout << count[i] << " ";
    }
    int max = 0;
    int index = -1;
    for (int i=0;i<str.length()-1 ; i++){
        if (count[i] > max){
            max = count[i];
            index = i;
        }
    }
    // int result = int('a') + index;
    // cout << result;
    // char result2 = static_cast<char>(result);
    // cout << result2;
    cout << "Index" << index << endl;
    char ch = 'a' + index;
    cout << ch << endl;
    return 'b';
}

int main(){
    string str = "mynameispiyushgoyal";
    // max_count(str);
    char ch = max_count(str);
    cout << ch << endl;
    return 0;
}
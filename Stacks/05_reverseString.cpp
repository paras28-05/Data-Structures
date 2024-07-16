#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <char> s;
    string input_string;
    cout << "Enter a String : " << endl; cin >> input_string;
    // while(input_string != '\0')
    // for (int i=0 ; i<4 ; i++){
    //     cout << input_string[i] << endl;
    // }
    s.push('\0');
    for (int i=0;i<input_string.size() ; i++){
        s.push(input_string[i]);
    }

    char output_string[input_string.size() + 1];

    for (int i=0 ; i <= input_string.size() ; i++){
        output_string[i] = s.top();
        s.pop();
    }

    cout << "Revered String : " << output_string << endl;
    
    return 0;
}
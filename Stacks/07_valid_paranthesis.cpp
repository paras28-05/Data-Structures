#include <iostream>
#include <stack>
using namespace std;

bool validParanthesis(string expression){
    stack<char> s;
    for (int i=0;i<expression.size();i++){
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            s.push(expression[i]);
        }else{
            if ((expression[i]==')' && s.top()== '(') || (expression[i]=='}' && s.top()== '{') || (expression[i]==']' && s.top()== '[')){
                s.pop();
            }else{
                return false;
            }
        }
    }
    if (s.empty()){
        return true;
    }else{
        return false;
    }

}

int main(){
    cout << validParanthesis("[{}]{}[]") << endl;
    return 0;
}
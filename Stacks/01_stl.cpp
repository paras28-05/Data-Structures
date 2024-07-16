#include <iostream>
#include <stack>
using namespace std;


int main(){
    stack<int> s;
    s.push(21);
    s.push(232);
    s.push(324);
    s.push(324);
    cout << s.empty()<< endl;
    // s.emplace(32);
    int size = s.size();
    for (int i=0 ; i< size ; i++){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

void sorted_insert(stack<int> &s , int data){
    if ((!s.empty() && data >= s.top()) || (s.empty())){
        s.push(data);
        return ;
    }
    int element = s.top();
    s.pop();
    sorted_insert(s , data);
    s.push(element);
}

void sort_stack(stack<int> &s){
    if (s.empty()){
        return ;
    }
    int element = s.top();
    s.pop();
    sort_stack(s);
    sorted_insert(s , element);
}

int main(){
    stack <int> s;
    s.push(0);
    s.push(32);
    s.push(-45);
    s.push(5);
    sort_stack(s);
    for (int i = 0 ; i < 4 ; i++){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
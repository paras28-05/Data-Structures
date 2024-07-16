// reverse a stack using the same single stack

#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &s , int data){
    if (s.empty()){
        s.push(data);
        return ;
    }
    int element = s.top();
    s.pop();
    insert_at_bottom(s , data);
    s.push(element);
}

void reverse_stack(stack<int> &s ){
    if (s.empty()){
        return;
    }
    int element = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s , element);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse_stack(s);
    for (int i = 0 ; i<5 ; i++){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
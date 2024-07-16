// Insertion of element at the bottom of stack

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

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    insert_at_bottom(s , 121);
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;
    return 0;
}
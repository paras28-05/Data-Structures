#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse_using_recursion(queue<int> &q){
    if (q.empty()){
        return ;
    }
    int element = q.front();
    q.pop();
    reverse_using_recursion(q);
    q.push(element);
}

void reverse_using_stack(queue<int> &q){
    stack<int> s;
    for (int i=0 ; i<q.size()-1 ; i++){
        s.push(q.front());
        q.pop();
    }

    for (int i=0;i<s.size()-1 ; i++){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reverse_using_stack(q);
    for (int i=0 ; i<5;i++){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
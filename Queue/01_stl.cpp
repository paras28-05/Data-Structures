#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> q;
    q.push(32);
    q.push(45);
    q.push(-2);
    q.push(0);
    cout << q.size() << endl;
    return 0;
}
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node() : data(0) , next(NULL) {}
        Node(int data) : data(data) , next(NULL) {}
};

int main(){
    Node *head = new Node(56 );
    cout  << head->next << endl;
    return 0;
}
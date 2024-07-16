#include<iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* createTree(Node* root){
    int data;
    cout << "Enter Data : "; cin >> data;
    root = new Node(data);

    if (data == -1){
        return nullptr;
    }

    cout << "Enter left value : " << root->data << endl;
    root->left = createTree(root->left);
    cout << "Enter right value : " << root->data << endl;
    root->right = createTree(root->right);
}


int max_depth(Node* root){
    queue<Node*> q; 
}

int main(){

    return 0;
}
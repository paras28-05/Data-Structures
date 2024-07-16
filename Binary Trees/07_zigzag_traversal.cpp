// Zig Zag traversal

#include <iostream>
#include <vector>
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

Node* gen_tree(Node* root){
    int data;
    cout << "Enter data : ";cin >> data;
    root = new Node(data);

    if (data == -1)
        return nullptr;
    
    cout << "Enter left of " << root->data << endl;
    root->left = gen_tree(root->left);

    cout << "Enter right of " << root->data << endl;
    root->right = gen_tree(root->right);

    return root;
}



int main(){
    Node* root = nullptr;
    root = gen_tree(root);
    cout << "-----------------";
    cout << root->data << endl;
    return 0;
}
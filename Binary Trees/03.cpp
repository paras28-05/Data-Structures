#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree{
    private:
        Node* root;
    public:
        BinaryTree(int data){
            this->root = new Node;
            this->root->data = data;
            this->root->left = nullptr;
            this->root->right = nullptr;
        }
};

int find_height(Node* root){
    if (root == nullptr){
        return 0;
    }
    int left_height = find_height(root->left);
}



int main(){

    return 0;
}
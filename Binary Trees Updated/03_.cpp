#include<iostream>
using namespace std;
template <typename T>

class BinaryTree{
    public: 
        T data;
        BinaryTree<T>* left;
        BinaryTree<T>* right;

        BinaryTree(T data){
            this->data = data;
            this->left = nullptr;
            this->rigth = nullptr;
        }
};

// BinaryTree<int>* gen_tree(BinaryTree<int> *root){}

int no_leaf_nodes(BinaryTree<int> *root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return no_leaf_nodes(root->left) + no_leaf_nodes(root->right);
}


int main(){
    BinaryTree<int>* root = new BinaryTree<int>(1);
    return 0;
}
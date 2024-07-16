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

        void create_tree(){
            int data;
            cout << "Enter data for root Node : "; cin >> data;
            this->root = new Node;
            this->root->data = data;
            this->root->left = nullptr;
            this->root->right = nullptr;

            cout << "Enter data to left of " << this->root->data << ": "; cin >> data;
            if (data != -1){
                create_tree(root->left);                
            }
        }

        int max_height(Node* root){
            if (root == nullptr){
                return 0;
            }

            int left = max_height(root->left);
            int right = max_height(root->right);
            int ans = max(left , right) + 1;

            return ans;
        }
};

int main(){

    return 0;
}
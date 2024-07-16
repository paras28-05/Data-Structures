// Finding diameter of binary tree , ie max no. of nodes between 
// any two nodes

#include <iostream>
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
    cout << "Enter data : "; cin >> data;
    root = new Node(data);

    if (data == -1)
        return nullptr;
    
    cout << "Enter left value of " << root->data << ": "<< endl;
    root->left = gen_tree(root->left);

    cout << "Enter right value of " << root->data << ": " << endl;
    root->right = gen_tree(root->right);

    return root;
}

int max_num(int op1 , int op2){
    if (op1>op2)
        return op1;
    return op2;
}

int max_height(Node* root){

    if (root == nullptr){
        return 0;
    }

    int left = max_height(root->left);
    int right = max_height(root->right);

    int ans = max_num(left , right) + 1;
    return ans;
}



int diameter(Node* root){
    if (root == nullptr){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = max_height(root->left) + max_height(root->right) +1;

    int ans = max_num( op3 , max(op1, op2));

    return ans;
}

pair<int , int> diameter_fast(Node* root){

    if (root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter_fast(root->left);
    pair<int , int> right = diameter_fast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair <int,int> ans;
    ans.first = max(op1 , max(op2 , op3));
    ans.second = max_num(left.second , right.second) + 1;
    return ans;
    
}

int main(){
    Node* root = nullptr;
    root = gen_tree(root);
    cout << "Diameter of the tree is: " << diameter_fast(root).first << endl;
    return 0;
}
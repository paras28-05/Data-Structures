#include <iostream>
#include <vector>
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

void traverse_left(Node* root , vector<int> &ans){
    // null node
    if (root == nullptr){
        return ;
    }

    // leaf node
    if (root->left == nullptr && root->right == nullptr){
        return ;
    }
    ans.push_back(root->data);
    if (root->left == nullptr && root->right != nullptr){
        // ans.push_back(root->right->data);
        traverse_left(root->right , ans);
    }

    // ans.push_back(root->left->data);
    traverse_left(root->left , ans);
}

void traverse_leaf_nodes(Node* root , vector<int> &ans){
    if (root == nullptr)
        return ;
    if (root->left == nullptr && root->right == nullptr){
        ans.push_back(root->data);
    }else{
    traverse_leaf_nodes(root->left , ans);
    traverse_leaf_nodes(root->right , ans);
    }
}

void traverse_right(Node* root , vector<int> & ans){
    if (root == nullptr)
        return ;
    if (root->left == nullptr && root->right == nullptr)
        return ;

    if (root->right){
        traverse_right(root->right , ans);
    }else if (root->left){
        traverse_right(root->left , ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary_traversal(Node* root){
    vector<int> ans;
    if (root == nullptr){
        return ans;
    }
    ans.push_back(root->data);
    traverse_left(root->left , ans);
    traverse_leaf_nodes(root->left , ans);
    traverse_leaf_nodes(root->right , ans);
    traverse_right(root->right , ans);

    return ans;
}

int main(){
    vector<int> ans;
    Node* root = nullptr;
    root = gen_tree(root);
    ans = boundary_traversal(root);
    for (int i=0 ; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
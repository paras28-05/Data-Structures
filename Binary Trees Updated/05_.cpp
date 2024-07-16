#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

vector<int> zigzagTrav(Node* root , vector<int> &ans){
    vector<int> ans;
    if (root == nullptr){
        return ans;
    }
    bool is_left_to_right = true;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (is_left_to_right){
            ans.push_back(temp->data);
            is_left_to_right = !is_left_to_right;
            q.push(temp->right);
            q.push(temp->left);
        }else{}
    }
}

int main(){

    return 0;
}
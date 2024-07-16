#include <iostream>
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

pair<int,int> solve (Node* root){
    
    if (root == nullptr){
        return make_pair(0,0);
    }

    pair<int,int> left_pair = solve(root->left);
    pair<int,int> right_pair = solve(root->right);

    int left_height = left_pair.first;
    int left_sum = left_pair.second;

    int right_height = right_pair.first;
    int right_sum = right_pair.second;

    if (left_height == right_height){
        if ((left_sum == right_sum) || (left_sum > right_sum))
            return make_pair(left_height + 1 , left_sum + root->data);
        else if (left_sum < right_sum)
            return make_pair(left_height + 1 , right_sum + root->data);
    }
    else if (left_height > right_height){
        return make_pair(left_height + 1 , left_sum + root->data);
    }
    else{
        return make_pair(right_height + 1 , right_sum + root->data);
    }

}

int bloodline(Node* root){
    pair<int , int> ans = solve(root);
    return ans.second;
}

Node* lca(Node* root)

int main(){

    return 0;
}
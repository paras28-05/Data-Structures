// to check wheteher the given tree is balanced or not

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

    return root;
}

int max_height(Node* root){
    if (root == nullptr)
        return 0;
    
    int left = max_height(root->left);
    int right = max_height(root->right);
    int ans = max(left , right) + 1;
    return ans;
}

bool is_balanced(Node* root){
    if (root == nullptr)
        return true;

    bool left_balance = is_balanced(root->left);
    bool right_balance = is_balanced(root->right);
    int left = max_height(root->left);
    int right = max_height(root->right);

    int diff = abs(left - right) <= 1;

    if (left_balance && right_balance && diff){
        return true;
    }else{

        return false;
    }
}

pair<bool , int> is_balanced_fast(Node* root){
    if (root == nullptr){
        pair <bool , int> p = make_pair(true,1);
        return p;
    }

    bool left_balance = is_balanced_fast(root->left).first;
    bool right_balance = is_balanced_fast(root->right).first;

    int diff = (is_balanced_fast(root->left).second - is_balanced_fast(root->right).second) <= 1;

    if (left_balance && right_balance && diff){
        pair<bool,int> p = make_pair(true,-1);
        return p;
    }else{
        pair<bool,int> p = make_pair(false,-1);
        return p;
    }


}

bool is_identical(Node* root1 , Node* root2){
    if (root1 == nullptr && root2 == nullptr){
        return true;
    }if(root1 != nullptr && root2 == nullptr){
        return false;
    }if(root1 == nullptr && root2 != nullptr){
        return false;
    }

    bool result1 = is_identical(root1->left , root2->left);
    bool result2 = is_identical(root1->right , root2->right);

    bool ans = root1->data == root2->data;
    if(result1 && result2 && ans){
        return true;
    }else{
        return false;
    }
}

// bool sum_tree(Node* root){
//     if (root == nullptr){
//         return ;
//     }
//     int left_ans = sum_tree(root->left);
//     int right_ans = sum_tree(root->right);

//     int result = root->data == root->left->data + root->right->data;

//     if (left_ans && right_ans && result){
//         return true;
//     }else{
//         return false;
//     }
    
// }

// int sum(Node* root){
//     if (root == NULL){
//         return 0;
//     }

//     int left_sum = sum(root->left);
//     int right_sum = sum(root->right);

//     if (left_sum+right_sum == root->data){
//         return 1;
//     }else{
//         return 0;
//     }
// }


pair <bool,int> sum_tree(Node* root){
    if (root == NULL){
        pair <bool,int> p = make_pair(true,0);
        return p;
    }

    if (root->left == NULL && root->right == NULL){
        pair <bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair <bool , int> left_sum_tree = sum_tree(root->left);
    pair <bool , int> right_sum_tree = sum_tree(root->right);

    bool case1 = left_sum_tree.first;
    bool case2 = right_sum_tree.first;

    if(case1 && case2 && root->data == left_sum_tree.second+right_sum_tree.second){
        pair <bool,int> p = make_pair(true,left_sum_tree.second+right_sum_tree.second);
        return p;
    }else{
        pair <bool,int> p = make_pair(false,0);
        return p;
    }



}
int main(){
    Node* root;
    // Node* root2;
    root = gen_tree(root);
    // root2 = gen_tree(root2);
    cout << is_balanced_fast(root).first << endl;
    cout << "--------------" << endl;
    cout << sum_tree(root).first << endl;
    return 0;
}
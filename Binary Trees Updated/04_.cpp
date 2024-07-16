#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            right = nullptr;
            left = nullptr;
        }
};

int height(Node* root){
    if (root == nullptr){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left , right) + 1;
}

pair<int,int> diametre_fast(Node* root){
    // pair<int , int> temp;
    if (root == nullptr){
        // temp.first = 0;
        // temp.second = 0;
        // return temp;
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diametre_fast(root->left);
    pair<int,int> right = diametre_fast(root->right);
    int opt3 = left.second + right.second + 1;
    int op1 = left.first;
    int op2 = right.first;

    // pair<int , int> q = make_pair(max(op1 , max(op2 , op3)) , max(left.second , right.second) + 1);
    pair<int , int> q;
    q.first = max(op1 , max(op2 , opt3));
    q.second = max(left.second , right.second) + 1;

    return q;


}

int diameter(Node* root){
    if (root == nullptr){
        return 0;
    }
    int left_tree = diameter(root->left);
    int right_tree = diameter(root->right);
    int tree = height(root->left) + height(root->right) + 1;

    return max(left_tree , max(right_tree , tree));
}

pair<int , bool> is_balanced(Node* root){
    if (root == nullptr){
        pair<int , bool> p = make_pair(0 , true);
        return p;
    }
    pair<int , bool> left = is_balanced(root->left);
    pair<int , bool> right = is_balanced(root->right);

    pair <int , bool > ans;
    if ((abs(left.first - right.first) <= 1) && left.second && right.second){
        ans = make_pair((max(left.first , right.first) + 1) , true);
    }else{
        ans = make_pair((max(left.first , right.first) + 1) , false);
    }

    return ans;
}

bool balanced(Node* root){
    pair<int,bool> ans = is_balanced(root);
    if (ans.second)
        return true;
    return false;
}

bool is_identical(Node* root1 , Node* root2){
    if (root1 == nullptr && root2 == nullptr){
        return true;
    }
    if (root1==nullptr && root2 != nullptr){
        return false;
    }
    if (root1 != nullptr && root2 == nullptr){
        return false;
    }

    bool left = is_identical(root1->left , root2->left);
    bool right = is_identical(root1->right , root2->right);

    bool value = root1->data == root2->data;

    if (left && right && value) 
        return true;
    return false;
}

pair<bool , int> is_sum_tree(Node* root){
    if (root == nullptr){
        pair<bool , int> p = make_pair(true , 0);
        return p;
    }
    if (root->left==nullptr && root->right == nullptr){
        pair<bool , int> p = make_pair(true , root->data);
        return p;
    }

    pair<bool , int> leftAns = is_sum_tree(root->left);
    pair<bool , int> rightAns = is_sum_tree(root->right);
    bool ans;
    if (leftAns.first && rightAns.first && (root->data == (leftAns.second + rightAns.second))){
        ans = true;
    }else{
        ans = false;
    }

    return make_pair(ans, leftAns.second + rightAns.second);

    // bool left = is_sum_tree(root->left);
}

bool sum_tree(Node* root){
    pair<bool , int> ans = is_sum_tree(root);
    if (ans.first)
        return true;
    return false;
}

// bool is_balanced(Node* root){
//     if (root == nullptr){
//         return true;
//     }

//     int left = height(root->left);
//     int right = height(root->right);

//     if (abs(left-right) <= 1)
//         return true;
//     return false;
// }

int main(){

    return 0;
}
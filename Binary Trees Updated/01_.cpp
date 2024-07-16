#include<iostream>
#include <queue>
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

Node* buildtree(Node* root){
    int data;
    cout << "Enter data : "; cin >> data;
    root = new Node(data);

    if (data == -1){
        return nullptr;
    }
    cout << "Enter left of " << root->data << ": ";
    root->left = buildtree(root->left);
    cout << "Enter Right of " << root->data << ": ";
    root->right = buildtree(root->right);
    return root;
}
// it is implemented using queue (technique is BFS)
vector<int> level_order_trav(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    vector<int> ans;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        ans.push_back(temp->data); 
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}

void inorder_trav(Node* root , vector<int> &ans){
    if (root == nullptr){
        return ;
    }

    inorder_trav(root->left , ans);
    ans.push_back(root->data);
    inorder_trav(root->right , ans);
}

vector<int> inorder(Node* root){
    vector<int> ans;
    inorder_trav(root , ans);
    return ans;
}

int main(){
    Node* root = nullptr;
    root = buildtree(root);
    vector<int> ans = level_order_trav(root);
    for (int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " " ;
    }

    vector<int> ans2 = inorder(root);
    for (int i=0 ; i<ans2.size() ; i++){
        cout << ans2[i] << " ";
    }
    return 0;
}
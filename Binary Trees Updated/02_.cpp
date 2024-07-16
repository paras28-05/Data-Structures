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
    // q.push(nullptr);
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

void preorder_util(Node* root , vector<int> &ans){
    if (root == nullptr){
        return ;
    }
    ans.push_back(root->data);
    preorder_util(root->left , ans);
    preorder_util(root->right , ans);
}

vector<int> preorder(Node* root){
    vector<int> ans;
    preorder_util(root , ans);
    return ans;
}

void postorder_util(Node* root , vector<int> &ans){
    if (root == nullptr){
        return ;
    }
    postorder_util(root->left , ans);
    postorder_util(root->right  , ans);
    ans.push_back(root->data);
}

vector<int> postorder(Node* root){
    vector<int> ans;
    postorder_util(root , ans);
    return ans;
}

Node* build_from_level_order_trav(Node* root){
    queue<Node*> q;
    int data;
    cout << "Enter data : "; cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left of " << root->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right of " << root->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    Node* root = nullptr;
    root = buildtree(root);
    // vector<int> ans = level_order_trav(root);
    // for (int i=0 ; i<ans.size() ; i++){
    //     cout << ans[i] << " " ;
    // }

    vector<int> ans2 = preorder(root);
    for (int i=0 ; i<ans2.size() ; i++){
        cout << ans2[i] << " ";
    }
    return 0;
}
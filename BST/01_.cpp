#include <iostream>
#include <vector>
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

vector<int> take_input(Node* root){
    int data;
    vector<int> ans;
    cin >> data;
    if (data != -1){
        ans.push_back(data);
    }else{
        return ans;
    }
    while(data != -1){
        cin >> data;
        ans.push_back(data);
    }

    ans.pop_back();
    return ans;
}

void insertNode(Node* root , int data){
    if (root == nullptr){
        root = new Node(data);
        return;
    }
    if (data < root->data){
        insertNode(root->left , data);
        }else if (data > root->data){
            insertNode(root->right , data);
            }
}


Node* createBst(vector<int> input_arr){
    Node* root = new Node(input_arr[0]);
    for (int i=1 ; i<input_arr.size() ; i++){
        insertNode(root , input_arr[i]);
    }
    return root;
}

vector<int> level_order_trav(Node* root){
    vector<int> ans;
    if (root == nullptr){
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    ans.push_back(root->data);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->left){
            q.push(temp->left);
        }
        if (temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}

int main(){
    Node* root = nullptr;

    // taking input from user
    vector<int> input_arr = take_input(root);

    // printing the input
    for (int i=0 ; i<input_arr.size() ; i++){
        cout << input_arr[i] << " ";
    }cout << endl;
     
    // creating bst
    root = createBst(input_arr);

    // levelorder traversal of tree
    vector<int> ans = level_order_trav(root);

    //printing level_order_arr
    for (int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
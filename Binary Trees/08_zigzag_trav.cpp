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
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* gen_tree(Node* root){
    int data;
    
    cout << "Enter data:"; cin >> data;
    root = new Node(data);
    if (data == -1)
        return nullptr;
    
    cout << "Enter left of " << root->data << endl;
    root->left = gen_tree(root->left);

    cout << "Enter right of " << root->data << endl;
    root->right = gen_tree(root->right); 

    return root;
}

vector<int> zigzag_traversal(Node* root){
    vector<int> result;
    bool leftToRight = true;

    if (root == nullptr)
        return result;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        // process each level
        int size = q.size();
        vector<int> ans(size);

        for (int i=0 ; i<size;i++){
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode->data;

            if (frontNode->left){
                q.push(frontNode->left);
            }

            if (frontNode->right){
                q.push(frontNode->right);
            }
        }

        leftToRight = !leftToRight;
        for (auto i:ans){
            result.push_back(i); 
        }
    }
    return result;
}

int main(){

    Node* root = nullptr;
    root = gen_tree(root);
    vector<int> ans = zigzag_traversal(root);
    for (int i=0 ; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
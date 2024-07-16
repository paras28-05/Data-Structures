#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree{
    private:
        Node* root;
    public:
        BinaryTree(){
            this->root->left = nullptr;
            this->root->right = nullptr;
        }
        BinaryTree(int data){
            Node* newNode = new Node();
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            this->root = newNode;
        }
};

Node* create_tree(Node* root){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    root = new Node;
    root->data = data;

    if (data == -1){
        return nullptr;
    }

    cout << "Enter left of " << data << endl;
    root->left = create_tree(root->left);
    cout << "Enter right of " << data << endl;
    root->right = create_tree(root->right);

    return root;

}


// Level Order Traversal // something else
// void levelOrderTraversal(Node* root){

//     if (root == nullptr){
//         return;
//     }
    
//     cout << root->data << " ";
//     levelOrderTraversal(root->left);
//     levelOrderTraversal(root->right);

// }

void level_order_traversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left){
            q.push(temp->left);
        }
        if (temp->right){
            q.push(temp->right);
        }
    }
}

void level_order_traversal1(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder_traversal(Node* root){
    if (root == NULL){
        return ;
    }
    if(root->left != NULL){
        inorder_traversal(root->left);
    }
    cout << root->data << " ";
    if (root->right != NULL){
        inorder_traversal(root->right);
    }
}

void preorder(Node* root){
    if (root == NULL){
        return ;
    }
    cout << root->data << " ";
    if(root->left != NULL){
        preorder(root->left);
    }
    if (root->right != NULL){
        preorder(root->right);
    }
}

void postorder(Node* root){
    if (root == NULL){
        return ;
    }

    if (root->left != NULL){
        postorder(root->left);
    }
    if (root->right != NULL){
        postorder(root->right);
    }
    cout << root->data << " ";
}

void build_from_level_order_traversal(Node* root){
    int data;
    queue<Node*> q;
    cout << "Enter data for root node : "; cin >> data;
    root = new Node;
    root->data = data;
    root->right = NULL;
    root->left = NULL;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter Left value of " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1){
            temp ->left = new Node;
            temp->left->data = leftData;
            temp->left->left = nullptr;
            temp->left->right = nullptr;

        }

        cout << "Enter Riht value of " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1){
            temp ->right = new Node;
            temp->right->data = leftData;
            temp->right->left = nullptr;
            temp->right->right = nullptr;

        }
    }
}

int no_of_leaf_nodes(Node* root){
    static int count = 0;
    if (root == NULL){
        return -1;
    }

    if (root->left == NULL && root->right == NULL){
        count++;
    }else{
        no_of_leaf_nodes(root->left);
        no_of_leaf_nodes(root->right);
    }
    return count;
}

int main(){
    // 1 3 7 -1 -1 -1 5 11 -1 -1 17 -1 -1 
    int count;
    Node* root = nullptr;
    root = create_tree(root);
    count = no_of_leaf_nodes(root);
    cout << "No of leaf Node: " << count << endl;
    return 0;
}
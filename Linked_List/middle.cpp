#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
        Node* head;
        LinkedList(int data){
            this->head = new Node;
            this->head->data = data;
            this->head->next = NULL;
        }
        void insert_at_head(int data){
            Node* new_node = new Node;
            new_node->data = data;
            new_node->next = this->head;
            this->head = new_node;
        }
};

void print(Node* head){
    Node* current = head;
    while(current != NULL){
        cout << current->data << endl;
        current = current->next;
    }
}

// void middle(Node* head){
//     Node* slow = head;
//     Node* fast = head;
//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         }

// }

Node* middle(Node* head){
    Node* temp = head;
    Node* current = head;
    int no_nodes = 1;
    while(temp->next != NULL){
        no_nodes++;
        temp = temp->next;
    }
    int middle = no_nodes/2;
    for (int i=0;i<middle;i++){
        current = current->next;
    }
    cout << "Middle Element : " << current->data << endl; 
    return current;
}

Node* middle2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Element : " << slow->data << endl;
    return slow;
}

int main(){
    LinkedList l1(10);
    l1.insert_at_head(20);
    l1.insert_at_head(30);
    l1.insert_at_head(40);
    l1.insert_at_head(50);
    l1.insert_at_head(60);
    l1.insert_at_head(70);
    l1.insert_at_head(80);

    print(l1.head);
    middle2(l1.head);
    return 0;
}
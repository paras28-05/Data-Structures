#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    public:
        Node* head;
    public:
        LinkedList(int data){
            this->head = new Node;
            this->head->data = data;
            this->head->next = NULL;
        }
        void insert_at_head(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = this->head;
            this->head = newNode;
        }
        void print(){
            Node* current = this->head;
            while(current != NULL){
                cout << current->data << endl;
                current = current->next;
            }
        }
};

Node* reverseLL(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;
    while(current != NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
        // forward = forward->next;
    }
    return prev;
}

Node* reverse(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* tempHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return tempHead;

}

void general_print(Node* head){
    Node* current = head;
    while(current != NULL){
        cout << current->data << endl;
        current = current->next;
    }
}

int main(){
    LinkedList l1(10);
    l1.insert_at_head(20);
    l1.insert_at_head(30);
    l1.insert_at_head(40);
    l1.insert_at_head(50);
    l1.insert_at_head(60);

    l1.print();
    cout << "After reversing" << endl;
    Node* l2 = reverse(l1.head);
    // l2.print();
    general_print(l2);
    return 0;
}
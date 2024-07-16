#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularLinkedList{
    private:
        Node* head;
    public:
        CircularLinkedList(int data){
            this->head = new Node;
            this->head->data = data;
            this->head->next = this->head;
        }
        void insert_at_head(int data){
            Node* newNode = new Node;
            newNode->data = data;
            Node* temp = this->head;
            while(temp->next != this->head){
                temp = temp->next;
            }
            newNode->next = this->head;
            temp->next = newNode;
            this->head = newNode;
        }
        void print(){
            Node* temp = this->head;
            // cout << this->head->data << endl;
            while(temp->next != this->head){
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
};

int main(){
    CircularLinkedList list(10);
    list.insert_at_head(20);
    list.print();
    return 0;
}
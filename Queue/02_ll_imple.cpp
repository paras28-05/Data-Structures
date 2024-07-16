// Implementation of Queue using Linked List

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    private : 
        Node* front;
        Node* rear;
    public:
        Queue() {
            this->front = nullptr;
            this->rear = nullptr;
        }
        Queue(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            this->front = newNode;
            this->rear = newNode;
        }

        bool isEmpty(){
            if (this->front == nullptr)
                return true;
            return false;
        }

        void push(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            this->rear->next = newNode;
            this->rear = newNode;
        }
        void pop(){
            if (this->isEmpty()){
                cout << "Queue is empty" << endl;
            }else{
                Node* temp = this->front;
                this->front = this->front->next;
                delete temp;
            }
        }
        int peek(){
            if (this->isEmpty()){
                return -1;
            }else{
                return this->front->data;
            }
        }
        int size(){
            Node* current = this->front;
            int count = 0;
            while(current != nullptr){
                count++;
                current = current->next;
            }
            return count;
        }
        void print(){
            Node* current = this->front;
            while(current != nullptr){
                cout << current->data << endl;
                current = current->next;
            }
        }
};

int main(){
    Queue q(1);
    q.push(2);
    q.push(3);
    q.print();
    return 0;
}
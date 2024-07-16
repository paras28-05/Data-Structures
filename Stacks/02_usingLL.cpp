// Implementation of Stack using Linked List 
// Implementataion of Stack using Array

#include <iostream>
using namespace std;


// when we are implementing Stack using LL there is no overflow condition
struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        Stack() {
            top = nullptr;
        }
        Stack(int data){
            Node* newNode = new Node;
            this->top = newNode;
            this->top->data = data;
            this->top->next = nullptr;
        }
        void push(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = top;
            this->top = newNode;
        }
        int size(){
            int count = 0;
            Node* current = this->top;
            while(current != nullptr){
                count++;
                current = current->next;
            }
            return count;
        }
        bool isEmpty(){
            // int tempSize = size();
            // if (tempSize == 0){
            //     return true;
            // }
            // return false;
            return top == nullptr;
        }
        void pop(){
            if (isEmpty()){
                cout << "Stack is empty" << endl;
            }else{
                Node* temp = this->top;
                this->top = temp->next;
                cout << temp->data << "deleted Successfully";
                delete temp;
            }

        }
        void print(){
            if (isEmpty()){
                cout << "Stack is Empty." <<endl;
            }else{
                Node* current = this->top;
                while(current != nullptr){
                    cout << current->data << endl;
                    current = current->next;
                }
            }
        }
        int peek(){
            if (isEmpty()){
                return -1;
            }
            return top->data;
        }
};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    cout << s1.size() << endl;
    s1.print();
    s1.pop();
    s1.print();
    return 0;
}
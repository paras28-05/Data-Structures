#include <iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int size;
        int top;
    public:
        Stack(int size){
            this->size = size;
            top = -1;
            arr = new int[this->size];
        }
        bool isEmpty(){
            return top == -1;
        }
        bool isFull(){
            return this->top == this->size - 1;
        }
        void push(int data){
            if (isFull()){
                cout << "Stack is OverFlow" << endl;
            }else{
                top++;
                this->arr[top] = data;
            }
        }
        void pop(){
            if (isEmpty()){
                cout << "Stack is UnderFlow" << endl;
            }else{
                int element = this -> arr[top];
                top--;
            }
        }
        int peek(){
            if (isEmpty()){
                cout << "Stack is UnderFlow" << endl;
            }else{
                return this->arr[top];
            }
        }
        int getSize(){
            return this->size;
        }
        void print(){
            if (isEmpty()){
                cout << "Stack is UnderFlow" << endl;
            }else{
                for (int i=top ; i >=0 ; i--){
                    cout << this->arr[i] << endl;
                }
            }
        }
};

int main(){
    Stack s1(2);
    s1.print();
    s1.push(121);
    s1.push(32);
    s1.push(45);
    s1.print();
    s1.pop();
    s1.print();
    s1.pop();
    cout << s1.peek() << endl;
    s1.print();
    return 0;
}
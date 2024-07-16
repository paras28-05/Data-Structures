#include <iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int front;
        int rear;

    public:
        Queue(int size){
            this-> size = size;
            this->arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool full(){}

        bool empty(){
            return front == rear;
        }

        void push(int data){
            if(!full()){
                if (front == -1){
                    front++;
                    rear++;
                    arr[rear] = data;
                }
                else{
                    rear++;
                    arr[rear] = data;
                }
            }else{
                cout << "Queue is full.";
            }
        }

        int pop(){
            if(!empty()){
                int temp = arr[front];
                front--;
                return temp;
            }else{
                cout << "Queue is empty";
                return int();
            }
        }

        int front(){
            if(!empty()){
                return arr[front];
            }else{
                cout << "Queue is empty.";
                return int();
            }
        }
        int size(){}
};

int main(){

    return 0;
}
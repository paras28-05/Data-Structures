#include <iostream>
using namespace std;

class CircularQueue{
    private:
        int size;
        int* arr;
        int front;
        int rear;
    public:
        CircularQueue(int size){
            this->size = size;
            this->arr = new int[this->size];
            this->front = -1;
            this->rear = -1;
        }

        bool isFull(){
            if ((this->front == 0 && this->rear == this->size - 1) || (this->rear == (this->front - 1) % (this->size - 1))){
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if (this->front == -1){
                return true;
            }
            return false;
        }

        void enqueue(int data){
            if (this->isFull()){
                cout << "Queue is Full" << endl;
            } else {
                if (this->front == -1) { // Insert first element
                    this->front = this->rear = 0;
                } else if (this->rear == this->size - 1 && this->front != 0) {
                    this->rear = 0;
                } else {
                    this->rear++;
                }
                this->arr[this->rear] = data;
            }
        }

        void dequeue(){
            if (this->isEmpty()){
                cout << "Queue is Empty" << endl;
            } else {
                if (this->front == this->rear) { // Single element was present
                    this->front = this->rear = -1;
                } else if (this->front == this->size - 1) {
                    this->front = 0;
                } else {
                    this->front++;
                }
            }
        }

        // For debugging purposes
        void display() {
            if (this->isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Queue elements are: ";
            if (this->rear >= this->front) {
                for (int i = this->front; i <= this->rear; i++)
                    cout << this->arr[i] << " ";
            } else {
                for (int i = this->front; i < this->size; i++)
                    cout << this->arr[i] << " ";
                for (int i = 0; i <= this->rear; i++)
                    cout << this->arr[i] << " ";
            }
            cout << endl;
        }

        ~CircularQueue() {
            delete[] this->arr;
        }
};

int main(){
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.display();

    q.enqueue(6);
    q.display();

    q.enqueue(7);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(8);
    q.display();

    return 0;
}

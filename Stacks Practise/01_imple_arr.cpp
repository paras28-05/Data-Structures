#include <iostream>
using namespace std;

template <typename T>

class Stack{
    private:
        T *arr;
        int size;
        int top;
        //implementing stack using arr has one disadvantage that 
        //we have to specify its size
        public:
        Stack(int size){
            this->size = size;
            this->arr = new T[size];
            this->top = -1;
        }

        ~Stack() {
        delete[] arr;
    }

        bool empty(){
            if (top == -1)
                return true;
            return false;
        }
        bool full(){
            if (top == size-1)
                return true;
            return false;
        }
        void push(T data){
            if(full()){
                cout << "Stack is overflow";
            }else{
                top++;
                arr[top] = data;
            }
        }

        T pop(){
            if(!empty()){
                int temp = top;
                top--;
                return arr[temp];
            }else{
                cout << "Stack is underflow";
                return T();
            }
        }
        T peek(){
            if (!empty()){
                return arr[top];
            }else{
                cout << "Stack is empty";
                return T();
            }
        }
        int getsize(){
            if (top == -1){
                return 0;
            }
            return top+1;
        }
};

int main(){

    return 0;
}

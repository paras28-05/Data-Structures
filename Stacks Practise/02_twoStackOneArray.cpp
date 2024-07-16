#include <iostream>
using namespace std;

class TwoStack{
    private:
        int *arr;
        int size;
        int top1;
        int top2;
    public:
        TwoStack(int size){
            this->size = size;
            this->arr = new int[size];
            top1 = -1;
            top2 = size;
        }

        bool empty1(){
            if (top1 == -1){
                return true;
            }
            return false;
        }

        bool empty2(){
            if (top2 == size){
                return true;
            }
            return false;
        }
        bool full(){
            if ((top2 - top1) == 1){
                return true;
            }
            return false;
        }

        void push1(int data){
            if(!full()){
                top1++;
                arr[top1] = data;
            }else{
                cout << "Stack is Overflow";
            }
        }
        void push2(int data){
            if(!full()){
                top2--;
                arr[top2] = data;
            }else{
                cout << "Stack is Overflow";
            }
        }

        int pop1(){
            if (!empty1()){
                int temp = top1;
                top1--;
                return arr[temp];
            }else{
                return -1;
            }
        }
        int pop2(){
            if (!empty2()){
                int temp = top2;
                top2++;
                return arr[top2];
            }else{
                return -1;
            }
        }
};

int main(){

    return 0;
}
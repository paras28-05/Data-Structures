// Implementation of two stacks using an array

#include <iostream>
using namespace std;

class TwoSatck{
    private:
        int top1;
        int top2;
        int size;
        int* arr;

    public:
        TwoSatck(int size){
            this->size = size;
            top1 = -1;
            top2 = -1;
            arr = new int[2*size];
        }

        bool isEmpty1(){
            return top1 == -1;
        }

        bool isEmpty2(){
            if 
        }

        bool isFull1(){
            return this->top1 == ((this->size)/2)-1;
        }

        bool isFull2(){
            return this->top2 == (this->size)-1;
        }

        void push1(int data){
            if (isFull1()){
                cout << "Stack 1 is OverFlow" << endl;
            }else{
                top1++;
                arr[top1] = data;
            }
        }

        void push2(int data){
            if (isFull2()){
                cout << "Stack 2 is OverFlow" << endl;
            }else if (isEmpty2()){
                top2 = (this->size)/2;
                arr[top2] = data;
            }else{
                top2++;
                arr[top2] = data;
            }
        }

        int pop1(){
            if (isEmpty1()){
                cout << "Stack 1 is UnderFlow" << endl;
                return -1;
            }else{
                top1--;
                return arr[top1+1];
            }
        }

        int pop2(){
            if (isEmpty2()){
                cout << "Stack 2 is UnderFlow" << endl;
                return -1;
            }else{
                top2--;
                return arr[top2+1];
            }
        }

        void print1(){
            if (isEmpty1()){
                cout << "Stack 1 is UnderFlow" << endl;
            }else{
                for(int i=this->top1 ; i>=0 ; i--){
                    cout << arr[i] << endl;
                }
            }
        }

        void print2(){
            if (isEmpty2()){
                cout << "Stack 2 is UnderFlow" << endl;
            }else{
                for(int i=this->top2 ; i>= (this->size)/2 ; i--){
                    cout << arr[i] << endl;
                }
            }
        }
};

int main(){
    TwoSatck reg(3);
    reg.push1(1);
    reg.push1(2);
    reg.push2(100);
    reg.push2(200);
    reg.push2(300);
    reg.print1();
    cout << "------------------------" << endl;
    reg.print2();
    return 0;
}
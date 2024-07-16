#include <iostream>
using namespace std;

void update(int** ptr){
    // ptr = ptr + 1;
    // *ptr = *ptr + 1;
    **ptr = **ptr + 1;
}

int main(){
    int num = 5;
    int* ptr = &num;
    int** ptr2 = &ptr;
    cout << "ptr2 (it will print address stored in it means address of ptr)" << ptr2 << endl;
    cout << "*ptr2 (it will print value of adddress ptr stores , address of num)" << *ptr2 << endl;
    cout << "**ptr2 , it will update numb value : " << **ptr2 << endl;
    
    update(ptr2);

    cout << "Assumption(should inc by 8 bytes)" <<  ptr2 << endl;
    cout << "assumption (should  inc by 8 bytes)" << *ptr2 << endl;
    cout << "asumption 6 : " << **ptr2 << endl;
    return 0;
}
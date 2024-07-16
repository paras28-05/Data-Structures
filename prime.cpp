#include <iostream>
using namespace std;

bool isPrime(int numb);
int no_of_prime(int numb);

int main(){
    int numb;
    cout << "Enter a Number : ";cin >> numb;
    cout << no_of_prime(numb) << endl;
    return 0;
}

bool isPrime(int numb){

    if (numb <=1){
        return false;
    }
    for (int i=2;i<numb;i++){
        if (numb%i == 0)
            return false;
    }
    return true;
}

int no_of_prime(int numb){
    int no_of_prime = 0;
    for (int i=2;i < numb;i++){
        for (int j=2;j<i;j++){
            if (i%j == 0){
                break;
            }else{
        }
        }
        no_of_prime++;
    }
    return no_of_prime;
}
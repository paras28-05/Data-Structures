#include <iostream>
using namespace  std;

void row_sum(int arr[][4] , int rows , int cols);
void col_sum(int arr[][4] , int rows , int cols);
int largest_row_sum(int arr[][4] , int rows , int cols);

int main(){
    int arr[][4] = {{1,2,3,4} , {1,2,5,4} , {56,3,1,0} , {45,3,2,5}};
    row_sum(arr , 4,4);
    col_sum(arr,4,4);
    cout << "Largest Index Row : " << largest_row_sum(arr , 4,4);
    return 0;
}

void row_sum(int arr[][4] , int rows , int cols){
    int row_sum_arr[rows];
    for (int i=0;i<rows;i++){
        row_sum_arr[i] = 0;
        for (int j=0 ; j<cols ; j++){
            row_sum_arr[i] += arr[i][j];
        }
    }
    for (int i=0 ; i<rows ; i++){
        cout << row_sum_arr[i] << " ";
    }
    cout << endl;
}

void col_sum(int arr[][4] , int rows , int cols){
    int temp[cols];
    for(int i=0;i<cols;i++){
        temp[i] = 0;
        for (int j=0;j<rows;j++){
            temp[i]+=arr[j][i];
        }
    }
    for (int i=0;i<cols;i++){
        cout << temp[i] << " ";
    }
    cout << endl;
}

int largest_row_sum(int arr[][4] , int rows , int cols){
    int row_sum_arr[rows];
    for (int i=0;i<rows;i++){
        row_sum_arr[i] = 0;
        for (int j=0 ; j<cols ; j++){
            row_sum_arr[i] += arr[i][j];
        }
    }
    int max = row_sum_arr[0];
    int index = 0;
    for (int i =0 ; i<rows ; i++){
        if (max < row_sum_arr[i]){
            max = row_sum_arr[i];
            index = i;
        }
    }
    return index;
}
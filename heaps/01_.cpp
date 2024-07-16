#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k_smallest_int(vector<int> arr , int k){

    priority_queue <int> pq;

    // step 1 , creating max heap of first k elemets of array
    for (int i=0 ; i<k ; i++){
        pq.push(arr[i]);
    }

    // step 2 , comparing remaining elemets with top of heap
    for (int i=k ; i<arr.size() ; i++){
        if (arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();

    return ans; 
}

int main(){

    return 0;
}
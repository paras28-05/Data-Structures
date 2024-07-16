#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void solve(queue<int> &q){
    if (q.empty()){
        return ;
    }
    int numb = q.front();
    q.pop();
    solve(q);
    q.push(numb);
}

queue<int> reverse(queue<int> &q){
    solve(q);
    return q;
}

vector<int> find_first_negative_element_in_k_size_window_in_array(vector<int> arr, int window_size) {
    vector<int> ans;

    for (int i = 0; i <= arr.size() - window_size; i++) {
        bool found = false;
        for (int j = i; j < i + window_size; j++) {
            if (arr[j] < 0) {
                ans.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            ans.push_back(-1);
        }
    }

    return ans;
}

queue<int> reverse_first_k_elements(queue<int> q, int k){
    queue<int> ans;
    stack<int> temp_stack;

    while(!q.empty()){
        for (int  i=0 ; i<k; i++){
        int numb = q.front();
        q.pop();
        temp_stack.push(numb);
    }

    while(!temp_stack.empty()){
        int numb = temp_stack.top();
        temp_stack.pop();
        ans.push(numb);
    }
    }
    return ans;
    
}

string first_non_repeating_char_in_stream(string str){
    stack<char> temp_stack;

    for (int i=0 ; i<str.length() ; i++){
        if (temp_stack.empty() == true){
            temp_stack.push(str[i]);
        }else{
            if(temp_stack.top() == str[i]){
                temp_stack.push('#');
            }else{
                temp_stack.push(str[i]);
            }
        }
    }
    string ans= "";
    while(!temp_stack.empty()){
        char ch = temp_stack.top();
        temp_stack.pop();
        ans.push_back(ch);
    }

    stack<char> s;
    for (int i=0 ; i<ans.length() ; i++){
        s.push(ans[i]);
    }

    string final = "";
    while(!s.empty()){
        char ch = s.top();
        s.pop();
        final.push_back(ch);
    }
    return final;
}   

queue<int> rearrange(queue<int> q){
    queue<int> q1;
    queue<int> ans;

    int s = q.size();

    for(int i=0; i<s/2 ; i++){
        int temp = q.front();
        q.pop();
        q1.push(temp);
    }

    int size = q.size();

    while(!q1.empty()){
        int temp1 = q1.front();
        q1.pop();
        ans.push(temp1);

        int temp2 = q.front();
        q.pop();
        ans.push(temp2);
    }

    return ans;




}

int min_max_problem(vector<int> arr , int window_size){
    vector<int> max_arr;
    vector<int> min_arr;

    for (int i=0 ; i<= arr.size()-window_size ; i++){
        int temp_max = arr[i];
        int temp_min = arr[i];
        for (int j=i ; j<i+window_size ; j++){
            if (temp_max < arr[j]){
                temp_max = arr[j];
            }
            if (temp_min > arr[j]){
                temp_min = arr[j];
            }
        }
        max_arr.push_back(temp_max);
        min_arr.push_back(temp_min);
    }

    int temp_min_sum = 0;
    int temp_max_sum = 0;

    for (int i=0 ; i<max_arr.size() ; i++){
        temp_max_sum += max_arr[i];
    }

    for (int i=0 ; i<min_arr.size() ; i++){
        temp_min_sum += min_arr[i];
    }

    return temp_max_sum + temp_min_sum;


}

int main(){
    // vector<int> arr;
    // arr.push_back(-8);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(-6);
    // arr.push_back(10);

    // vector<int> ans = find_first_negative_element_in_k_size_window_in_array(arr , 4);

    // for (int i=0 ; i<ans.size() ; i++){
    //     cout << ans[i] << " ";
    // }

    // cout << first_non_repeating_char_in_stream("aabbcdee");

    // queue<int> q;
    // q.push(11);
    // q.push(12);
    // q.push(13);
    // q.push(14);
    // q.push(15);
    // q.push(16);
    // q.push(17);
    // q.push(18);

    // queue<int> ans = rearrange(q);

    // while(!ans.empty()){
    //     int temp = ans.front();
    //     ans.pop();
    //     cout << temp << " ";
    // }

    vector<int> arr ;
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(-1);
    arr.push_back(7);
    arr.push_back(-3);
    arr.push_back(-1);
    arr.push_back(-2);

    cout << min_max_problem(arr , 4);



    return 0;
}
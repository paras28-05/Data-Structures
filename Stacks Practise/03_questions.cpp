#include <iostream>
#include <stack>
using namespace std;

string reverse(string str){
    stack<char> s;
    char ch = '\0';
    s.push(ch);

    for (int i=0 ; i<str.size() ; i++){
        char ch = str[i];
        s.push(ch);
    }

    string temp_str = "";

    while(!s.empty()){
        char ch = s.top();
        temp_str.push_back(ch);
        s.pop();
    }

    return temp_str;
}

stack<int> delete_middle(stack<int> &s){
    int temp;
    if (s.size()%2 == 0){
        temp = (s.size()/2)-1;
    }
    temp = s.size()/2;

    stack<int> temp_stack;
    for(int i=0 ; i<temp ; i++){
        int temp_no = s.top();
        s.pop();
        temp_stack.push(temp_no);
    }
    s.pop();

    while(!temp_stack.empty()){
        int temp_no = temp_stack.top();
        temp_stack.pop();
        s.push(temp_no);
    }

    return s;
}

bool valid_paranthesis(string str){
    stack<char> s;
    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        if (ch == '[' || ch == '{' || ch == '('){
            s.push(ch);
        }
        else{
            s.pop();
        }
    }

    return s.empty();
}

stack<int> insert_at_bottom_of_stack(stack<int> s , int data){
    // stack<int> ans;
    if (s.empty()){
        s.push(data);
        return s;
    }

    int numb = s.top();
    s.pop();
    insert_at_bottom_of_stack(s , data);
    s.push(numb);

    return s;
}

stack<int> reverse_stack_using_recursion(stack<int> s){
    // stack<int> ans;
    if (s.empty()){
        return s;
    }

    int numb = s.top();
    s.pop();
    stack<int> temp = reverse_stack_using_recursion(s);
    s = insert_at_bottom_of_stack(temp , numb);
    return s;
}

void sorted_insert(stack<int> &s , int numb){
    if ((numb > s.top())  || s.empty()){
        s.push(numb);
        return ;
    }
    int n = s.top();
    s.pop();
    sorted_insert(s , numb);
    s.push(n);
}

void solve(stack<int> &s){
    if(s.empty()){
        return ;
    }
    int numb = s.top();
    s.pop();
    solve(s);  // Corrected: 's' is passed by reference, so changes affect the original stack
    sorted_insert(s , numb);  // Corrected: 's' is passed by reference to maintain changes
}


stack<int> sort(stack<int> s){
    solve(s);
    return s;
}

bool check_redundant_brackets(string str){
    stack<char> s;
    for (int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        if (ch == '[' || ch == '{' || ch == '(' || ch == '/' || ch== '*' || ch == '+' || ch == '-'){
            s.push(ch);
        }else if (ch == ']' || ch == '}' || ch == ')'){
            char top_ch = s.top();
            if (top_ch == '+' || top_ch == '-' || top_ch == '*' || top_ch == '/'){
                s.push(ch);
            }else if (top_ch == ')' || top_ch == ']' || top_ch == '}'){
                return true;
            }
        }
    }
    return false;
}

int main(){
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);


//     delete_middle(s);

    // stack<int> ans = sort(s );

    // while(!ans.empty()){
    //     cout << ans.top() << " ";
    //     ans.pop();
    // }

    string s = "[a+(n-c)]";
    cout << check_redundant_brackets(s);

    return 0;
}
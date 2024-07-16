#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node* head;
    public:
        // LinkedList() {
        //     this->head = new Node;
        //     this->head->next = NULL;
        //     this->head->data;
        //     cout << "Sab set hai.";
        // }
        LinkedList(int data){
            this->head = new Node;
            this->head->next = NULL;
            this->head->data = data;
            // head -> data = data;
            // head -> next = NULL;
        }
        void insert_at_head(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = this->head;
            this->head = newNode;
        }
        void insert_at_tail(int data){
            Node* current;
            current = this->head;
            while(current->next != NULL){
                current = current->next;
            }
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;
            // cout << current->next << endl;
            current->next = newNode;
            current = current->next;

        }
        void insert(int data , int index){
            Node* current = this->head;
            int totalNodes = 1;
            while(current->next != NULL){
                current = current->next;
                totalNodes++;
            }
            if (index == 0){
                this->insert_at_head(data);
            }else if(index >= totalNodes){
                this->insert_at_tail(data);
            }else{
                Node* newNode = new Node;
                newNode->data = data;
                Node* current =this->head;
                for (int i=0;i<index-1;i++){
                    current = current->next;
                }
                newNode->next= current->next;
                current->next = newNode;
            }
        }

        // returns index of given value
        int search_by_value(int data){
            Node* current = this->head;
            int index=0;
            while(current != NULL){
                if (current->data == data)
                    return index;
                else{
                    current = current->next;
                    index++;
                }
            }
            return -1;
        }
        int search_by_index(int index){
            Node* current = this->head;
            int totalNodes = 0;
            while(current != NULL){
                totalNodes++;
                current = current->next;
            }
            if (index >= totalNodes){
                return -1;
            }
            else{
                current = this->head;
                for (int i=0;i<index;i++){
                    current = current->next;
                }
                return current->data;
            }
        }
        int delete_at_head(){
            Node* temp = this->head;
            head = temp->next;
            int value = temp->data;
            delete temp;
            return value;
        }
        // error is coming
        int delete_at_tail(){
            Node* current = this->head;
            Node* current_prev = this->head;
            while(current->next != NULL){
                current = current->next;
            }
            while(current->next->next != NULL){
                current_prev = current_prev->next;
            }
            current_prev->next =NULL;
            int value = current->data;
            delete current;
            return value;
        }

        int deleteNode(int index){
            Node* current = new Node;
            int totalNodes=0;
            while(current != NULL){
                totalNodes++;
            }
            return totalNodes;
            // if (index >= totalNodes){
            //     return -1;
            // }else{
            //     current = this->head;
            //     for (int i=0 ; i<index;i++){
            //         current = current->next;
            //     }
            //     Node* temp = current->next;
            //     current->next = current->next->next;
            //     int value = temp->data;
            //     delete temp;
            //     return value;
            // }
        }
        void print(){
            Node* current;
            current = this->head;
            while(current != NULL){
                cout << current->data << endl;
                current = current->next;
            }
        }
};


int main(){
    LinkedList  list(23432);
    list.insert_at_head(1200);
    list.insert(43,0);
    list.insert(54,5);
    list.insert(67,2);
    list.insert(1,11);
    list.insert(45,4);

    // list.insert_at_head(34543);
    // list.insert_at_head(6436);
    // list.insert_at_head(456);
    // list.insert_at_tail(1200);
    // list.insert_at_tail(4354);
    // list.insert_at_tail(324);


    // cout << list.head->data << endl;
    // cout << "yeh chal rha." << endl;
    list.print();
    // cout << list.search_by_value(121323) << endl;
    // cout << list.search_by_index(6) << endl; 
    list.delete_at_head();
    cout << "Aftr " << endl;
    list.print();
    cout << "After deltnvi" << endl;
    cout <<list.deleteNode(2) << endl;
    list.print();


    return 0;
}
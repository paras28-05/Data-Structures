#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList{
    private:
        Node* head;
    public:
        DoublyLinkedList(int data) {
            this->head = new Node;
            this->head->data = data;
            this->head->next = NULL;
            this->head->prev = NULL;
        }

        void insert_at_head(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = this->head;
            this->head->prev = newNode;
            newNode->prev = NULL;
            this->head = newNode;
        }

        void insert_at_tail(int data){
            Node* newNode = new Node;
            newNode->data = data;
            Node* current = this->head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            newNode->next = NULL;

        }
        void insert(int data , int index){
            // Node* newNode = new Node;
            Node* temp = this->head;
            int totalNodes = 1;
            while(temp->next != NULL){
                totalNodes++;
                temp = temp->next;
            }
            if (index <= 0){
                this->insert_at_head(data);
            }else if(index >= totalNodes){
                this->insert_at_tail(data);
            }else{
                Node* current = this->head;
                for (int i=0 ; i<index-1;i++){
                    current = current->next;
                }
                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = current->next;
                newNode->prev = current;
                Node* temp = current;
                temp = current->next;
                temp->prev = newNode;
                current->next = newNode;
            }
        }
        // returns index;
        int search_by_value(int data){
            Node* temp = this->head;
            int temp_index = 0;
            while(temp != NULL){
                if (temp->data == data){
                    return temp_index;
                }else{
                    temp_index++;
                    temp = temp->next;
                }
            }
            return -1;
        }
        // returns value of that index
        int search_by_index(int index){
            Node* temp = this->head;
            int totalNodes = 1;
            while(temp->next != NULL){
                totalNodes++;
                temp = temp->next;
            }
            if (index <= 0){
                return this->head->data;
            }
            else if (index >= totalNodes){
                return -1;
                }
                else{
                Node* temp = this->head;
                for (int i=0 ; i<index ; i++){
                    temp = temp->next;
                }
                return temp->data;
            }
        }

        int delete_at_head(){
            Node* temp = this->head;
            this->head = this->head->next;
            this->head->prev = NULL;
            temp->next = NULL;
            int value = temp->data;
            delete temp;
            return value;
        }
        // int delete_at_tail(){
        //     Node* temp = this->head;
        //     while(temp != NULL){
        //         temp = temp->next;
        //     }
        //     Node* temp_prev = temp->prev;
        //     temp_prev->next = NULL;
        //     temp->prev = NULL;
        //     int value = temp->data;
        //     delete temp;
        //     return value;
        // }

        int delete_at_tail() {

        Node* temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        int value = temp->data;
        
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            this->head = NULL; // If there was only one node
        }

        delete temp;
        return value;
    }
        // function to delte node by value
        // function to delte node by index
        void print(){
            Node* current = this->head;
            while(current != NULL){
                cout << current->data << endl;
                current = current->next;
            }
        }
};

int main(){
    DoublyLinkedList list(121);
    list.insert_at_head(344);
    list.insert_at_tail(34432);
    list.insert(100,2);
    list.print();
    // cout << list.search_by_value(34432) << endl;
    // cout << list.search_by_index(4) << endl;
    cout << list.delete_at_tail() << endl;
    cout << "after deleting" << endl;
    list.print();

    return 0;
}
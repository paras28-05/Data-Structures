#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TrieNode{
    public : 
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            this->data = ch;
            for (int i=0 ; i<26 ; i++){
                this->children[i] = nullptr;
            }
            this->isTerminal = false;
        }
};


class Trie{
    public:
        TrieNode* root;
        Trie(){
            this->root = new TrieNode('\0');
        }

        void insert_util(string word , TrieNode* root){
            // base case
            if (word.length() == 0){
                root->isTerminal = true;
                return ;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if (root->children[index] != nullptr){
                child = root->children[index];
            }else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insert_util(word.substr(1),child);
        }

        void insert_word(string word){
            insert_util(word , this->root);
        }

        bool search_util(string word , TrieNode* root){
            if (word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if (root->children[index] != nullptr){
                child = root->children[index]; 
            }else{
                return false;
            }

            return search_util(word.substr(1) , child);
        }

        bool search(string word){
            return search_util(word , this->root);
        }
};

int main(){
    Trie *t = new Trie();
    t->insert_word("PIYUSH");
    t->insert_word("AAYUSH");
    t->insert_word("PUSHPA");
    t->insert_word("SATISH");
    t->insert_word("GOYAL");

    cout << "Present or not : " << t->search("PIYU") << endl;
    return 0;
}
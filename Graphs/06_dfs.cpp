#include<iostream>
#include<unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adj_list;
        void add_edge(int u , int v){
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        void gen_tree(int no_nodes){
            for (int i=0 ; i<no_nodes ; i++){
                int u , v;
                cout << "Enter u :"; cin >> u;
                cout << "Enter v :"; cin >> v;
                add_edge(u,v);
            }
        }
        unordered_map<int , list<int>> get_graph(){
            return adj_list;
        }

        void print(){
            for (auto i : adj_list){
                cout << i.first << "->";
                for (auto j:i.second){
                    cout << j << " ";
                }cout << endl;
            }
        }
};

vector<vector<int>> dfs()

int main(){
    Graph g;
    g.gen_tree(5);
    g.print();
    return 0;
}
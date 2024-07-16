#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int>> adj_list;

        void add_edje(int u , int v , bool is_directed){
            // is_directed -> 1 : true : directed graph
            // is_directded -> 0 :fale : undirected graph
            adj_list[u].push_back(v);
            if (!is_directed){
                adj_list[v].push_back(u);
            }
        }

        void print(){
            for(auto i : adj_list){
                cout << i.first << "->" ;
                for (auto j : i.second){
                    cout << j << " ";
                }cout << endl;
            }
        }

        unordered_map<int ,  list<int>> get_adj_list(){
            return adj_list;
        }
        unordered_map<int , list<int>> gen_graph(int no_nodes){
            for (int i=0 ; i<no_nodes ; i++){
                int u , v;
                cin >> u;
                cin >> v;
                add_edje(u , v , false);
            }
            return adj_list;
        }
};

void print(unordered_map<int , list<int>> adj_lsit){
    for (auto i : adj_lsit){
        cout << i.first << " ->";
        for (int j:i.second){
            cout << j << " ";
        }cout << endl;
    }
}

int main(){
    Graph g;
    int no_nodes;
    cout << "Enter no of nodes : "; cin >> no_nodes;
    unordered_map<int , list<int>>adj_list = g.gen_graph(no_nodes);
    cout << "Class print : " << endl;
    g.print();
    cout << "Outside class print: " << endl;
    print(adj_list);
    return 0;
}
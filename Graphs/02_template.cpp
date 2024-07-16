#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
template <typename T>

class Graph{
    public:
        unordered_map<T , list<T>> adj;

        void add_edje(T u , T v , bool is_directed){
            // is_directed : 1 -> directed graph
            // is_directed : 0 -> undirected graph

            // create an edje from u to v
            adj[u].push_back(v);
            if (!is_directed){
                adj[v].push_back(u);
            }
        }

        void print_adj_list(){
            for (auto i : adj){
                cout << i.first << "->";
                for (auto j : i.second){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int nodes;
    cout << "Enter no of nodes : "; cin >> nodes;

    int edges;
    cout << "Enter number of edges : "; cin >> edges;
    Graph<char> g;
    for (int i=0 ; i<edges ; i++){
        char u , v;
        cout << "Enter u : "; cin >> u;
        cout << "Enter v : "; cin >> v;
        g.add_edje(u , v , false);
    }

    g.print_adj_list();
    return 0;
}
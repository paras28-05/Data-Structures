#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int>> adj_list;
        vector<vector<int>> edges;
        vector<vector<int>> make_edges(int no_nodes , int no_edges){
            edges.resize(no_edges , vector<int>(2));
            for (int i=0 ; i<no_edges ; i++){
                int u , v;
                cin >> u >> v;
                edges[i][0] = u;
                edges[i][1] = v;
            }
            return edges;
        }
};

unordered_map<int ,list<int>> make_adj_list(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<int>> adj_list;

    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
    }

    return adj_list;
}

vector<int> top_sort_bfs(vector<vector<int>> edges , int no_nodes , int no_edges){

    unordered_map<int , list<int>> adj_list = make_adj_list(edges , no_nodes , no_edges);
    // finding all indegress
    vector<int>indegree[no_nodes];

    for (auto i:adj_list){
        for (auto j:i.second){
            indegree[j]++;
        }
    }

    
}

int main(){
    Graph g;
    int no_nodes;
    int no_edges;
    vector<vector<int>> edge_mat = g.make_edges(no_nodes , no_edges);

    unordered_map<int , list<int>> adj_list = make_adj_list(edge_mat , no_nodes , no_edges);

    for (auto i : adj_list){
        cout << i.first << "->";
        for (auto j:i.second){
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}

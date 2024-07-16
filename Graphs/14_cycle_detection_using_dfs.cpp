#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int>> adj_list;
        vector<vector<int>> edges;

        vector<vector<int>> make_edges(int no_nodes , int no_edges){
            edges.resize(no_edges , vector<int>(2));
            for(int i=0 ; i<edges.size() ; i++){
                int u , v;
                cin >> u;
                cin >> v;
                edges[i][0] = u;
                edges[i][1] = v;

                // adj_list[u].push_back(v);
                // adj_list[v].push_back(u);
            }
            return edges;
        }
};

unordered_map<int ,list<int>> make_adj_mat(vector<vector<int>> edges , int nodes , int no_edges ){

    unordered_map <int , list<int>> adj_list;
    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    return adj_list;
}

bool dfs(int node , int parent,unordered_map<int , list<int>> &adj_list ,  unordered_map<int , bool> &is_visited){
    is_visited[node] = true;
    for (auto i : adj_list[node]){
        if (!is_visited[i]){
            bool cycle_detected = dfs(i , node , adj_list , is_visited);
            if (cycle_detected)
                return true;
        }else if(i != parent){
            return true;
        }
    }
    return false;
}

string is_cyclic_dfs(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<int>> adj_list = make_adj_mat(edges , no_nodes ,no_edges );
    unordered_map<int , bool> is_visited;

    for (int i = 0 ; i<no_nodes ; i++){
        if (!is_visited[i]){
            bool ans = dfs(i ,-1, adj_list , is_visited );
            if (ans)
                return "Yes";
        }
    }
    return "No";
}

int main(){
    Graph g;
    int nodes = 3;
    int edges = 3;
    vector<vector<int>> edge_mat = g.make_edges(nodes , edges);

    for (int i =0 ; i<edge_mat.size() ; i++){
        cout << edge_mat[i][0] << " " << edge_mat[i][1] << endl; 
    }

    unordered_map<int , list<int>> adj_mat = make_adj_mat(edge_mat , nodes , edges);

    for (auto i : adj_mat){
        cout << i.first << "->";
        for (int j:i.second){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << is_cyclic_dfs(edge_mat , nodes , edges) << endl;
    return 0;
}
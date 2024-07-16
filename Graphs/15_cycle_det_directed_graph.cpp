#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int>> adj_list;
        vector<vector<int>> edges;
        // creation of directed graph only;
        vector<vector<int>> make_edge(int no_nodes , int no_edges){
            edges.resize(no_edges , vector<int>(2));
            for (int i=0 ; i<no_edges ; i++){
                int u ,v;
                cin >> u >> v;
                edges[i][0] = u;
                edges[i][1] = v;
            }
            return edges;
        }
};

unordered_map<int , list<int>> gen_adj_list(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<int>> adj_list;
    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
    }
    return adj_list;
}

bool detect_cycle(int node ,unordered_map<int , bool> &dfs_visited , unordered_map<int , list<int>> &adj_list ,unordered_map<int , bool> &is_visited ){
    is_visited[node] = true;
    dfs_visited[node] = true;

    for (auto neighbour : adj_list[node]){
        if (is_visited[neighbour] == false){
            bool smallans = detect_cycle(neighbour , dfs_visited , adj_list , is_visited);
            if (smallans)
                return true;
        }
        else if(dfs_visited[neighbour] == true , is_visited[neighbour] == true){
            return true;
        }
    }
    dfs_visited[node] = false;
    return false;
}

string detect_cycle_in_directd_graph(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<int>> adj_list = gen_adj_list(edges , no_nodes , no_edges);
    unordered_map<int , bool> is_visited;
    unordered_map<int , bool> dfs_visited;


    for (int i=0 ; i<no_nodes ; i++){
        if (!is_visited[i]){
            bool ans = detect_cycle(i , dfs_visited , adj_list , is_visited);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}

int main(){
    Graph g;
    int no_nodes = 8;
    int no_edges = 9;
    vector<vector<int>> edge_mat = g.make_edge(no_nodes , no_edges);

    for (int i=0 ; i < edge_mat.size() ; i++){
        cout << edge_mat[i][0] << " " << edge_mat[i][1] << endl;
    }

    unordered_map<int , list<int>> adj_list = gen_adj_list(edge_mat , no_nodes , no_edges);
    for (auto i : adj_list){
        cout << i.first << "->" ;
        for (auto j : i.second){
            cout << j << " ";
        }cout << endl;
    }

    cout << "Cycle Present : ";
    cout << detect_cycle_in_directd_graph(edge_mat , no_nodes , no_edges) << endl;
    return 0;
}
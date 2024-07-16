// cycle detection in graph using dfs and bfs

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    public:
    unordered_map<int , list<int>> adj_list;
    vector<vector<int>> edges1;
    vector<pair<int , int>> edges2;

    vector<vector<int>> make_edges(int no_nodes , int no_edges){
        edges1.resize(no_edges , vector<int>(2));
        edges2.resize(no_edges);
        for (int i=0 ; i<no_edges ; i++){
            int u ,v;
            cin >> u;
            cin >> v;

            edges1[i][0] = u;
            edges1[i][1] = v;

            edges2[i].first = u;
            edges2[i].second = v;
        }

        return edges1;
    }

    unordered_map<int , list<int>> make_adj_list(vector<vector<int>> edges , int no_nodes , int no_edges){
        for (int i=0 ; i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        return adj_list;
    }
};

bool isCycleBFS(int node , unordered_map<int , list<int>> &adj_list ,unordered_map<int , bool> &is_visited){
    unordered_map<int , int> parent;
    parent[node] = -1;
    is_visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // find its neighbours

        for (auto i : adj_list[frontNode]){
            if (is_visited[i] == true && i != parent[frontNode]){
                return true;
            }else if (!is_visited[i] ){
                q.push(i);
                is_visited[i] = true;
                parent[i] = frontNode;
            }
        }
    }
    return false;

}

string cycle_detection(vector<vector<int>> edges , int no_nodes , int no_edges){
    //create adj_list (undirected graph)

    unordered_map<int , list<int>> adj_list;
    unordered_map<int , bool> is_visited;

    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // to handle disconnected graph
    for (int i=0 ; i<no_nodes ; i++){
        if (!is_visited[i]){
            bool ans = isCycleBFS(i , adj_list , is_visited );
            if (ans){
                return "Yes";
            }
        }
    }
    return "No";
}


int main(){
    Graph g;
    int nodes = 5;
    int edges = 6;
    vector<vector<int>> edges_mat = g.make_edges(nodes , edges);

    // for (auto i : edges_mat){
    //     for (auto j : i){
    //         cout << j << " ";
    //     }cout << endl;
    // }

    unordered_map<int , list<int>> adj_mat = g.make_adj_list(edges_mat , nodes , edges);

    for (auto i : adj_mat){
        cout << i.first << "->";
        for (auto j : i.second){
            cout << j << " ";
        }cout << endl;
    }

    cout << cycle_detection(edges_mat , nodes , edges);
    return 0;
}
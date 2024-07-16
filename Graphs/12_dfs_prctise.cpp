#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph{
    public:
    unordered_map<int , list<int>> adj_list;
    vector<vector<int>> edges;
    int no_nodes;

    vector<vector<int>> make_edges(int no_nodes , int no_edges){
        edges.resize(no_edges , vector<int>(2));
        this->no_nodes = no_nodes;
        for (int i=0 ; i<no_edges ; i++){
            int u , v;
            cin >> u;
            cin >> v;
            edges[i][0] = u;
            edges[i][1] = v;
        }
        return edges;
    }
};

void dfs(int node , unordered_map<int , list<int>> &adj_list ,unordered_map<int , bool> &is_visited , vector<int> &component){
    is_visited[node] = true;
    component.push_back(node);
    // adj_list[node];
    for (auto i:adj_list[node]){
        if(!is_visited[i]){
            dfs(i , adj_list , is_visited , component);
        }
    }
}

vector<vector<int>> dfs_trav(vector<vector<int>> edges , int nodes ,int no_edges){
    unordered_map<int , list<int>> adj_list;
    unordered_map<int , bool> is_visited;
    vector<vector<int>> ans;
    // creation of adj_list
    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // this is required to adjust the problemm of disconnected graphs
    for (int i=0 ; i<nodes ; i++){
        if(!is_visited[i]){
            vector<int> component;
            dfs(i , adj_list , is_visited , component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    Graph g;
    vector<vector<int>> edges = g.make_edges(5,4);
    cout << "Output" << endl;
    for(int i=0 ; i<edges.size() ; i++){
        cout << edges[i][0] << " " << edges[i][1] << endl;
    }

    vector<vector<int>>ans = dfs_trav(edges , 5,4);
    cout << "Dfs traversal" << endl;
    // for(int i=0 ; i<ans.size() ; i++){
    //     for (int j=0 ; j<ans[i].size() ; i++){
    //         cout << ans[i][j] << " " ;
    //     }cout << endl;
    // }

    for (auto component : ans) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
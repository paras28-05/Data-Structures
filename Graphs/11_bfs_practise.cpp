#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
// use set instead of list for sorted traversal

class Graph{
    public:
        vector<vector<int>> adj_list;
        vector<vector<int>> edges;
        int no_nodes;

        vector<vector<int>> add_edges(int no_of_nodes, int no_edges) {
            no_nodes = no_of_nodes;
            edges.resize(no_edges); // Resize the edges vector to the number of edges
            for (int i = 0; i < no_edges; i++) {
                int u, v;
                cin >> u;
                cin >> v;
                edges[i].push_back(u);
                edges[i].push_back(v);
            }
            return edges;
        }
};

void bfs(int node , unordered_map<int , list<int>> &adj_list , unordered_map<int , bool> &is_visited , vector <int> &ans){
    queue<int> q;
    q.push(node);
    is_visited[node] = 1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        adj_list[frontNode];
        for (auto i : adj_list[frontNode]) {
            if(!is_visited[i]){
                q.push(i);
                is_visited[i] = 1;
            }            
        }
    }
}

vector<int> bfs_trav(vector<pair<int , int>> edges ,int no_edges, int nodes){
    vector <int> ans;
    unordered_map<int , list<int>> adj_list;
    unordered_map<int , bool> is_visited;

    for (int i=0;i<no_edges ; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);}

        // traversing all components og graph
        for (int i =0 ; i<nodes ; i++){
            if(!is_visited[i]){
                bfs(i , adj_list , is_visited , ans);
            }
        }
    

    return ans;
}

int main(){
    // Graph g;
    // int nodes , edges;
    // cout << "Nodes : ";cin >> nodes;
    // cout <<"Edges : "; cin >> edges;
    // vector<vector<int>>edges_mat = g.add_edges(nodes, edges);
    // for (int i=0 ; i<edges_mat.size() ; i++){
    //     cout << edges_mat[i][0] <<  " " << edges_mat[i][1] << endl;
    // }

    vector<pair<int,int>> edges;
    // edges.push_back(make_pair(4,3));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(1,3));

    vector<int> ans = bfs_trav(edges ,3, 4);
    for (int i =0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }


    return 0;
}
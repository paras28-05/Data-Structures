#include <iostream>
#include <unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int>> adj_list;
        vector<vector<int>> edges;

        vector<vector<int>> make_edges(int no_nodes , int no_edges){
            edges.resize(no_edges , vector<int>(2));
            for (int i=0 ; i<no_edges ; i++){
                int u , v;
                cin >>u >> v;

                edges[i][0] = u;
                edges[i][1] = v;
            }

            return edges;
        }
};

unordered_map<int, list<int>> make_adj_list(vector<vector<int>> edges , int no_nodes , int no_edges){

    unordered_map<int , list<int>> adj_list;
    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // undirected graph
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    return adj_list;
}

vector<int> shortest_path(vector<vector<int>> edges , int no_nodes , int no_edges , int src , int dest){

    unordered_map<int , list<int>> adj_list = make_adj_list(edges , no_nodes , no_edges);
    unordered_map<int , bool> is_visited;
    unordered_map<int , int>parent;
    queue<int> q;

    q.push(src);
    is_visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for (auto i:adj_list[frontNode]){
                if (!is_visited[i]){
                    q.push(i);
                    is_visited[i] = true;
                    parent[i] = frontNode;
                }
    }
    }

    // preparing shortest path
    stack<int>ans;
    int currentNode = dest;

    ans.push(currentNode);

    while(currentNode != src){
        currentNode = parent[currentNode];
        ans.push(currentNode);
    }
    // ans.push(src);

    vector<int> result;
    while(!ans.empty()){
        int ele = ans.top();
        result.push_back(ele);
        ans.pop();
    }

    return result;
    
}


int main(){
    Graph g;
    int no_nodes = 8;
    int no_edges = 9;
    vector<vector<int>>edge_mat = g.make_edges(no_nodes , no_edges);

    for (int i=0 ; i<edge_mat.size() ; i++){
        cout << edge_mat[i][0] << " " << edge_mat[i][1] << endl;
    }

    unordered_map<int , list<int>> adj_mat = make_adj_list(edge_mat , no_nodes , no_edges);

    for (auto i : adj_mat){
        cout << i.first << "->";
        for (auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }

    int src=0;
    int dest = 7;
    vector<int> ans = shortest_path(edge_mat , no_nodes , no_edges , src , dest);
    for (int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}
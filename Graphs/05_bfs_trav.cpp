#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

class Graph{
    public:
        unordered_map<int , list<int>> adj;

        void add_edje(int u , int v , bool is_directed){
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
        unordered_map<int , list<int>> get_graph(){
            return adj;
        }
};

void prepare_adj_list(unordered_map<int , set<int>> &adj_list , vector<pair<int , int>>&edges){
    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj_list[u].insert(v);
        adj_list[v].insert(u);

    }
}

void bfs(unordered_map<int , set<int>> &adj_list ,unordered_map<int,bool> &is_visited , vector<int> &ans , int node ){
    queue<int> q;
    q.push(node);
    is_visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // traverse neighbours of node
        for (auto i:adj_list[frontNode]){
            if (!is_visited[i]){
                q.push(i);
                is_visited[i] = true;
            }
        }
    }

}

vector<int> bfs_trav(int no_nodes , vector<pair<int , int>>edges){

    // create adjancency list
    vector<int> ans;
    unordered_map<int , set<int>> adj_list;
    unordered_map<int,bool> is_visited;

    prepare_adj_list(adj_list , edges);

    // traversing all componenets of graph (disconnected graphs)
    for (int i=0 ; i<no_nodes ; i++){
        if (!is_visited[i]){
            bfs(adj_list , is_visited , ans , i);
        }
    }

}

void print_adj_list(unordered_map<int , list<int>> adj_list){
            for (auto i : adj_list){
                cout << i.first << "->";
                for (auto j : i.second){
                    cout << j << " ";
                }
                cout << endl;
            }
}


int main(){
    int nodes;
    cout << "Enter no of edges : "; cin >> nodes;

    int edges;
    cout << "Enter number of edges : "; cin >> edges;
    Graph g;
    for (int i=0 ; i<edges ; i++){
        int u , v;
        cout << "Enter u : "; cin >> u;
        cout << "Enter v : "; cin >> v;
        g.add_edje(u , v , false);
    }

    // g.print_adj_list();
    unordered_map<int , list<int>> adj_list = g.get_graph();
    // print_adj_list(adj_list);
    
    return 0;
}


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

class Graph{
    public: 
        unordered_map<int , list<pair<int,int>>> adj_list;
        vector<vector<int>> edges;

        vector<vector<int>> make_edges(int no_nodes , int no_edges){
            // since weights are also there
            // undirected graph
            edges.resize(no_edges , vector<int>(3));
            for (int i=0 ; i<no_edges ; i++){
                int u , v , w;
                cin >> u >> v >> w;
                edges[i][0] = u;
                edges[i][1] = v;
                edges[i][2] = w;
            }
            return edges;
        }
};

unordered_map<int , list<pair<int , int>>> make_adj_list(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<pair<int , int>>> adj_list;

    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj_list[u].push_back(make_pair(v,w));
        adj_list[v].push_back(make_pair(u,w));

    }
    return adj_list;
}

vector<int> dijkstra(vector<vector<int>> edges , int no_nodes , int no_edges , int src){

    unordered_map<int , list<pair<int,int>>> adj_list = make_adj_list(edges , no_nodes , no_edges);
    vector<int> dist(no_nodes);
    for (int i=0 ; i<no_nodes ; i++){
        dist[i] = INT_MAX;
    }
    set <pair<int , int>> st;

    dist[src] = 0;
    st.insert(make_pair(0, src));

    while(!st.empty()){
        // fetch top record
        auto top = *(st.begin());
        int node_dist = top.first;
        int top_node = top.second;

        st.erase(st.begin());

        // traverse on neighbours
        for (auto neighbours : adj_list[top_node]){
            if (node_dist + neighbours.second <= dist[neighbours.first]){

                auto record = st.find(make_pair(dist[neighbours.first],neighbours.first))
            }
        }
    }
}



int main(){

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

class Graph{
    public:
        vector<pair<pair<int,int> , int>> edges;

        vector<pair<pair<int,int> , int>> make_edges(int no_nodes , int no_edges){
            for(int i=0;i<no_edges;i++){
                int u , v , w;
                cin >> u >> v >> w;
                pair<int , int>node = make_pair(u,v);
                pair<pair<int, int>,int> ans = make_pair(node , w);
                edges.push_back(ans);
            }

            return edges;
        }
};

unordered_map<int , list<pair<int , int>>> make_adj_list(vector<pair<pair<int,int> , int>> edges , int no_nodes , int no_edges){

    unordered_map<int , list<pair<int , int>>> adj_list;
    for (int i=0 ; i<edges.size(); i++){
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        adj_list[u].push_back(make_pair(v,w));
        adj_list[v].push_back(make_pair(u,w));

    }
    return adj_list;
}

// calculation of min spanning tree using prims algo
// this algo returns data structure similar to edges data structure
vector<pair<pair<int,int> , int>> prim_mst(vector<pair<pair<int,int> , int>> edges , int no_nodes , int no_edges ){
    unordered_map<int , list<pair<int , int>>> adj_list = make_adj_list(edges , no_nodes , no_edges);

    vector<int> key(no_nodes+1);
    vector<bool> mst(no_nodes+1);
    vector<int> parent(no_nodes+1);

    for (int i=0 ; i<no_nodes ; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
     // starting of algo
     // 1 is src node
     key[1] = 0;
     parent[1] = -1;

     for (int i=1 ; i<no_nodes ; i++){
        int mini = INT_MAX;
        int u ;

        for (int v=1 ; v<no_nodes ; v++){
            if (mst[v] == false && key[v] << mini){
                u = v;
                mini = key[v];
            }
        }

        // mark u to true
        mst[u] = true;

        // check its neighbors
        for (auto it : adj_list[u]){
            int v = it.first;
            int w = it.second;
            if (mst[v] == false  && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
     }

     vector<pair<pair<int,int> , int>> result;

     for (int i=2 ; i<= no_nodes ; i++){
        result.push_back(make_pair(make_pair(parent[i] , i) , key[i]));
     }

     return result;
}


int main(){
    Graph g;
    int no_nodes =3;
    int no_edges = 3;
    vector<pair<pair<int,int> , int>> edge_mat = g.make_edges(no_nodes , no_edges);
    for (auto i : edge_mat){
        cout << i.first.first << " " << i.first.second << "->" << i.second << endl;
    }

    unordered_map<int , list<pair<int , int>>> adj_list = make_adj_list(edge_mat , no_nodes , no_edges);

    for (auto i : adj_list){
        cout << i.first << "->";
        for (auto j : i.second){
            cout << "[" << j.first << " " << j.second << "]";
        }
        cout << endl;
    }
    
    return 0;
}
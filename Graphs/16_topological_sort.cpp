#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
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

unordered_map<int , list<int>> make_adj_list(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<int>> adj_list;

    for (int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
    }
    return adj_list;
}


void topological_sort_util(int node , unordered_map<int , list<int>> &adj_list , unordered_map<int , bool> &is_visited , stack<int> &s1){
    is_visited[node] = true;

    for(auto neighbour : adj_list[node]){
        if (!is_visited[neighbour]){
            topological_sort_util(neighbour , adj_list , is_visited , s1);
        }
    }
    s1.push(node);
}

vector<int> topological_sort(vector<vector<int>> edges , int no_nodes , int no_edges){
    unordered_map<int , list<int>> adj_list = make_adj_list(edges , no_nodes , no_edges);
    unordered_map<int , bool> is_visited;
    vector<int> ans;
    stack<int> s1;

    for (int i=0 ; i<no_nodes ; i++){
        if (!is_visited[i]){
            topological_sort_util(i , adj_list , is_visited , s1);
        }
    }

    while(!s1.empty()){
        ans.push_back(s1.top());
        s1.pop();
    }

    return ans;
}

int main(){
    Graph g;
    int no_nodes = 4;
    int no_edges = 4;
    vector<vector<int>> edge_mat = g.make_edges(no_nodes , no_edges);
    for (int i=0 ; i<edge_mat.size() ; i++){
        cout << edge_mat[i][0] << " " << edge_mat[i][1] << endl;
    }

    unordered_map<int , list<int>> adj_list = make_adj_list(edge_mat , no_nodes , no_edges);

    for (auto i : adj_list){
        cout << i.first << "->";
        for (auto j:i.second){
            cout << j << " ";
        }cout << endl;
    }

    cout <<"Topological Sort : " << endl;
    vector<int> ans = topological_sort(edge_mat , no_nodes , no_edges);
    for (int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
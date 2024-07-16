#include <iostream>
#include <vector>
using namespace std;

class Graph {
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

    vector<vector<int>> create_adj_list() {
        vector<vector<int>> ans(no_nodes); // Use dynamic sizing for ans
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        adj_list.resize(no_nodes); // Resize adj_list to no_nodes
        for (int i = 0; i < no_nodes; i++) {
            adj_list[i].push_back(i);
            for (int j = 0; j < ans[i].size(); j++) {
                adj_list[i].push_back(ans[i][j]);
            }
        }
        return adj_list;
    }

    void print() {
        // for (int i = 0; i < adj_list.size(); i++) {
        //     cout << adj_list[i][0] << "->";
        //     for (int j = 1; j < adj_list[i].size(); j++) {
        //         cout << adj_list[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << adj_list.size();
    }
};

int main() {
    Graph g;
    int nodes, edges;
    cin >> nodes;
    cin >> edges;
    g.add_edges(nodes, edges);
    g.create_adj_list();
    g.print();
    return 0;
}

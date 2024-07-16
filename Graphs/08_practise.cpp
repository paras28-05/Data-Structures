#include <iostream>
#include <vector>
using namespace std;

class Graph{
    public:
        vector<vector<int>> adj_list;
        void add_edge(int u , int v ,  bool is_directed){
            if (!adj_list.size()){
                adj_list[0].push_back(u);
                adj_list[0].push_back(v);
            }
            for (int i=0; i<adj_list.size();i++){
                if (adj_list[i][0] == u){
                    adj_list[i].push_back(v);
                }else{
                    adj_list[adj_list.size()][0] = u;
                    adj_list[adj_list.size()].push_back(v);
                }
            }
            if (!is_directed){
                for (int i=0; i<adj_list.size();i++){
                if (adj_list[i][0] == v){
                    adj_list[i].push_back(u);
                }else{
                    adj_list[adj_list.size()][0] = v;
                    adj_list[adj_list.size()].push_back(u);
                }
            }
            }
        }

        void print_adj(){
            cout << adj_list.size();
            // for (int i=0 ; i<adj_list.size() ; i++){
            //     cout << adj_list[i][0] << "->";
            //     for (int j=1 ; j<adj_list[i].size() ; j++){
            //         cout << adj_list[i][j] << " ";
            //     }cout << endl;
            // }
        }

        vector<vector<int>> gen_graph(int no_nodes){
            for (int i=0 ; i<no_nodes ; i++){
                int u , v;
                cin >> u;
                cin >>v;
                add_edge(u,v , false);
            }
            return adj_list;
        }

};

void print(vector<vector<int>> adj_list){
    for (int i=0 ; i<adj_list.size() ; i++){
        cout << adj_list[i][0] << "->";
        for (int j=1;j<adj_list[i].size();j++){
            cout << adj_list[i][j] << " ";
        }cout << endl;
    }
}

int main(){
    Graph g;
    int no_nodes;
    cout << "Enter no of edges : "; cin >> no_nodes;
    vector<vector<int>> adj_lsit = g.gen_graph(no_nodes);
    cout << "Class print function : "; g.print_adj();
    cout << "outside print fuction : "; print(adj_lsit);
    return 0;
}
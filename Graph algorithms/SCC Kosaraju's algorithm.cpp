//  Kosaraju’s algorithm to find strongly connected components of a directed graph
// Given a directed graph, find all the strongly connected components

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

const int max_node = 1000;
vector<int> graph[max_node];              //store graph's adjacency list
vector<int> transpose_graph[max_node];    //store transpose graph's adjacency list
bool vis[max_node];                       //store node visit stat for dfs

vector<int> node_order;     //store nodes in order of their finish time in dfs

//this function travels the whole graph and puts the nodes in a node_order
// the nodes are pushed in order of their finish time
void dfs(int n){
    if(vis[n]) return;  //if node is already visited
    
    int len= graph[n].size();
    vis[n]= true;
    
    for(int i= 0; i<len; i++){
        dfs(graph[n][i]);
    }
    
    node_order.push_back(n);
}


//this function traverses the transpose graph
// at each call traverses a SCC and prints each node of that SCC to std output
void dfs_print(int n){
    if(vis[n] == true) return;  //if node is already visited
    
    cout<< n <<" ";
    
    int len= transpose_graph[n].size();
    vis[n]= true;
    
    for(int i= 0; i<len; i++){
        dfs_print(transpose_graph[n][i]);
    }
}

//n nodes
// print each SCC nodes in separate line
// and return the number of SCC in that graph
int kosarajuSCC(int n){
    int scc_count= 0;   //keep count of strongly connected components
    for(int i= 1; i<=n; i++){
        if(vis[i] == false){
            dfs(i);
        }
    }
    
    for(int i= 1; i<=n; i++){
        vis[i]= false;
    }
    
    for(int i= node_order.size()-1; i>= 1; i--){
        if(vis[node_order[i]] == false){
            dfs_print(node_order[i]);
            scc_count++;
            cout<<endl;
        }
        
    }
    
    node_order.clear();
    return scc_count;
}

int main(void){
    
    int n; //n nodes
    int m; //m edges
    int u; //start node of an edge
    int v; //end node of an edge
    
    cin>>n>>m;
    
    
    //initialize
    for(int i= 0; i<= n; i++){
        vis[i]= false;
        graph[i].clear();
        transpose_graph[i].clear();
    }
    
    //take graph input as adjacency list
    for(int i= 0; i<m; i++){
        cin>>u>>v;     //edge u -> v
        
        graph[u].push_back(v);
        transpose_graph[v].push_back(u);
    }
    
    int components= kosarajuSCC(n);
    cout<< "Components: "<< components <<endl;
    
    
    return 0;
}
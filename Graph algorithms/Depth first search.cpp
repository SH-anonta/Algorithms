//Depth first search
//traverse the graph in O(n) time
//the example given bellow is an unweighted undirected graph

/*
 * Sample input:
 * #of nodes 1-n, #of edges m
 * m lines follow with pair of nodes which have edges between them

5 6
1 3
2 4
4 3
4 5
2 5
1 2
 */


#include <iostream>
#include <vector>

//adjacency list for 10K nodes
std::vector<int> graph[10000];

//status of current node during traversal(using characters)
// w-> white: unvisited
// g-> grey: being processed/adjacent nodes are being visited
// b-> black: processed/ all adjacent nodes have been visited
char stat[1000];        
int entry_time[1000];   //time of visiting a node
int exit_time[1000];    //time of processed a node

int dfs_clock;
using namespace std;
//parameters: adjacency list of graph, current position of graph
void dfs(int current_node){
    //if this node is already visited
    if(stat[current_node] != 'w') return;
    
    int adj_nodes= graph[current_node].size();
    
    //flag this node as visited(grey)
    stat[current_node]= 'g';
    entry_time[current_node]= ++dfs_clock;
    
    //visit this node's adjacent nodes
    for(int i= 0; i<adj_nodes; i++){
        dfs(graph[current_node][i]);
    }
    
    //flag this node as processed (black)
    stat[current_node]= 'b';
    exit_time[current_node]= ++dfs_clock;
}

int main(void)
{
    using namespace std;
    
    //n nodes, m edges
    int n, m, u, v;
    
    dfs_clock= 0;
    cin>>n>>m;
    
    //mark all nodes as unvisited(white)
    for(int i=1; i<= n; i++){
        stat[i]= 'w';
    }
    
    //take edges from input
    while(m--){
        cin>>u>>v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //start DFS from node 1
    dfs(1);
    
    
    ///////////////////////////////////////
    //displaying results of DFS
    cout<< "Node:  ";
    for(int i=1; i<= n; i++){
        cout.width(3);
        cout<< i<< " ";
    }
    
    cout<<endl;
    cout<< "Entry: ";
    for(int i=1; i<= n; i++){
        cout.width(3);
        cout<< entry_time[i]<<" ";
    }
    cout<<endl;
    cout<< "Exit:  ";
    for(int i=1; i<= n; i++){
        cout.width(3);
        cout<< exit_time[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}


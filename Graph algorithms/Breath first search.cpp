//Breath first search
//traverse every node from an initial node in closest nodes first order
//the following implementation is simple and does not consider multiple connected components
//the graph shown in the example is undirected but it can work for directed graphs as well
//time complexity O(n)
//*see input graph in bottom*

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

//graph start from node and number of nodes
void bfs(std::vector<int> graph[], int start, int n){
    bool visited[n+3];
    std::queue<int> q;
    
    //set all nodes unvisited
    for(int i= 1; i<=n; i++){
        visited[i]= false;
    }
    
    //current node we are at and number of adjacent nodes of it(len)
    int current, adj_node,len;
    visited[start]= true;
    q.push(start);
    
    std::cout<< "Order of traversal:\n";
    while(!q.empty()){
        current= q.front();
        len= graph[current].size();
        q.pop();
        
        std::cout<< current <<" ";
        
        //loop through all adjacent nodes of current node
        for(int i= 0; i<len; i++){
            adj_node= graph[current][i];
            if(visited[adj_node] == true) continue;
            visited[adj_node]= true;
            q.push(adj_node);
        }
        
    }
    
    std::cout<<std::endl;
}


int main(void)
{
    using namespace std;
    //n nodes, m edges, bfs starts from start
    int n, m, u, v, start;
    std::vector<int> graph[100];
    
    cin>>n>>m;
    
    //input the edges
    while(m--){
        cin>>u>>v; //there is an edge between u and v
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>start;
    
    bfs(graph, start, n);
    
    return 0;
}



/*
7 8
1 2  
1 3
2 5  
2 3  
3 4  
4 5
4 6
5 7  
1 
 */
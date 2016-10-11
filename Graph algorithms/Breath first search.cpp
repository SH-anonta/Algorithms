//Simple BFS graph traversal (graph is undirected and is connected )
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>

//print order of visiting nodes
//start from node 1
void breath_first_search(std::vector<std::vector<int>>& graph, int node_count){
    std::queue<int> q;
    
    //to keep track of which nodes are visited
    bool stat[node_count+5];
    memset(stat, 0, sizeof(stat));
    
    q.push(1);  //start from 1st node
    std::cout<< "1 ";
    stat[1]= true;
    
    int current_node, adj_nodes;
    while(!q.empty()){
        current_node= q.front();
        adj_nodes= graph[current_node].size();
        
        //visit neighbors of current node
        for(int i= 0; i<adj_nodes; i++){
            if(stat[graph[current_node][i]] == true) continue; //node already visited
            q.push(graph[current_node][i]);
            std::cout<< graph[current_node][i] <<" ";
            stat[graph[current_node][i]]= true;
        }
        
        q.pop();    //current node processed(all of it's adjacent nodes are visited)
    }
    
    std::cout<<std::endl;
}


int main(void)
{
    using namespace std;
    
    //representing the graph
    vector<vector<int>> graph(101); //up to 100 vertices/nodes
    int n, m, a,b; //n nodes, m edges, a and b have edges
    cin>>n>>m;
    
    while(m--){
        cin>>a>>b;
        //edge insertion
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    cout<< "Order of traversal:"<<endl;
    breath_first_search(graph, n);
    
    return 0;
}

/*
Graph input:
n m [n nodes m edges, m lines follow with edge description]
 
7 8

1 2  
1 3
2 5  
2 3  
3 4  
4 5
4 6
5 7  
 
 */
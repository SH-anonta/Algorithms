// Single source shortest distance:
// given a graph and a starting node s
// find the shortest paths from s to every other nodes

//strategy: use breath first search to traverse the graph. While at it...
//keep track of the distance of each node from the starting node
//and keep a tree/order of node traversal (which node was discovered from which node)
//that we can follow to get the shortest path (reverse)
//see input graph at bottom [undirected simple graph]
#include <iostream>
#include <queue>
#include <stack>

void bfs(std::vector<int> graph[], int distance[], int parent[], int start, int n){
    bool visited[n+4];
    //set all nodes as unvisited
    for(int i= 0; i<=n; i++){
        visited[i]= false;
        distance[i]= -1; //keep the distance of each node from the starting node
        parent[i]= -1;   //keep track of parent of node in traversal tree
    }
    
    int current, adj_node, len;
    std::queue<int> q;
    visited[start]= true;
    distance[start]= 0;
    
    q.push(start);
    
    while(!q.empty()){
        current= q.front();
        q.pop();
        len= graph[current].size();
        
        for(int i= 0; i<len; i++){
            adj_node= graph[current][i];
            
            if(visited[adj_node] == true) continue;
            distance[adj_node]= distance[current]+1;
            visited[adj_node]= true;
            parent[adj_node]= current;
            q.push(adj_node);
        }
    }
    
}

int main(void)
{
    using namespace std;
    //n nodes, m edges, bfs starts from start
    int n, m, u, v, start;
    std::vector<int> graph[100];
    int distance[100];
    int parent[100];
    
    cin>>n>>m;
    
    //input the edges
    while(m--){
        cin>>u>>v; //there is an edge between u and v
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>start;     //starting node
    
    //find paths with BFS
    bfs(graph, distance, parent, start, n);
    
    //print found paths
    cout<<"Node :  (path length) : [shortest path]   \n";
    for(int i= 1; i<= n; i++){
        cout<< i << ": ";
        if(distance[i] == -1){
            cout<<"no path found\n";
            continue;
        }
        
        cout<< "(" <<distance[i]<<") : ";
        int current= i;
        stack<int> reverser;
        while(parent[current] != -1){
            reverser.push(current);
            current= parent[current];
        }
        reverser.push(start);
        
        while(!reverser.empty()){
            cout<< reverser.top() <<" ";
            reverser.pop();
        }
        cout<<endl;
    }
    
    return 0;
}

/*
(nodes, edges)
m edges follow
n m

8 8
1 2  
1 3
2 5  
2 3  
3 4  
4 5
4 6
5 7  
2 
  
(^s starting node)
 */

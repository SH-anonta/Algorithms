//Find articulation points and edges in graph
//time complexity O(E+V)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

std::vector<int> graph[1000];  //the graph is stored here
char stats[1000];       //w for unvisited, g for exploring b for visited
int parent[1000];       //keep record of who is who's parent in DFS tree
int entry_time[1000];    //start time
int exit_time[1000];    //end   time
int low[1000];          //stire the minimum entry time of the desendents of current node
int visit_time;

typedef std::pair<int, int> Edge;
bool cut_node[1000];
std::vector<Edge> cut_edge;

int dfs_root;
int root_childs;

void dfs(int n){
    stats[n]= 'g';
    low[n]= entry_time[n]= visit_time;
    visit_time++;
    
    int len= graph[n].size(), next;
    
    for(int i= 0; i<len; i++){
        next= graph[n][i];
        if(stats[next] == 'w'){
            parent[next]= n;
            if(n == dfs_root) root_childs++;
            
            dfs(next);
            
            if(low[next] >= entry_time[n] && n != dfs_root) cut_node[n]= true;
            if(low[next] > entry_time[n]) cut_edge.push_back(Edge(n, next));
            
            low[n]= std::min(low[n], low[next]);
        }
        else if(next != parent[n]){
            low[n]= low[n]= std::min(low[n], entry_time[next]);
        }
    }
    
    stats[n]= 'b';
    exit_time[n]= visit_time;
    visit_time++;
    
}

int main(void)
{
    using namespace std;
    visit_time= 1;
    
    int n;  // n nodes
    int m;  // m edges
    int u, v; //two terminals an edge
    
    //take graph input
    cin>>n>>m;
    
    //prepare for graph traversal
    for(int i= 0; i<=n; i++){
        graph[i].clear();
        parent[i]= i; //
        stats[i]= 'w'; //all unvisited
    }
    
    //take edge input (undirected edges)
    for(int i= 0; i<m; i++){
        cin>>u>>v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //start graph traversal
    for(int i= 1; i<=n; i++){
        if(stats[i] == 'w'){
            dfs_root= i;
            root_childs = 0;
            dfs(i);
            if(root_childs > 1) cut_node[dfs_root]= true;
        }
    }
    
    //output DFS tree stats
    cout<< "node:\tparent:\tentry:\texit"<<endl;
    for(int i= 1; i<= n; i++){
        cout<< i << "\t"<< parent[i] << "\t"<< entry_time[i] << "\t"<< exit_time[i] <<endl;
    }
    
    int cut_edges= cut_edge.size();
    
    cout<< "Cut nodes: ";
    for(int i= 1; i<= n; i++){
        //Important must skip root node of dfs tree
        if(cut_node[i] == true){
            cout<< i <<" ";
        }
        
    }
    cout<<endl;
    cout<< "Cut edges:\n";
    for(int i= 0; i< cut_edges; i++){
        cout<< cut_edge[i].first <<" "<< cut_edge[i].second <<endl;
    }
            
    return 0;
}

//sample input
/*
 
6 7
1 2
2 5
1 3
3 4
2 3
5 4
1 6
 
8 6
1 2
2 3
2 4
3 4
4 5
7 8
 */
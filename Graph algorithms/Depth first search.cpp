//DFS graph traversal

#include <iostream>
#include <vector>
#include <cstdio>

std::vector<int> graph[1000];  //the graph is stored here
char stats[1000];   //w for unvisited, g for exploring b for visited
int parent[1000];       //keep record of who is who's parent in DFS tree
int entry_time[1000];    //start time
int exit_time[1000];    //end   time

int visit_time;

void dfs(int n){
    stats[n]= 'g';
    entry_time[n]= visit_time;
    visit_time++;
    
    int len= graph[n].size(), next;
    
    for(int i= 0; i<len; i++){
        next= graph[n][i];
        if(stats[next] == 'w'){
            parent[next]= n;
            dfs(next);
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
            dfs(i);
        }
    }
    
    //output DFS tree stats
    cout<< "node:\tparent:\tentry:\texit"<<endl;
    for(int i= 1; i<= n; i++){
        cout<< i << "\t"<< parent[i] << "\t"<< entry_time[i] << "\t"<< exit_time[i] <<endl;
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
 
 */
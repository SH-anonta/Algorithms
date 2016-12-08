//topological sort using BFS in O(n) time

/*  sample input:
 * n vertex, m edges, m lines describe m directed edges
5 4
1 2
2 3
1 3
1 5

 */

#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[1000];
std::vector<int> topo_sort;
int indegree[1000];

void topoSort(int n){
    std::queue<int> q;
    
    for(int i= 1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    int u, len, x;
    while(!q.empty()){
        u= q.front();
        q.pop();
        if(indegree[u] == 0)
            topo_sort.push_back(u);
        len= graph[u].size();
        
        for(int i= 0; i<len; i++){
            x= graph[u][i];
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
}

int main(void)
{
    using namespace std;
    int n,m, u,v;
    //take input
    cin>>n>>m;
    for(int i= 0; i<= n; i++) indegree[i]= 0;
    for(int i= 0; i<m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    topoSort(n);
    
    for(int i= 0; i<n; i++){
        cout<< topo_sort[i]<<" ";
    }
    cout<<endl;
    return 0;
}
// Union Find Disjoint Set data structure
// keep data in groups/sets and answer if two elements are from the same set in O(1)
// Path compression heuristic is used.
#include <iostream>

//keep parent of i th element
int parent[1000];

//given the number of elements 1-n initialize the parent array
//at first all n elements are in their own separate sets
void initialize_set(int n){
    for(int i= 0; i<= n; i++) parent[i]= i;
}

// return the representative/root of the set/tree the element a is in
// and compress the tree path while at it
int rep_of(int a){
    if(parent[a] == a) return a;
    return parent[a]= rep_of(parent[a]);
}

//puts elements of two sets in the same sets
void join(int a, int b){
    parent[rep_of(a)]= rep_of(b);
}

// check if elements a and b are in the same set
bool same_set(int a, int b){
    return rep_of(a) == rep_of(b);
}

// return count of disjoint sets given total element count n
// [1 based indexing is used]
int set_count(int n){
    int num= 0;
    for(int i= 1; i<=n; i++){
        if(parent[i] == i) num++;
    }
    
    return num;
}

// return how many elements are member of set which a belongs to
// given a and the total number of elements n
int set_size(int a, int n){
    int num= 0;
    int rep_of_a= rep_of(a);
    for(int i= 1; i<=n; i++){
        if(rep_of(i) == rep_of_a) num++;
    }
    
    return num;
}

int main(void)
{
    using namespace std;
    
    int n, m, a, b, q;   
    cin>>n>>m;          //n elements and m relationships
    
    initialize_set(n);
    
    while(m--){
        cin>>a>>b;
        
        join(a,b);
    }
    
    cin>>q;
    while(q--){     //q querees
        cin>>a>>b;      
        cout<< (same_set(a,b)? "Yes" : "No" ) <<endl;
    }
    
    cout<< "Total disjoint sets: "<< set_count(n) <<endl;
    
    return 0;
}


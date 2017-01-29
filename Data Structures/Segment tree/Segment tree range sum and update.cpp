// segment tree 
// given an array of numbers. Segment tree provides two operations
// 1. Build a segment tree from an array
// 2. given a range [l, r] give a property of elements in that range
// sum/minimum/maximum element etc in O(lg(n)) complexity
// 2. update an element in the array  O(lg(n)) complexity  
// Segment tree uses a binary heap

//IMPORTANT: 1 based indexing is used in both array and segment tree/heap index

#include <iostream>

const int array_size= 1000;
const int heap_size= 4*array_size;
//size of the heap should be at least 4*size of array

// index 0, value 0 is not part of input
int array[array_size]= {0, 1, 2, -4, 9, 21, 42, -30,11, 33, 12};
int tree[heap_size];

//make a segment tree with elements of array
//heap_index -node's index in heap
//l and r    -current node's range
void initializeTree(int heap_index, int l, int r){
    //a leaf is reached
    if(l == r){
        tree[heap_index]= array[l];
        return;
    }
    
    int mid= (l+r)/2;
    
    //current node gets the sum of it's children
    initializeTree(2*heap_index, l, mid);
    initializeTree(2*heap_index+1, mid+1, r);
    tree[heap_index]= tree[2*heap_index]+tree[2*heap_index+1];
}

//return sum of elements in [st, nd] in O(lg(n)) (start and end of range of query)
//l r, current node's range
//heap_index current node's index on the heap
int treeQuery(int heap_index, int l, int r, int st, int nd){
    //if current node's range is completely outside query range
    //returning something that will not effect the result
    if(r < st || l > nd) return 0;
    
    //if current node's range is completely inside query range
    if(l >= st && r <= nd){
        return tree[heap_index];
    }
    
    int mid= (l+r)/2;
    return treeQuery(2*heap_index, l, mid, st, nd)
           +treeQuery(2*heap_index+1, mid+1, r, st, nd);
}

//return sum of elements in [st, nd]   (start and end of range of query)
//l r, current node's range
//heap_index current node's index on the heap
void treeUpdate(int heap_index, int l, int r, int array_index, int new_value){
    //if current node's range is completely outside query range
    //returning something that will not effect the result
    if(l == r && l == array_index){
        tree[heap_index]= new_value;
        return;
    }
    
    int mid= (l+r)/2;
    if(array_index <= mid)
        treeUpdate(2*heap_index, l, mid, array_index, new_value);
    else
        treeUpdate(2*heap_index+1, mid+1, r, array_index, new_value);
    
    tree[heap_index]= tree[2*heap_index]+tree[2*heap_index+1];
}

int main(void){
    using namespace std;
    int elements= 10;
    initializeTree(1, 1, elements);
    
//    for(int i= 1; i<= 26; i++){
//        cout<< i <<" "<< tree[i] <<endl;
//    }
    
    int st, nd;
    char command;
    cout<< "commands: queries (q) or updates (u)" <<endl;
    while(cin>>command>>st>>nd){
        if(command == 'q'){
            cout<< "Enter start and end of range" <<endl;
            cout<< treeQuery(1, 1, elements, st, nd) <<endl;
        }
        else{
            cout<< "Enter index and new value" <<endl;
            treeUpdate(1, 1, elements, st, nd);
//            for(int i= 1; i<= 26; i++){
//                cout<< i <<" "<< tree[i] <<endl;
//            }
            
            cout<< "Updated" <<endl;
        }
    }
    
    return 0;
}
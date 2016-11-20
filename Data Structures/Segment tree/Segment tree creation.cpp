//segment tree is a complete binary tree
//that can be used for fast query over a set of data
//given an array of integers create a segment tree 
//tree creation O(n)
//tree query O(logn)
//tree update O(logn)

//array, array of elements from which to create the tree
//seg_tree, store where the tree will be stored
//l left/starting point of array
//r right/end point of array
// at is index of segment tree where info is stored

#include <iostream>
#include <cstdio>

using namespace std;


int CC_;
#define sf scanf
#define pf printf
#define PP cin.get();
#define NL cout<<endl;
#define all(container) container.begin(),container.end()
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;
#define DM(MT,n_,m_)pf("Matrix %s:\n   ", #MT);for(int i_= 0;i_<m_;i_++)pf("%4d ", i_);NL;NL;for(int r_=0;r_<n_;r_++){pf("%2d ", r_);for(int c_= 0;c_<m_;c_++)pf("%4d ", MT[r_][c_]);NL}


void create_segment_tree(int array[], int seg_tree[], int l, int r, int at){
     //if array is of size 1
    if(l >= r){
        seg_tree[at]= array[r];
        return;
    }
    seg_tree[at]= 0;
    
    //dividing the array in half and recursively creating their seg-tree
    create_segment_tree(array, seg_tree, l, (l+r)/2, 2*at);
    create_segment_tree(array, seg_tree, 1+(l+r)/2, r, 2*at+1);
    
    //adding the sum of it's children
    seg_tree[at]= seg_tree[2*at]+seg_tree[2*at+1];
}

int main(void)
{
    using namespace std;
    
    int n, a[100], seg_tree[100];
    cin>>n;
    
    for(int i= 0; i<n; i++){
        cin>>a[i];
    }
    
    create_segment_tree(a, seg_tree, 0, n-1, 1);
    
    //printing the segment tree
    for(int i= 1; i<=18; i++){
        cout<< seg_tree[i] << " ";
    }
    cout<<endl;
    
    return 0;
}

/*
 * inputs:
8
1 2 3 4 5 6 7 8
 
7
1 6 3 4 9 2 7 8
 */
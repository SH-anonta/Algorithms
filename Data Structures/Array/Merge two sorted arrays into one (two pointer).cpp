//merge two sorted arrays into one sorted array using two pointers (all in increasing order)
// time complexity: O(n+m) [n and m are length if the two strings]
#include <iostream>

//m and n are lengths of the arrays ary1 and ary2 respectively
template <typename T>
T* merge(const T* ary1, int m, const T* ary2, int n){
    T* combo= new T[m+n];
    int p1= 0, p2= 0, lim= m+n, i;
    
    //run until any one of or both array run out of elements
    for(i= 0; i<lim && p1 < m && p2 < n; i++){
        if(ary1[p1] < ary2[p2]){
            combo[i]= ary1[p1];
            p1++;
        }
        else if(ary1[p1] > ary2[p2]){
            combo[i]= ary2[p2];
            p2++;
        }
        else{   //when there equal elements in the array
            combo[i]= ary1[p1]; //both element get added
            i++;
            combo[i]= ary2[p2];
            p1++;
            p2++;
        }
    }
    
    //if an array is shorter than the other
    //insertion stops when all elements of the shorter array are inserted
    //and the remaining elements of the larger array get inserted array
    if(p1< m){
        for(; p1<m && i <lim; i++){
            combo[i]= ary1[p1];
            p1++;
        }
    }
    if(p2 < n){
        for(; p2<n && i <lim; i++){
            combo[i]= ary2[p2];
            p2++;
        }
    }
    
    
    return combo;
}

int main(void)
{
    using namespace std;
    
    const int sz_a= 10, sz_b= 5;
    
    int a[sz_a]= {1, 4, 6, 7, 9, 20, 31, 34, 120, 400};
    int b[sz_b]= {0, 2, 4, 10, 400};
    
    int* c= merge(a, sz_a, b, sz_b);
    
    for(int i=0; i<sz_a+sz_b; i++){
        cout<< c[i] <<" ";
    }
    cout<<endl;
    
    delete[] c;
    return 0;
}
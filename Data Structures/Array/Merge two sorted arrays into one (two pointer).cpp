//merge two sorted arrays into one sorted array using two pointers (all in increasing order)
// time complexity: O(n+m) [n and m are length if the two strings]
#include <iostream>


//merges arrays in specified order and returns pointer to new array
//m and n are lengths of the arrays ary1 and ary2 respectively
template <typename T>
T* merge(const T* ary1, int len1, const T* ary2, int len2){
    T* combo= new T[len1+len2];
    int p1= 0, p2= 0, lim= len1+len2, i;
    
    //run until any one of or both array run out of elements
    for(i= 0; i<lim && p1 < len1 && p2 < len2; i++){
        if(ary1[p1] <= ary2[p2]){
            combo[i]= ary1[p1];
            p1++;
        }
        else if(ary1[p1] > ary2[p2]){
            combo[i]= ary2[p2];
            p2++;
        }
    }
    
    //if an array is shorter than the other
    //insertion stops when all elements of the shorter array are inserted
    //and the remaining elements of the larger array get inserted array
    while(p1<len1){
        combo[i]= ary1[p1];
        p1++;
        i++;
    }
    while(p2<len2){
        combo[i]= ary2[p2];
        p2++;
        i++;
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
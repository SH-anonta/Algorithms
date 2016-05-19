//Binary search functions for arrays and vectors
//find index of an element in an array in O(logn) time

//arguments, pointer to array, position of last element, element to be found

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int binarySearch(const T* ary, int nd, const T& target){
    int st= 0;
    int mid;
    
    while(st<=nd){
        mid= st + (nd - st)/2;
        
        if(ary[mid] == target) return mid;

        if(target > ary[mid])
            st= mid+1;
        else nd = mid-1;
    }
    
    //if target was not found
    return -1;
}


template <typename T>
int binarySearch(const vector<T>& ary, const T& target){
    int st= 0, nd= ary.size();
    int mid;
    
    while(st<=nd){
        mid= st + (nd - st)/2;
        
        if(ary[mid] == target) return mid;
        if(target > ary[mid])   //search in right half
            st= mid+1;
        else nd = mid-1;    //search in left half
    }
    
    //if target was not found
    return -1;
}

int main(void)
{
    using namespace std;
    
    int a[10]= {1, 34, 123, 234, 300, 321, 444, 500, 1333, 3210};
    vector<int> v= {1, 34, 123, 234, 300, 321, 444, 500, 1333, 3210};
    
    int found= binarySearch(a, 10, 321);
    cout<< "Array: Found at Index(-1 if not found): "<<  found <<endl;
    
    found= binarySearch(v, 321);
    cout<< "Vector: Found at Index(-1 if not found): "<<  found <<endl;
    return 0;
}
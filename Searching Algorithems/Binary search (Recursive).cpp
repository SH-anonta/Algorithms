//Binary search functions for arrays and vectors
//find index of an element in an array in O(logn) time

//arguments, pointer to array, position of 1st element,
// position of last element, element to be found
#include <iostream>
#include <cstdio>
#include <ctime>
#include <random>
#include <vector>

//find index of an element in an array in O(logn) time
template <typename T>
int binarySearch(const T* ary, int st, int nd, const T& target){
    
    //if start and end index trackers cross each other
    //meaning target not found
    if(nd < st)  return -1;

    static int mid;
    mid = st+ (nd - st)/2;

    if(ary[mid] == target)return mid;

    //look in the right half of sub-array
    if(target > ary[mid])
        return binarySearch(ary, mid+1, nd, target);

    //look in the left half of sub-array
    return binarySearch(ary, st, mid-1, target);
}


//find index of an element in a vector in O(logn) time
template <typename T> 
int binarySearch(const std::vector<T>& ary, int st, int nd, const T& target){
    
    //if start and end index trackers cross each other
    //meaning target not found
    if(nd < st)  return -1;

    static int mid;
    mid = st+ (nd - st)/2;

    if(ary[mid] == target)return mid;

    //look in the right half of sub-array
    if(target > ary[mid])
        return binarySearch(ary, mid+1, nd, target);

    //look in the left half of sub-array
    return binarySearch(ary, st, mid-1, target);
}

int main()
{
    using namespace std;
    
    int a[10]= {1, 34, 123, 234, 300, 321, 444, 500, 1333, 3210};
//    vector<int> a = {1, 34, 123, 234, 300, 321, 444, 500, 1333, 3210};
    
    int found= binarySearch(a, 0, 10, 321);
    cout<< "Found at Index(-1 if not found): "<<  found <<endl;
    
    
    return 0;
}
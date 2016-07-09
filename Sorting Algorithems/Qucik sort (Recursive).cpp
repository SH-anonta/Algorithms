// Recursive quick sort
// Uses last element as pivot

#include <iostream>

#define SS cout<<"AAAAAAAAAAAAA"<<endl;

//partition function, takes last element as pivot
//puts pivot at correct position
//puts elements smaller than pivot at left of pivot
//and elements larger than pivot at right of pivot
template <typename T>
int partition(T* ary, int l, int h){
    int x = ary[h];
    int i= l-1;
    
    for(int j= l; j<= h-1; j++){
        if(ary[j] <= x){
            i++;
            std::swap(ary[i], ary[j]);
        }
    }
    std::swap(ary[i+1], ary[h]);
    return i+1;
}

//Quick sort
template <typename T>
void quickSortRecur(T* ary, int l, int h){
    if(l<h){
        int p = partition(ary, l, h);
        quickSortRecur(ary, l, p-1);
        quickSortRecur(ary, p+1, h);
    }
}


//Wrapper function,
//takes two pointers to start and end points of array to be sorted
//calls recursive function 
template <typename T>
inline void quickSort(T* st , T* nd){
    quickSortRecur(st, 0, nd-st -1);
}


int main(void)
{
    using namespace std;

    const int sz= 10;
//    int ary[sz]= {9,8,7,6,5,4,3,2,1,0};
    int ary[sz]= {0, -1, -41, 2, 6, 2, 3, 121, -21, 20};
    
//    quickSort(ary, ary+sz);
//    quickSort(ary, 0, sz-1);
    quickSort(ary, ary+sz);
            
    for(int i= 0; i<sz; i++){
        cout<< ary[i] << " ";
    }
    cout<<endl;

    return 0;
}

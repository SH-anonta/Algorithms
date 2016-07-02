//Simple bubble sort implementation
//Worst case complexity O(n^2) when array is sorted in reverse order
//optimizations skip the last k elements at every kth pass through
// because they are already sorted at kth pass through
//Check if the the array is sorted to avoid excessive iterations

#include <iostream>
#include <cstdlib>

//Sort given array in ascending order using bubble sort algorithm
template <typename T>
void bubbleSort(T* st, T* nd){
    int len= nd-st-1;
    bool swaps;
    
    for(int i= 0; i<len; i++){
        swaps= false;
        for(int j= 0; j<len-i; j++){
            if(st[j]>st[j+1]){
                std::swap(st[j],st[j+1]);
                swaps = true;
            }
        }
        
        if(!swaps) break;
    }
 }

int main(void)
{
    using namespace std;

    const int sz= 10;
//    int ary[sz]= {9,8,7,6,5,4,3,2,1,0};
    int ary[sz]= {0, -1, -41, 2, 6, 2, 3, 121, -21, 1};
    
    bubbleSort(ary, ary+sz);
    
    for(int i= 0; i<sz; i++){
        cout<< ary[i] << " ";
    }
    cout<<endl;

    return 0;
}

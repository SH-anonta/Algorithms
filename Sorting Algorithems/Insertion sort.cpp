//Insertion sort algorithm: traverse the array left to right,
//find the most appropriate place for the value on the left side and insert it there
//Worst case complexity O(n^2) (initially sorted in reverse order)
//good for small arrays

#include <iostream>

using namespace std;

//Sort an array using insertion sort algorithm
template <typename T>
void insetrionSort(T* st, T* nd){
    const int len= nd-st;
    
    for(int i= 1, j; i<len; i++){
        T temp= st[i];
        for(j= i-1; j>=0 && st[j]>temp; j--){
            st[j+1]= st[j];
        }
        st[j+1] = temp;
    }
}

int main(void)
{
    using namespace std;

    const int sz= 10;
//    int ary[sz]= {9,8,7,6,5,4,3,2,1,0};
    int ary[sz]= {0, -1, -41, 2, 6, 2, 3, 121, -21, 1};
    
    insetrionSort(ary, ary+sz);
    
    for(int i= 0; i<sz; i++){
        cout<< ary[i] << " ";
    }
    cout<<endl;

    return 0;
}
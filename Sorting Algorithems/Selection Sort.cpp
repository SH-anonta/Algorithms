//Algorithm: Selection sort
//Time complexity: O(n^2)
//Simply scan the whole array to find the max/min value,
//swap that value with the first element
//then scan array for min/max value from 2nd element to last and swap that with the 2nd element
//repeat n-1 times

#include <iostream>

using namespace std;

//prints array
template <typename T>
void prnt_ary(T* , unsigned int );


//sort array using selection sort algorithm
template <typename T>
void selection_sort(T ary[], int len)
{
    int mni; //index of element with minimum value
    for(int i= 0, j; i<len-1; i++)
    {
        for(j= i+1, mni= i; j<len; j++)
        {
            if(ary[mni]>ary[j])
                mni = j;
        }
        swap(ary[mni], ary[i]);
    }
}



int main(void)
{
    const int sz= 10;
    //array to be sorted
    int num[sz]= {-2, 99, 347, 0, 12, -123, -7, -23, 31, -99};
    
    selection_sort(num, sz);

    prnt_ary(num, sz);    
    return 0;
}


template <typename T>
void prnt_ary(T ary[], unsigned int n){
     while(n--){
        cout<< *ary++ << " ";       
    }
     cout<<endl;
}

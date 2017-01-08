// Maximum sub array sum problem
// given an array of integers
// find the maximum sum of contiguous sub array
// and the range of that sub array

// using Kadane's algorithm (DP)
// time complexity O(n) [number of elements]
// space complexity O(1)

#include <iostream>

int l, r;   //store index of max sum sub array range here [l to r]

//return max sum sub array and set the range in l, r global variables
int maxSubArraySum(int array[], int size){
    int cmx= array[0], gmx= array[0];
    
    l= r= 0;            //store range of global max sub array
    int tl= 0, tr= 0;   //store range of current max sub array
    for(int i= 1; i<size; i++){
        if(cmx+array[i] >= array[i]){
            cmx+= array[i];
            tr++;
        }
        else{
            cmx= array[i];
            tl= tr= i;
        }
        
        if(gmx <= cmx ){
            gmx= cmx;
            l= tl;
            r= tr;
        }
    }
    
    return gmx;
}


int main(void){
    using namespace std;
    
    int array[100];
    
    int n;
    
    //size of array
    cin>>n;
    for(int i= 0; i<n; i++){
        cin>>array[i];
    }
    
    cout<< "Max sum of sub array: "<< maxSubArraySum(array, n) <<endl;
    cout<< "(index)Range of max sum of sub array: "<< l << " to "<< r<<endl;
    
    return 0;
}

/*
 * Sample inputs
 * n [size of array]
 * next line contains the array

5
1 -5 3 -2 4

8
-2 -3 4 -1 -2 1 5 -3

 */
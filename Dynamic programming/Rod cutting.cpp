//Rod cutting 
//given a rod of length n
//and a list of lengths and their price 
//what is the configuration which will give us rods that maximize the price


#include <iostream>

using namespace std;

int cache[1005];
int length[1000];
int price[1000]= {1, 5, 8, 9, 10, 17, 17, 20};

int rodCut(int n){
    cache[0]= 0;
    
    int i, j, mx= INT_MIN;
    for(i= 1; i<= n; i++){
        for(j= 0; j<i; j++){
            if(mx < price[j]+cache[i-j-1]){
                mx= price[j]+cache[i-j-1];
            }
            cache[i]= mx;
        }
    }
    
    return cache[n];
}

int main(void)
{
    int n= 8;
//    cin>>n;
    
    cout<< rodCut(n) <<endl;
//    for(int i= 0; i<n; i++){
//        
//    }
    
    return 0;
}
//given n types of coins of unlimited quantity find minimum number of coins needed to make N
//time complexity O(n*m) [n is the number that needs to be made using coins]
//                       [m is the types of coins used]
//Space complexity O(n)  [n is the number that needs to be made using coins]

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

short CC_;
#define sf scanf
#define pf printf
#define PP getchar();
#define NL cout<<"\n";
#define pqueue priority_queue
#define testb(x_, i_) ((x_&1<<i_)!=0)
#define setb(x_, i_) (x_=(x_|(1<<i_)))
#define clrb(x_, i_) (x_=(x_&(!(1<<i_))))
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

//given an array of coin types (assumed to be of unlimited quantity)
// and a value sum. find the minimum number of coins required to add upto sum
template <typename T>
int minCoin(T* coins, int coin_size, T sum){
    const int INF= 1<<30;
    std::vector<T> used_coins;
    //partial results are stored here
    int minqtt[sum+1];
    minqtt[0]= 0;
    for(int i= 1; i<=sum; i++){
        minqtt[i]= INF; //setting all elements to infinity
    }
    
    //incrementally compute result for 1-sum 
    for(int i= 1; i<=sum; i++ ){
        for(int j= 0; j<coin_size; j++){
            //if better combo of coins found update entry
            if(coins[j]<=i && minqtt[i-coins[j]]+1 <minqtt[i]){
                minqtt[i]= minqtt[i-coins[j]]+1;
            }
        }
    }
    
    
    //if making the sum is not possible return -1
    return ((minqtt[sum] != INF)? minqtt[sum]: -1);
}

int main(void)
{
    int a[3]= {1, 3, 5};
    
    cout<< minCoin(a, 3, 8)<<endl;
    
    return 0;
}
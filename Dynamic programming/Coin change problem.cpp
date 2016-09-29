//Coin change problem: Given m the types of coins (of unlimited quantity)
//find the number of ways we can make n using these coins
// ie. given coins 2, 3, 5
// 11 can be made in 4 ways
// 5, 3, 3
// 5, 2, 2, 2
// 3, 3, 3, 2
// 3, 2, 2, 2, 2

#include <iostream>
#include <cstdio>

//array of coin types, size of the array, n-> amount to be maid
template <typename T>
long long coinCombo(const T coins[], const int ctypes, T n){
    //a solution is found
    if(n == 0) return 1;
    
    //solution con not be found using this combo
    if(n < 0) return 0;
    
    //out of coin types, so no solution
    if(ctypes <= 0 && n > 0) return 0;
    
    //try adding the m-1 th coin type + try adding the same type of coin again
    return coinCombo(coins, ctypes-1, n) + coinCombo(coins, ctypes, n-coins[ctypes-1]);
}

int main(void)
{
    using namespace std;
    
    
    int ctypes= 3;
    int coin_types[ctypes]= {2, 3, 5};
    int n= 11;
    
    cout<< coinCombo(coin_types, ctypes, n) <<endl;
    
    return 0;
}
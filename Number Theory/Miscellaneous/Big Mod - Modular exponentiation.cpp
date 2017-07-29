// Code produces mod of very big numbers using Big Mod algorithm 
// i.e. (71^569) % 13 = 2
// Complexity nlog(n)


#include <iostream>

using namespace std;

int bigMod(int base, int exp, int m){

    if(exp == 0) return 1;

    if(!(exp & 1)){ //if exp is even
        int temp= bigMod(base, exp/2, m)%m;
        return (temp*temp)%m;
    }

    else return ( (base%m)*(bigMod(base, exp-1, m))%m )%m;
}


int main(void)
{
    cout<< bigMod(71, 569, 13) <<endl;
    
    return 0;
}
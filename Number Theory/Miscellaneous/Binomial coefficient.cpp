//Binomial coefficient
//using Pascal's triangle

#include <iostream>
#include <cstring>
#include <ctime>

//return how many ways n items can be arranged in k slots nCk
long long binomialCoefficient(int n, int k){
    if(k == 1) return n;
    if(n == k) return 1;
    
    return binomialCoefficient(n-1,k-1) + binomialCoefficient(n-1,k);
}


int main(void)
{
    using namespace std;
    
    cout<< binomialCoefficient(10, 3) <<endl;
    
    clock_t tt= clock();
    
    return 0;
}
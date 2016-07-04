//Finds all the divisors of a number in square root of n time
// simple brute force solution with some slight optimization

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
std::vector<T> divisors(const T num){
    long long sqrtNum= sqrt((double)num);
    vector<T> divisors1, divisors2;
    
    for(int i= 1; i<= sqrtNum; i++){
        if(num % i == 0){
            divisors1.push_back(i);
            //if the the divisor and quotient are not the same
            if(num/i != i) divisors2.push_back(num/i);
        }
    }
    
    
    int len = divisors2.size();
    for(int i= len-1; i>=0; i--){
        divisors1.push_back(divisors2[i]);
    }
    
    return divisors1;
}

int main(void)
{
    using namespace std;
    
    
    long long num= 1254;
    vector<long long> divs = divisors(num);
    
    for(int i= 0; i<divs.size(); i++){
        cout<< divs[i] <<" ";
    }
    cout<<endl;
    
    
    return 0;
}
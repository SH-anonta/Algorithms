// Find the square root of any number a binary search
// let square root of any number n is q
// 1<= q <= n is true for all numbers except 0
// by doing a binary search in that interval
// will lead us to the square root of n in O(logn) time

// let median value of interval is mid
// we can use the relation of mid*mid and n to find which half of the interval has the answer
// if n>mid*mid (square root is grater then mid) then our answer is in the right half of the interval
// so l(left side of interval) becomes mid and we just disposed half of our previous interval

#include <iostream>
#include <cmath>


double squareRoot(double n){
    if(n == 0) return 0.0;
    double l= 1, r= n, mid= (l+r)/2, mm= mid*mid;
    
    //while mid*mid is not equal to n, keep dividing the interval
    while(fabs(mm-n) > 1E-9){
        if(n > mm){
            l= mid;
        }
        else r= mid;
        
        mid= (l+r)/2;
        mm= mid*mid;
    }
    
    return mid;
}

int main(void)
{
    using namespace std;
    
    double x= 50;
    cout.precision(6);
    
    cout<< squareRoot(x) <<endl;
    return 0;
}
// extended GCD Modular 
//given n and m find the modular inverse of n under mod m

// modular inverse for n under mod m exists iff n and m are coprime [GCD(n, m) == 1]
// a and b are modular inverse iff (a*b) % m == 1

#include <bits/stdc++.h>
using namespace std;

//given a and b. find x, y and g such that a*x + b*y == gcd(a,b)
//returns gcd(a,b) and stores x and y in pointed to x and y variables respectively
int extendedGCD(int a, int b, int* x, int* y){
    if(a == 0){
        *x= 0;
        *y= 1;
        return b;
    }
    
    int x1, y1;
    int gcd= extendedGCD(b%a, a, &x1, &y1);
    *x= y1 - (b/a) * x1;
    *y= x1;
    
    return gcd;
}


int main(void)
{
    using namespace std;
    
    int x= 0, y= 0, a,b;
    
    b= 15;
    a= 35;
    
    cout<< extendedGCD(a,b, &x, &y)<<endl;
    cout<< x <<" " << y <<endl;
    return 0;
}
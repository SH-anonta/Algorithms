//Calculates GCD and LCM of given 2 numbers
//Time complexity: O(Log n)

#include <iostream>
#include <cmath>

using namespace std;

//returns the GCD of two numbers
int gcd(int a, int b){
    if( b%a == 0) return a;
    else  return gcd(b%a, a);
}

//returns the LCM of two numbers
int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(void){
    int g= gcd(12, 8);
    int l= lcm(12, 8);

    cout<< "GCD: " << g <<endl;
    cout<< "LCM: " << l <<endl;

    return 0;
}

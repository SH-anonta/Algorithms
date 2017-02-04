//Euler's totient function
// phi(n) = count of numbers that are <= n and are coprime of n
// if gcd(n, x) = 1 n and x are coprime
// this approach works by subtracting the number of prime divisors and their multiple of n
// since divisors and their multiple have gcd greater than 1 with n
// after subtracting their count what is left is the count of coprimes from 1 to n
#include <iostream>

//return Euler's totient of n
int phi(int n){
    int ret= n;
    
    for(int i= 2; i*i <= n; i++){
        if(n % i == 0){
            while(n%i == 0){
                n /= i;
            }
            ret -= ret/i;
        }
    }
    
    if(n > 1) ret -= ret/n;
    
    return ret;
}

int main(void)
{
    using namespace std;
    int n;
    
    cout<<"Enter numbers:" <<endl;
    while(cin>>n){
        cout<< "phi: "<< phi(n) <<endl;
    }
    
    return 0;
}
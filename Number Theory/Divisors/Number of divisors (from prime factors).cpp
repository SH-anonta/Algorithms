//Code counts number of divisors of a number
//done using prime factorizing the number
//and using their power to find out the number of divisors
//...Since divisors are just products of different combinations of the prime factors

//If we can write N = X1^P1 * X2^P2 * X3^P3 * ... Xn^Pn
//Where X are prime factors of N and P are their powers
//then the number of divisors of N is (P1 + 1) * (P2 + 1) * ... (Pn + 1)

#include <iostream>
#include <cmath>

using namespace std;


const int stat_sz= 1E6;      //size of array to hold prime numbers
const int prime_sz= 8E4;	

bool stat[stat_sz+10];       //to mark composite as 1 then avoid them to generate primes
int primes[prime_sz]; 
int primeFactors[128];

//Sieve of Eratosthenes, Prime number generation
void sieve(int );

template <typename T>
int divisorCount(T num)
{
    T sqrtN= sqrt((double)num);
    int factorPower;
    int divCount= 1;
    for(int i= 0; primes[i]<=sqrtN; i++)
    {
        factorPower= 0;
        //Counting the power of the current prime factor
        while(num % primes[i] == 0){
            factorPower++;
            num /= primes[i];
        }
        
        
        divCount *= factorPower + 1;
    }
    
    //if the last factor gets left out
    if(num != 1)
    {
        // factor's power is 1 so 1+1= 2
        divCount *= 2;
    }
    
    
    return divCount;
}




int main(void)
{
    //generating prime numbers for factorizing number
    //Prime numbers upto sqrt(n) must be generated
    sieve(1e6);
    
    long long n= 148716818871;
    int divs = divisorCount(n);
    cout<<  "Number of divisors of " << n <<": " << divs <<endl;
    
    return 0;
}

void sieve(int N)
{
    int sqrtN= sqrt(double(N));
    int primeCount= 1;
       
    for(int i= 3, j; i<=sqrtN; i+=2)
    {
        if(stat[i] == 0)
        {
            for(j = i*i; j<=N; j+= i<<1)
            {
                stat[j]= 1;
            }
            
        }
        
    }
    
    primes[0]= 2; 
    
    for(int i= 3, j= 1; i<=N; i+= 2)
    {
        if(stat[i] == 0) 
        {
            primes[j]= i;
            j++;
            primeCount++;
        }
        
    }    
}

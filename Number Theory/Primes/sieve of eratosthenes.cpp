//#Name: Anonta Haque #Problm:  
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <cstdio>


using namespace std;

typedef long L;                 //"%ld"
typedef long long LL;           //"%lld"
typedef long double LD;         //"%f"
typedef unsigned int UI;        // "%u"
typedef unsigned long  UL;      //"%lu"
typedef unsigned long long ULL; //"%llu"

short COUNT_;
#define sf scanf
#define pf printf
#define NL pf("\n");
#define SS pf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++COUNT_);
#define DD(x_) cout<<">>>>( "<<++COUNT_<<" ) "<<#x_<<": "<<x_<<endl;


//constants
const int sz= 1E6;      //size of array to hold prime numbers

bool stat[sz+10];       //to mark composite as 1 then avoid them to generate primes
int primes[sz+10];      //8E4 is enough for storing primes within 2-1E6 

void sieve(int N)
{
    int sqrtN= sqrt(double(N));
    int primeCount= 1;
    
    
    //marks all the composite numbers from 9 to [sz]
    //even numbers are not marked as they are skipped altogether
    for(int i= 3, j; i<=sqrtN; i+=2)
    {
        if(stat[i] == 0)        //if not marked as composite yet/ don't want to mark twice
        {
            for(j = i*i; j<=N; j+= i<<1) //j+= 2i
            {
                stat[j]= 1; //marking this number as composite (corresponding to index number)
            }
            
        }
        
    }
    
    
    //setting 1st element as these loops only process odd numbers
    //pf("%d ", 2);
    primes[0]= 2; 
    
    //generates primes by skipping even numbers
    //and composite numbers marked by 'stat' array
    for(int i= 3, j= 0; i<=N; i+= 2)
    {
        if(stat[i] == 0)   //if not marked as composite
        {
            primes[j]= i;
//            pf("%d ", i);
//            pf("%d ", primes[j]);
            j++;
            primeCount++;
        }
        
    }
    
    pf("\n%d\n", primeCount);
}



int main(void)
{
    sieve(1e6);    
    
    return 0;
}




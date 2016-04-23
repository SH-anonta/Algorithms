//#Name: Anonta Haque #Problm:  
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>

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
#define put(x_) pf("%d", x_)
#define read(x_) sf("%d", &x_)
#define readf(x_) sf("%f", &x_)
#define read2(x_,y_) sf("%d%d",&x_,&y_)
#define SS pf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++COUNT_);
#define DD(x_) cout<<">>>>( "<<++COUNT_<<" ) "<<#x_<<": "<<x_<<endl;


//return if the given number is a prime or not
//simple algorithm, bad for handling huge numbers
template <typename T>
bool isprime(T num)
{
    T numsqr= sqrt((double)num);
    
    //cover some corner cases
    if(num == 2) return true;
    if(num == 1) return false;
    if(num % 2 == 0) return false;
    
    //try to divide by odd numbers upto square root of num
    //if dividable by any, return false else true
    for(int i= 3; i<= numsqr; i+=2)
    {
        if(num % i == 0) return false;
    }
    
    return true;
}


int main(void)
{
    
    cout<< isprime(51464641) <<endl;
    return 0;
}




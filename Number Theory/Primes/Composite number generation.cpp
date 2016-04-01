//#Name: Anonta Haque #Problm: generate Composite numbers
// Using sieve of eratosthenes algorithm

#include <iostream>
#include <cstdio>
#include <cmath>

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
#define arySZ(x_) sizeof(x_)/sizeof(x_[0])  //(array must be in scope)
//constants
const int SZ= 1E6;

int pr[8];
bool stat[SZ+10];
int composites[SZ+10];

//Sieve of eratosthenes, generate and store composite numbers
// in composites array
void sieve(LL N)
{
//    int composite_count= 3;
    
    //safety check
    if(N >= arySZ(composites) || N >= arySZ(composites)){
        pf("Array to short!!!\n");
        return;
    }
    
    //create array for marking composite numbers
    
//    mark all odd composite numbers in the stat array
//    corresponding to index number
    LL sqn= sqrt((double)N);
    for(int i= 3; i<=sqn; i+= 2)
    {
        //if not marked as odd composite yet
        if(stat[i] == 0)
        {
            for(int j= i*i; j<N; j+= i<<1)
            {
                stat[j]= 1;
            }
        }
    }
    
    //fill int the first 3 elements
    composites[0]= 4;
    composites[1]= 6;
    composites[2]= 8;
    
    for(int i= 9, j= 3; i<N; i+=2)
    {
        if(stat[i] == 1)
        {
//            pf("%d ", i);
            composites[j]= i;
            j++;
        }
//        pf("%d ", i+1);
        composites[j]= i+1;
        j++;
    }
    
}


int main(void)
{
    sieve(1e6);
    
    return 0;
}




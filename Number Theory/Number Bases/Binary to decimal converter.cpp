//Simple binary to decimal functions.
//todec() functions take argument binary 
//cstyle string or string object and return a long long int


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

short COUNT_;
#define sf scanf
#define pf printf
#define NL pf("\n");
#define put(x_) pf("%d", x_)
#define read(x_) sf("%d", &x_)
#define readf(x_) sf("%f", &x_)
#define read2(x_,y_) sf("%d%d",&x_,&y_)
#define arySZ(x_) sizeof(x_)/sizeof(x_[0])  //(array must be in scope)
#define SS pf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++COUNT_);
#define DD(x_) cout<<">>>>( "<<++COUNT_<<" ) "<<#x_<<": "<<x_<<endl;
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;


using namespace std;

typedef long long LL;     

//Convert from binary (string object)to decimal number (integer)
LL todec(string& bin)
{
    LL dec= 0;
    short i= 0,
    len= bin.size() -1;
    
    while(bin[i])
    {
        if(bin[i++]=='1'){
            dec += 1<<len;
        }
    len--;
    }
    return dec;
}

//Convert from binary (c style string)to decimal number (integer)
LL todec(char* bin)
{
    LL dec= 0;
    short i= 0,
    len= strlen(bin) -1;
    while(bin[i])
    {
        if(bin[i++]=='1'){
            dec += 1<<len;
        }
    len--;
    }
    return dec;
}

#define BINS "10100100011010010101010001"

int main(void)
{
    string bin= BINS;
    char cbin[100]= BINS;
    
    cout<< todec(bin) <<endl;
    
    return 0;
}
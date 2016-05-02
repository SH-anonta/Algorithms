//Generate Fibonacci Sequence upto n'th element
#include <iostream>

using namespace std;


void fobonacci(int n)
{
    unsigned long long first= 0, second= 1, third= 1;
    
    while(n--)
    {
        cout<< third << " ";
        
        third= first+second;
        first= second;
        second= third;
    }
    
    cout<<endl;
}

int main(void)
{
    fobonacci(50);
    
    return 0;
}

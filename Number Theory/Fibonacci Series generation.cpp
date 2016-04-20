//Generate Fibonacci Sequence upto n'th element
#include <iostream>

using namespace std;

void fobonacci(int n)
{
    int first= 0, second= 1, third= 1;
    
    for(int i= 0; i<n; i++)
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
    fobonacci(10);
    
    return 0;
}

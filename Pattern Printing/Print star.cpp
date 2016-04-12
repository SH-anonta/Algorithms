// Prints a resizable star like this: (Size 3)
// 
//          *
//         ***
//        *****
// *******************
//  *****************
//   ***************
//   **************
//  ****************
// ******************
//        *****
//         ***
//          *

#include <iostream>
#include <stdlib.h>


using namespace std;

inline void star90(int n, const char ch)
{
    //s1
    for(int i= 0; i<n; i++)
    {
        //1 & 2
        for(int j= 0; j<2*n; j++)
        {
            cout<< ' ';
        }
        //3
        for(int k= n - i; k>0; k--)
        {
            cout<< ' ';
        }
        //4
        for(int l= 0; l<=i; l++)
        {
            cout<<ch;
        }
        //5
        for(int m= 0; m<i; m++)
        {
            cout<<ch;
        }
        cout<<endl;
    }
    
    //s2
    for(int i= 0; i<n; i++)
    {
        //6
        for(int m= 0; m<i; m++)
        {
            cout<<' ';
        }
        //7
        for(int k= n-i; k>0; k--)
        {
            cout<< ch;
        }
        //8
        for(int j= 0; j<4*n; j++)
        {
            cout<< ch;
        }
        //9
        for(int k= n - i; k>=0; k--)
        {
            cout<< ch;
        }
        cout<<endl;
    }
    
    //s3
    for(int i= 0; i< n; i++)
    {
        for(int k= n -i -1; k>0; k--)
        {
            cout<< ' ';
        }
        
        for(int l= 0; l<=i; l++)
        {
            cout<<ch;
        }
        
        for(int j= 0; j<4*n; j++)
        {
            cout<< ch;
        }
        
        for(int l= 0; l<=i; l++)
        {
            cout<<ch;
        }
        
        cout<<endl;
    }
    
    //s4
    for(int i= 0; i<n; i++)
    {
        for(int j= 0; j<2*n; j++)
        {
            cout<< ' ';
        }
        
        for(int a= 0; a<=i; a++)
        {
            cout<<' ';
        }
        
        for(int k= n - i-1; k>0; k--)
        {
            cout<<ch;
        }
        
        for(int k= n - i; k>0; k--)
        {
            cout<<ch;
                }
        cout<<endl;
    }
}


int main(void)
{
    const int n= 3;
    const char ch= '*';
    
    star90(n,ch);
    
    cout<<endl;
    
    return 0;
}

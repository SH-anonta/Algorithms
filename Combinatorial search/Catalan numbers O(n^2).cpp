//finding the first n Catalan numbers in O(n^2) (using dynamic programming)

#include <iostream>
#include <cstring>

const int asize= 1006;
unsigned long catalan_numbers[asize];

unsigned long catalan(int n){
    if(n <= 1) return 1;
    if(catalan_numbers[n] != -1) return catalan_numbers[n];
    
    unsigned long cat= 0;
    
    for(int i= 0; i<n; i++){
        cat+= catalan(i)*catalan(n-i-1);
    }
    
    return catalan_numbers[n]= cat;
}

int main(void)
{
    using namespace std;
    
    int n;
    cin>>n;
    memset(catalan_numbers, -1, sizeof(catalan_numbers));
    
    catalan_numbers[0]= catalan_numbers[1]= 1;
    cout<< "first "<< n <<" Catalan numbers:\n";
    
    catalan(n);
    for(int i= 0; i<=n; i++){
        cout<< catalan_numbers[i] <<" ";
    }
    cout<<endl;
    
    
    
    return 0;
}
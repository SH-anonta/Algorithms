//Code cycles through an array
// Meaning after the last element you get the 1st element

#include <iostream>

using namespace std;

int main(void)
{
    const int sz= 5;
    int a[sz]= {1,2,3,4,5};
    
    //Cycle through the array a
    for(int i=0; 1; i = (i+1)%sz){
        cout<< a[i] <<"\n";
        
        cin.get();
    }
    return 0;
}
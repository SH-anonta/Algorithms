//Generate random numbers within a given range;
//generate completely random numbers
// rand();
//generate random numbers from 0 to 99
// rand()%100;
//generate random numbers from 1 to 100
//  rand()%100 + 1;
//generate random numbers from 20 to 50
//  rand()%31+ 20; //basically (50 - 20 + 1)

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(void)
{
    
    int n;
    
    //number of iteration/ how many random numbers to generate
    int i= 10;
    
    //upper and lower limits for creating random numbers
    int lower= 2;
    int upper= 10;
    
    cout<< i << " random numbers between "<< lower << " and " << upper<<"\n\n";
    
    //initialing random seed
    //so on every start of the program the rand function will return new random number
    srand(time(NULL)); 
    
    while(i--){
        n= rand()%(upper-lower+1) + lower;
        cout<< n <<endl;
    }
    
    return 0;
}
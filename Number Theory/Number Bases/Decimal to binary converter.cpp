//Code converts a decimal number into it's binary representation

#include <iostream>
#include <string>

using namespace std;

//returns a string object containing the bit string of a number
template <typename T>
string toBinary(T num){
    string bin;
    
    while(num != 0){
        if(num&1){ //of num is odd
             bin = '1' + bin;
        }
        else bin = '0' + bin;
        
        num /= 2;
    }
    
    return bin;
}

int main(void)
{
    string bin;
    long long num;
    
    while(1){
        cin>>num;
        
        bin = toBinary(num);
        
        cout<< bin <<endl;
        
    }
    
    return 0;
}
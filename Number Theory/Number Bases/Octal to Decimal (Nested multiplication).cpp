//Converts Binary (bit string) to decimal (long long) using nested multiplication

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

//converts string object 
long long octalToDecimal(const std::string& oct){
    long long res= oct[0] - '0';
    for(int i= 1; oct[i] !='\0'; i++){
        res *= 8;
        res += oct[i] - '0';
    }
    
    return res;
}

//converts C string / char array 
long long octalToDecimal(const char* oct){
    long long res= oct[0] - '0';
    for(int i= 1; oct[i] !='\0'; i++){
        res *= 8;
        res += oct[i] - '0';
    }
    
    return res;
}

//TODO
long long octalToDecimal(const long long oct){
    
    
    
}

int main(void)
{
    using std::cout;
    using std::endl;
    
    std::string bin = "754547";
    //Using string object:
    cout<< "Octal: " << bin<< "\nDecimal: " << octalToDecimal(bin)  <<endl;
    //Using c string:
    cout<< "\nOctal: " << bin<< "\nDecimal: " << octalToDecimal(bin.c_str())  <<endl;
    
    
    return 0;
}
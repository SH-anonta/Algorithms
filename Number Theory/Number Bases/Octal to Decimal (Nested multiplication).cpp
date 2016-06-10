//Converts Binary (bit string) to decimal (long long) using nested multiplication
#include <iostream>
#include <cmath>
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
long long octalToDecimal(const long long octnum){
    const int len = 1 + log10(octnum);
    char* oct = new char[len];
    sprintf(oct, "%lld", octnum);
    long long res= oct[0] - '0';
    for(int i= 1; oct[i] !='\0'; i++){
        res *= 8;
        
        res += oct[i] - '0';
    }
    
    return res;
}

int main(void)
{
    using std::cout;
    using std::endl;
    
    std::string oct = "754547";
    int octnum = 754547;
    //Using string object:
    cout<< "Octal: " << oct<< "\nDecimal: " << octalToDecimal(oct)  <<endl;
    //Using c string:
    cout<< "\nOctal: " << oct<< "\nDecimal: " << octalToDecimal(oct.c_str())  <<endl;
    // using long int
    cout<< "\nOctal: " << oct<< "\nDecimal: " << octalToDecimal(octnum)  <<endl;
    
    
    return 0;
}
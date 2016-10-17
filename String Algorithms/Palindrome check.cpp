#include <iostream>
#include <cstring>

using namespace std;

//checks if a given string is palindromic or not
bool isPalindrome(char* str)
{
    int len= strlen(str);
    for(int i= 0;i<len/2; i++)
    {
        if(str[i]!=str[len-i-1]){
            return false;
        }
    }
    
    return true;
}

int main(void)
{
    char str[]= "pallap";
    cout<< isPalindrome(str) <<endl;
    
    return 0;
}
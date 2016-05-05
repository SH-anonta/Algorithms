#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

//Functions checks if a given string is pangram or not
bool isPangram(string& str){
    bool found;
    int len= str.size();
    
    for(char alph= 'a'; alph<='z'; alph++){
        found = false;
        for(int i= 0; i<len; i++){
            //if alphabet's upper or lower case equals char of string
            // +' ' adds 32 to alph, which is it's uppercase counter part
            if(str[i] == alph || alph+' '){
                found = true;
                break;
            }
        }
        //if current alphabet was not found in the string
        if(!found) return false;
    }
    
    return true;
}

//Functions checks if a given string is pangram or not
bool isPangram(char str[]){
    bool found;
    int len= strlen(str);
    
    for(char alph= 'a'; alph<='z'; alph++){
        found = false;
        for(int i= 0; i<len; i++){
            //if alphabet's upper or lower case equals char of string
            // +' ' adds 32 to alph, which is it's uppercase counter part
            if(str[i] == alph || alph+' '){
                found = true;
                break;
            }
        }
        //if current alphabet was not found in the string
        if(!found) return false;
    }
    
    return true;
}

int main(void)
{
    string str;
    char cstr[1024];
    
//    cout<< "Enter a string:\n";
//    getline(cin, str);
//    
//    fgets(cstr, 1000, stdin);
//    
//    cout<< isPangram(str) <<endl;
//    cout<< isPangram(cstr) <<endl;
    
    return 0;
}
// Anagram are words which can be transformed into each other just by rearranging their letters
// dips and spid are anagrams. their length must be equal
// the code below checks if two strings are anagrams
// letter case doesn't matter


#include <iostream>
#include <cctype>

bool isAnagram(const std::string& str1, const std::string& str2){
    int len= str1.size();
    std::string temp= str2;
    bool found;
    
    if(len != str2.size()) return false;
    
    for(int i= 0; i<len; i++){
        found = false;
        for(int j= 0; j<len; j++){
            if(tolower(str1[i]) == tolower(temp[j])){
                found = true;
                temp[j]= '\0';  //so the same letter wont be taken into account
                break;
            }
            
        }
        
        if(!found) return false;
    }
    
    return true;
}


int main(void)
{
    using std::cout;
    using std::endl;
    using std::string;
    
    string s= "lisa",
           a= "LASI";
    
    cout<< isAnagram(a,s) <<endl;
    return 0;
}
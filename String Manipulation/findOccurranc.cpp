//Code finds the number of time a string occurs in another string
#include <iostream>
#include <string>

using namespace std;

//Returns the number of occurrence of target string in str string
//the string matching is case sensitive
int findOccurrance(string& str, string& target){
    int occurCount= 0;
    int slen = str.size();
    int tlen = target.size();
    bool found;
    
    for(int i= 0; i<slen; i++){
        found = true;
        for(int j= 0; j<tlen && i+j<slen; j++){
            if(target[j] != str[i+j]){
                found = false;
                break;
            }
        }
        if(found) occurCount++;
    }
    
    return occurCount;
}




int main(void)
{
    string text= "this is the text that shows this";
    string target= "th";
    
    cout<< findOccurrance(text, target)<<endl;
    return 0;
}

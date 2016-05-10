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
    
    for(int i= 0, j; i<slen; i++){
        for(j= 0; j<tlen && i+j<slen; j++){
            if(target[j] != str[i+j]){
                break;
            }
        }
        
        if(j == tlen){ //if all chars of target were checked
            occurCount++;
        }
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

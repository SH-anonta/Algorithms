//Find occurrence of a string in another string

#include <iostream>
#include <string>

int strOccur(std::string& str, std::string& target){
    using std::string;
    
    int occur= 0;
    
    int pos= str.find(target);
    while(pos != string::npos){
        pos = str.find(target, pos+1);
        occur++;
    }
    
    return occur;
}


int main(void)
{
    using std::cout;
    using std::string;
    using std::endl;
    
    string s= "text files contain text in text format text";
    string t= "text";
    
    cout<< strOccur(s, t) <<endl;
    
    return 0;
}
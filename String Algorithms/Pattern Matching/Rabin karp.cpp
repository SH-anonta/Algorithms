//Robin karp algorithm
#include <iostream>

        
//find the pattern b in string s
//return index of first occurrence
//return -1 if pattern not found 
int rabinKarp(const std::string& s, const std::string& b){
    int n= s.size(), m = b.size();
    if(n<m) return -1;
    long long pattern_hash= 0, current_hash= 0, p= 1 , MOD= 7 + 1E15;

    //generate hash of pattern and first m char of string
    for(int i= m-1; i>= 0; i--){
        pattern_hash = (pattern_hash+(p*b[i])%MOD)%MOD;
        current_hash = (current_hash+(p*s[i])%MOD)%MOD;
        p *= 5;
    }
    
    int pos= 0;    
    p/= 5;
    
    //rolling hash generation
    while(pos <= n-m){
        if(pattern_hash == current_hash){
            if(s.find(b.c_str(), pos, m) != std::string::npos) return pos;
        }

        current_hash -= p*s[pos];   //chopping off the left most char's value
        current_hash = (current_hash*5)%MOD;          //increasing the power of all the comps by 1
        current_hash += s[pos+m];   //adding a new char value to hash/ 

        pos++;
    }
    
    return -1;
}

int main(void)
{
    using namespace std;
    string a= "robin karp";
    string b= "bin kar";
    
    cout<< rabinKarp(a, b) <<endl;
    
    return 0;
}
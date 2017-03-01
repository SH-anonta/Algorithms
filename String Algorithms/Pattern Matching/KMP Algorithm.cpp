// KMP algorithm
// given a string S and a pattern P (length of S and P are n and m respectively)
// find all occurrences of P in S
// runs in O(n+m) and needs O(m) space

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int reset_table[10000];

//given a string build it's reset table
void buildResetTable(string& pattern){
    int i = 0, j= -1, len= pattern.size(); 
    reset_table[0]= -1;
    while(i < len){
        while(j >= 0 && pattern[i] != pattern[j]){
            j= reset_table[j];
        }
        i++;
        j++;
        reset_table[i]= j;
    }
}


void kmpFind(string& s, string& p){
    int i= 0, j= 0;
    int n= s.size();
    int m= p.size();
    
    
    while(i< n){
        while(j >= 0 && s[i] != p[j]){
            j= reset_table[j];
        }
        i++;
        j++;
        
        if(j == m){
            cout<< "found at: "<< i-j<<endl;
            j= reset_table[j];
        }
        
    }
}


int main(){
    string s, p;
    
    s= "I dont like seventy sev but seventy seventy seven";
    p= "seventy seven";
    
    buildResetTable(p);
    kmpFind(s, p);

    return 0;
}
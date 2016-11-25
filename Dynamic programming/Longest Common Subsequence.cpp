// Longest Common Subsequence (LCS0
// given two strings find the longest common subsequence
// in O(m*n) where m and n are the length of two strings


#include <iostream>
#include <cstring>
#include <cstdio>


//store subproblem answers in cache
int cache[10000][10000];
//keep sequence of the LCS movements
char track[10000][10000];

int LCS(std::string& s1, std::string s2){
    int len1= s1.size(), len2= s2.size();
    
    for(int i= 0; i<= len1; i++){
        for(int j= 0; j<= len2; j++){
            if(i == 0 || j == 0)
                cache[i][j]= 0;
            else if(s1[i-1] == s2[j-1]){
                cache[i][j]= 1+cache[i-1][j-1];
                track[i][j]= 'c';
            }
            else if(cache[i-1][j] >= cache[i][j-1]){
                cache[i][j]= cache[i-1][j];
                track[i][j]= 'u';   //go up
            }
            else{
                cache[i][j]= cache[i][j-1];
                track[i][j]= 'l';   //go left
            }
            
        }
    }
    
    return cache[len1][len2];
}

//given the first string and the length of both
//return LCS by following instructions in track array
std::string LCS_string(std::string& s, int m, int n){
    if(m <= 0 || n <= 0) return std::string("");
    if(track[m][n] == 'c'){
        return LCS_string(s, m-1, n-1)+s[m-1];
//        std::cout<< s[m-1];
    }
    else if(track[m][n] == 'u')
        return LCS_string(s, m-1, n);
    else if(track[m][n] == 'l')
        return LCS_string(s, m, n-1);
    else{
        std::cerr<<"ERROR: invalid instruction in LCS track matrix\n";
        return std::string("__ERROR__");
    }
}

int main(void)
{
    using namespace std;
    string s,t;
    
    cout<< "Input a pair of strings:\n";
    
    while(cin>>s>>t){
        if(s == "") break;
        
        cout<< "LCS length: " << LCS(s, t) <<endl;
        cout<< "LCS: ";
        cout<< "LCS :"<< LCS_string(s, s.size(), t.size()) <<endl;
        cout<<endl;
    }
    return 0;
}

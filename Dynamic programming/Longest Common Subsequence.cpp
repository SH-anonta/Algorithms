// Longest Common Subsequence (LCS0
// given two strings find the longest common subsequence
// in O(m*n) where m and n are the length of two strings


#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
 
//Macros
int CC_;
#define sf scanf
#define pf printf
#define PP cin.get();
#define NL cout<<endl;
#define all(container) container.begin(),container.end()
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;
#define DM(MT,n_,m_)pf("Matrix %s:\n   ", #MT);for(int i_= 0;i_<m_;i_++)pf("%d ", i_);NL;NL;for(int r_=0;r_<n_;r_++){pf("%2d ", r_);for(int c_= 0;c_<m_;c_++)pf("%c ", MT[r_][c_]);NL}


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
//    DD(m<<" "<<n)
//    DD(track[m][n])
    if(m <= 0 || n <= 0) return string("");
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
        return string("__ERROR__");
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
//        DM(track,  s.size(), t.size());
        cout<< "LCS: ";
        cout<< "LCS :"<< LCS_string(s, s.size(), t.size()) <<endl;
//        LCS_string(s, s.size(), t.size()); 
        cout<<endl;
    }
    return 0;
}

//#Name: Sofen Hoque Anonta 
//Hash template

#include <iostream>
#include <set>

using namespace std;


int phash(string& s){
    static const int base= 27;
    static const int MOD= 10000007;
    static const char adjust_char= 'a'; //for hashing strings with only lower case English letters
    
    int val= 0;
    int prod= 1;
    for(int i= 0, len= s.size(); i<len; i++){
        val= (val+ (s[i] - adjust_char) *prod)%MOD;
        prod= (prod*base)%MOD;
    }
    
    return val;
}

void solve(){
    
}

int main(void)
{
    solve();
    
    return 0;
}
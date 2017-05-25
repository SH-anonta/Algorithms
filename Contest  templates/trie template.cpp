//#Name: Sofen Hoque Anonta  #Problm:
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int word;
    int pre;
    
    Node* ed[26];
};

Node* root;

void add(string& s, int d, Node* cn){
    if(s[d] == '\0'){
        cn->pre++;
        cn->word++;
        return;
    }
    
    cn->pre++;
    
    char ch= s[d]-'a';
    
    if(cn->ed[ch] == NULL){
        cn->ed[ch]= new Node();
    }
    
    add(s, d+1, cn->ed[ch]);
}

//warning when nodes are deleted the root node may also be deleted if no string remain in trie
bool remove(string& s, int d, Node* cn){
    if(s[d] == '\0' && cn->word++){
        cn->pre--;
        cn->word--;
        
//        if(cn->pre == 0) delete cn;
        return true;
    }
    
    char ch= s[d]-'a';
    
    //string not present in array
    if(cn->ed[ch] == NULL) return false;
    
    if(remove(s, d+1, cn->ed[ch])){
        cn->pre--;
        cn->word--;
        if(cn->pre == 0) cn->ed[ch]= NULL;
//        delete cn;
    }
    else return false;
}


void printTrie(string&s, int d, Node* cn){
    if(cn->word > 0){
        cout<< ">> "<< s <<endl;
    }
    
    for(int i= 0; i<26; i++){
        if(cn->ed[i] == NULL) continue;
        
        s.push_back(i+'a');
        printTrie(s, d+1, cn->ed[i]);
        s.pop_back();
    }
}

void dfs(int d, Node* cn){
    for(int i= 0; i<26; i++){
        if(cn->ed[i] == NULL) continue;
        
        dfs(d+1, cn->ed[i]);
    }
}

void solve(){
    root = new Node();
    string s[]= {"tree", "trie", "cick", "extra", "thicc", "tribe"};
    
    for(string i : s){
        add(i, 0, root);
    }
    
    string ss;
    string r= "tree";
    cout<< remove(r, 0, root) <<endl;
    
    printTrie(ss, 0, root);
} 

int main(void)
{
//    freopen("D:/input.txt", "r", stdin);
    solve();

    
    return 0;
}
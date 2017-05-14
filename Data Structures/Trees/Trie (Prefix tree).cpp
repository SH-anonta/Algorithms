//Prefix Trie for lower case English letters 
#include <iostream>

using namespace std;


class Trie{
private:
    //max number of child each node of trie can have
    static const int CHILD_COUNT= 26;
    class TrieNode{
    public:
        int words;
        int prefixes;
        TrieNode* edge[CHILD_COUNT];
        
        TrieNode(){
            words= 0;
            prefixes= 0;
            for(int i= 0; i<CHILD_COUNT; i++){edge[i]= NULL;}
        }
    };
    
    TrieNode* root_node;
    
    //visit each node and delete them
    //cn for current current
    void clearAllNodes(TrieNode* cn){
        for(int i= 0; i<CHILD_COUNT; i++){
            if(cn->edge[i] == NULL) continue;
            clearAllNodes(cn->edge[i]);
            cn->edge[i]= NULL;
        }
        
        delete cn;
    }
    
public:
    Trie(){
        root_node= new TrieNode();
    }
    
    //function to insert a string into the Trie
    void add(string& s, int depth, TrieNode *cn){
        if(s[depth] == '\0'){
            cn->prefixes++;
            cn->words++;
            return;
        }
        
        char ch= s[depth]-'a';
        if(cn->edge[ch] == NULL){
            cn->edge[ch] = new TrieNode();
        }
        
        cn->prefixes++;
        add(s, depth+1, cn->edge[ch]);
    }
    
    //wrapper function to insert a string into the Trie
    void add(string& s){
        if(root_node == NULL) TrieNode();
        add(s, 0, root_node);
    }
    
    //how many times a string occurs in the trie
    int frequency(string& s){
        return frequency(s, 0, root_node);
    }
    
    int frequency(string& s, int depth, TrieNode* cn){
        if(s[depth] == '\0'){
            return cn->words;
        }
        
        char ch = s[depth]-'a';
        if(cn->edge[ch] == NULL) return 0;
        else return frequency(s, depth+1, cn->edge[ch]);
    }
    
    //return the number of strings in the trie that have string s as it's prefix
    int prefixFrequency(string& s){
        return prefixFrequency(s, 0, root_node);
    }
    
    int prefixFrequency(string& s, int depth, TrieNode* cn){
        if(s[depth] == '\0'){
            return cn->prefixes;
        }
        
        char ch = s[depth]-'a';
        if(cn->edge[ch] == NULL) return 0;
        else return prefixFrequency(s, depth+1, cn->edge[ch]);
    }
    
    //cn is current node, print strings inserted in the dictionary
    void printDictionary(TrieNode* cn, string& s){
        //todo print frequency of a word
        if(cn->words > 0){
            cout<< ">> "<< s <<endl;
        }
        
        for(int i= 0; i<CHILD_COUNT; i++){
            if(cn->edge[i] == NULL) continue;
            
            s.push_back(i+'a');
            printDictionary(cn->edge[i], s);
            s.pop_back();
        }
    }
    
    //print all strings inserted in the Trie
    void printDictionary(){
        if(root_node == NULL) return;
        string temp;
        printDictionary(root_node, temp);
    }
    
    bool prefixOfOtherWord(TrieNode* cn){
        if(cn->words == 1 && cn->prefixes > 1) return false;

        for(int i= 0; i<CHILD_COUNT; i++){
            if(cn->edge[i] == NULL) continue;
            
            if(prefixOfOtherWord(cn->edge[i]) == false) return false;
            
        }
        
        return true;
    }
    
    //return if there are words that are prefix of other words in the trie
    //wrapper function
    bool prefixOfOtherWord(){
        return prefixOfOtherWord(root_node);
    }
    
    //destructor
    ~Trie(){
        clearAllNodes(root_node);
    }
    
    //delete all entry in trie
    void clear(){
        clearAllNodes(root_node);
    }
};

void test1(){
    
    string s[]= {"tris","is", "a", "trie", "trie"};
    string f= "tri";
    
    Trie t;
    for(string i : s){
        t.add(i);
    }
    
    t.printDictionary();
//    cout<< t.frequency(f) <<endl;
    cout<< t.prefixFrequency(f) <<endl;
}

int main(void)
{
//    test1();
    
    
    return 0;
}
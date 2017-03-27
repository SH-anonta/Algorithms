//creating all n length permutation (with repetition) of a given set of elements 
// in lexicographical order
//this approach is very similar to doing a breath first search

#include <iostream>
#include <queue>

using namespace std;

//given a string print all possible n length permutations (with repetition) of it's elements
void combo(string elements, int n){
    int len = elements.size();
    
    queue<string> q;
    string empty = "";
    
    for(int i= 0; i<len; i++){
        q.push(empty+elements[i]);
    }
    
    string current_str;
    while(!q.empty()){
        current_str= q.front();
        q.pop();
        
        if(current_str.size() == n){
            cout<< current_str <<endl;
            continue;
        }
        
        for(int i= 0; i<len; i++){
            q.push(current_str + elements[i]);
        }
        
    }
    
}

int main(void)
{
    string s= "abcd";
    combo(s, 3);
    
    
    return 0;
}
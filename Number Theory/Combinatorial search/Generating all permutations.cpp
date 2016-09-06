//This is a backtracking combinatorial search to compute all permutations of alphabets from A to n th alphabets
// time complexity is O(n!) [O(n!/2) actually]
// space complexity is O(n!) [only if permutations are to be printed in lexicographic order]
// optimization: compute first half of n! permutations
// then reverse their individual configurations to get the rest of the permutations 

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>

long long factorial(long long);

//n is the number of elements left to select from to put in the next position
//count keeps track of how many permutations have been found
//stats keeps track of which element have been added to the current permutation
//perm contains the (partial) permutation
//generate permutations from A to nth alphabet
void generatePermutations(int n, int total, long long* count, bool* stats , std::string& perm, std::set<std::string>& all_perms){
    if(*count == 0) return;
    if(n == 0){
        (*count)--;
        all_perms.insert(perm);
        all_perms.insert(std::string(perm.rbegin(), perm.rend()));
        return;
    }
    
    for(int i= 0; i<total; i++){
        if(stats[i] == false){
            stats[i]= true;
            perm.push_back(i+'A');
            generatePermutations(n-1, total, count,stats, perm, all_perms);
            perm.pop_back();
            stats[i]= false;
        }
    }
}

//wrapper function
void generatePermutations(int alphabets){
    //used to keep track of which elements have been added to current permutation
    bool* stats= new bool[alphabets];
    for(int i= 0; i<alphabets; i++){
        stats[i]= false;
    }
    
    //to print the permutations in  lexicographic order, they are stored here first
    std::set<std::string> all_permutations;
    long long half_count= factorial(alphabets);
    //used to store partial permutations and then is added to a set once it is completed
    std::string temp;
    
    generatePermutations(alphabets, alphabets, &half_count, stats, temp, all_permutations);
    delete stats;
    
    std::set<std::string>::iterator i= all_permutations.begin(), nd= all_permutations.end();
    int permutation_no= 1;
    while(i != nd){
        std::cout<< permutation_no <<" ";
        std::cout<< *i <<std::endl;
        i++;
        permutation_no++;
    }
}

int main(void)
{
    generatePermutations(3);
    
    return 0;
}


long long factorial(long long n){
    long long  f= n;
    while(--n){
        f*= n;
    }
    return f;
}
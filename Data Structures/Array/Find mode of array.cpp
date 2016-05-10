//finds the mode of an array,(most frequent element of the array in other words)
//used map to keep count of occurrence of each element
// the elements themselves are taken as keys
// and their occurrence is stored/incremented in their associated values

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//Return the most frequent element in the array
int getMode(int* ary, int len){
    map<int, int> occur;
    for(int i= 0; i<len; i++){
        occur[ary[i]]++;
    }
    
    map<int, int>::iterator mx = occur.begin();
    map<int, int>::iterator i = occur.begin();
    i++;
    
    while(i!=occur.end())
    {
        if(i->second > mx->second) mx = i;
        i++;
    }
    
    return mx->first;
}


int main(void)
{
    const int sz= 7;
    int a[sz]= {4,-2,4,4,43, -2, -2};
    
    cout<< getMode(a, sz) <<endl;
    
    
    return 0;
}
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


//takes an array, size of array and a number n
//returns a vector of pairs containing the pairs such that n = a+b
//returns an empty vector if no such pairs were found
template <typename T>
std::vector<std::pair<T,T>> findPair(T* ary, int size, const T& target){
    std::sort(ary,ary+size);
    std::vector<std::pair<T,T>> pairs;
    int l= 0, r= size-1;
    
    while(l<r){
        if(ary[l]+ary[r] == target){
            pairs.push_back(std::pair<T, T>(ary[l],ary[r]));
//           std::cout<< ary[l] << " " << ary[r] <<std::endl;
            l++;
            r--;
        }
        else if(ary[l]+ary[r] > target) r--;
        else l++;
    }
    
    return pairs;
}

int main(void)
{
    using namespace std;
    const int size= 10;
    int a[size] = {3, 6, 7, 1, 8, 2, 5, 4, 12, 9};
    
    vector<pair<int,int>> res = findPair(a, size, 10);
    
    if(res.empty()){
        cout<< "No pairs found!"<<endl;
    }
    
    int len= res.size();
    for(int i= 0; i<len; i++){
        cout<< res[i].first << " " << res[i].second <<endl;
    }
    
    return 0;
}
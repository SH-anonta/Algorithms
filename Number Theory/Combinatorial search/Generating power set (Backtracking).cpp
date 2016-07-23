//Generates power set of a given set/array using recursive Backtracking
//The figure below illustrates how this works:
//Each branch/edge represents a recursive call
//and where a, b or c means that element is chosen as part of the subset
// and _ means no elements were chosen
//basically weather the a or b or gets pushed into the subset array

//        *START*
//      /        \
//     a           _
//    /  \       /   \
//   b     _     b     _
//  / \   / \   / \   /  \
// c   _  c  _  c  _  c   _
//abc  ab ac a  bc  b c  [empty set]
//^^^ following each branch we get all possible subsets


#include <iostream>
#include <vector>
#include <string>


template <typename T>
void powerSet(T* ary, int len, std::vector<T> combo){
    //when there is no more items to choose (or not choose)
    if(len == 0){
        int sz= combo.size();
        for(int i= 0; i<sz; i++){
            std::cout<< combo[i] <<" ";
        }
        std::cout<<std::endl;
        return;
    }
    
    //dont take the next element
    powerSet(ary, len-1, combo);
    combo.push_back(ary[len-1]);
    //^take the next element
    powerSet(ary, len-1, combo);
}

//wrapper function
template <typename T>
void powerSet(T* ary, int len){
    powerSet(ary, len, std::vector<T>());
}

int main(void)
{
    using namespace std;
    char sampleSet[4]= "ABC";

//    generate power set of ABC
    powerSet(sampleSet, 3);
    return 0;
}
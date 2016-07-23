Generates power set of a given setarray using recursive Backtracking
#include iostream
#include vector
#include string


template typename T
void powerSet(T ary, int len, stdvectorT combo){
    if(len == 0){
        int sz= combo.size();
        for(int i= 0; isz; i++){
            stdcout combo[i]  ;
        }
        stdcoutstdendl;
        return;
    }
    
    powerSet(ary, len-1, combo);
    combo.push_back(ary[len-1]);
    powerSet(ary, len-1, combo);
}

wrapper function
template typename T
void powerSet(T ary, int len){
    powerSet(ary, len, stdvectorT());
}

int main(void)
{
    using namespace std;
    char sampleSet[4]= ABC;

    generate power set of ABC
    powerSet(sampleSet, 3);
    return 0;
}
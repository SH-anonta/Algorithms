//Implementation of the Josephus problem.
//If there are n people standing in a circle, and you start killing every k'th person in the circle
//who will be the last surviver?
//WiKi: https://en.wikipedia.org/wiki/Josephus_problem

#include <iostream>
#include <cmath>
using namespace std;

//returns the last/safe person in the circle
int jossef(int n, int k){
    if(n == 1) return 1;
    return ((jossef(n -1,k)+k-1)% n) + 1;
}

int main(){

    int n, k;

    cin>>n>>k;
	 cout<< jossef(n, k) <<"\n";

    return 0;
}

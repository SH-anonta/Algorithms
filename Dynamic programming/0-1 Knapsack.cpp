// 0-1 Knapsack problem
// given a list of items, their weight, their value
// and capacity of carrying weight
// what is the maximum value that can be taken

#include <iostream>

//store subproblem answers for reuse
long long cache[10000][10000];
int weight[10000];
int value[10000];

//with n items and capacity cap
//return maximum value that can be taken
long long knapsack(int n, int cap){
    for(int i= 0; i<= n; i++){
        for(int w= 0; w<= cap; w++){
            if(i == 0 || w == 0)
                cache[i][w]= 0;
            else if(weight[i-1] <= w)
                cache[i][w]= std::max(value[i-1] + cache[i-1][w-weight[i-1]], cache[i-1][w]);
            else
                cache[i][w]= cache[i-1][w];
        }
    }
    
    return cache[n][cap];
}

int main(void)
{
    using namespace std;
    
    int cap, n;
    cout<< "Provide (n) number items and weight capacity:\nn paris should follow, item weight and value:\n";
    cin>>cap>>n;
    
    for(int i= 0; i<n; i++){
        cin>>weight[i]>>value[i];
    }
        
    cout<< knapsack(n, cap) <<endl;
    
    
    return 0;
}
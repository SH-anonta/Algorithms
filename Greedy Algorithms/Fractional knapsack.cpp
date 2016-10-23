//fractional knapsack problem:
//given items their weights and values and capacity
//find the maximum value obtainable with given capacity
//considering we can take parts of an item
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>

//first is value second is weight
typedef std::pair<double, double> item;

//return if first item has greater value by weight ratio than the 
bool comp_item(item& a, item& b){
    return a.first/a.second > b.first/b.second;
}

//find the maximum value obtainable 
double mx_profit(item items[], int n, double capacity){
    double mx= 0;
    //sort items by their value/weight ratio in decreasing order
    sort(items, items+n, comp_item);
    
    for(int i= 0; i<n; i++){
        if(items[i].second <= capacity){
            capacity -= items[i].second;
            mx+= items[i].first;
        }
        else{
            mx+= items[i].first/items[i].second * capacity;
            capacity= 0;
            break;
        }
    }
    
    return mx;
}

int main(void)
{
    using namespace std;
    
    int n;
    item items[100];
    double capacity;
    
    cin>>n>>capacity;
    for(int i= 0; i<n; i++){
        cin>>items[i].first>>items[i].second;
    }
    
    cout<< mx_profit(items, n, capacity) <<endl;
    
    return 0;
}

/*
//n number of items, capacity
n lines: value (of current weight) weight
3 50

60 10
100 20
120 30
 */
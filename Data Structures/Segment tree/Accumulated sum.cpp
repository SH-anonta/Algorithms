//accumulated sum
//given an array of integers
//answer queries:
//given a range [i,j] (0 based indexing) give the sum of elements in that range
//update the array

//given the array a= {1 2 3 4 5 6}
//we can accumulate their sums and get 
// 1 3 6 10 15 21
//from which we can get the sum of any range in constant time
// sum of a[l, r]= (accumulated sum) acc= a[r]- a[l-1]
//ie sum of [2, 5]= acc[5]-a[2-1] = 15 - 1 = 14

//this data structure answers queries in O(1)
//and updates the data in O(n)
#include <iostream>
#include <string>


int main(void)
{
    using namespace std;
    
    int n;
    int data[100];
    int accumulate[100];
    
    cin>>n;
    for(int i= 1; i<=n; i++){
        cin>>data[i];
    }
    
    //store accumulated sum from data[i] to data[i] in accumulate[i]
    accumulate[0]= 0;
    for(int i= 1; i<=n; i++){
        accumulate[i] = accumulate[i-1]+data[i];
    }
    
    cout<< "Enter queries:\n1)range i j(get sum of elements in i-j)\n2)update i n (index new_element)"<<endl;
    cout<< "enter exit to exit"<<endl;
    
    string s;
    int l, r, k, e;
    while(cin>>s && s != "exit"){
        if(s == "range"){
            cin>>l>>r;
            
            cout<< l<<" "<<r<< " "<<accumulate[r]-accumulate[l-1] <<endl;
        }
        else if(s == "update"){
            cin>>k>>e;
            data[k]= e;
            for(int i = k; i<n; i++){
                accumulate[i]+= e;
            }
        }
    }
    
    return 0;
}
//Calculate all divisors of 1 to n in O(nlogn) time
#include <iostream>
#include <vector>


const int array_size= 1E6;
//store the divisors in here
std::vector<int> divisors[array_size+10];

//Calculate all divisors of 1 through n 
void generate_divisors(std::vector<int> divisors[], int n){
    for(int i= 1; i<=n; i++){
        for(int j= i; j<= n; j+= i){
            divisors[j].push_back(i);
        }
    }
}


int main(void)
{
    using namespace std;
    
    int n= 20, len;
    generate_divisors(divisors, n);
    
    cout<<"n: Divisors:\n";
    for(int i= 1; i<=n; i++){
        len= divisors[i].size();
        cout<< i <<": ";
        
        for(int j= 0; j<len; j++){
            cout<< divisors[i][j] <<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}
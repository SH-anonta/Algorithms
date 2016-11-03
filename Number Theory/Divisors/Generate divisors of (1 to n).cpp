Calculate all divisors of 1 through n in O(nlogn)
#include iostream
#include vector


const int array_size= 1E6;
store the divisors in here
stdvectorint divisors[array_size+10];

Calculate all divisors of 1 through n 
void generate_divisors(stdvectorint divisors[], int n){
    for(int i= 1; i=n; i++){
        for(int j= i; j= n; j+= i){
            divisors[j].push_back(i);
        }
    }
}


int main(void)
{
    using namespace std;
    
    int n= 20, len;
    generate_divisors(divisors, n);
    
    for(int i= 1; i=n; i++){
        len= divisors[i].size();
        cout i  ;
        
        for(int j= 0; jlen; j++){
            cout divisors[i][j]  ;
        }
        
        coutendl;
    }
    
    return 0;
}
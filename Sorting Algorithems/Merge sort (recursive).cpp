//Merge sort
// Worst case time complexity O(nlog(n))
// space complexity O(n)
// properties: in place, stable
// a divide and conquer algorithm
#include <iostream>
#include <cstdio>

using namespace std;

//Macros
short CC_;
#define sf scanf
#define pf printf
#define PP getchar();
#define NL cout<<"\n";
#define pqueue priority_queue
#define testb(x_, i_) ((x_&1<<i_)!=0)
#define setb(x_, i_) (x_=(x_|(1<<i_)))
#define clrb(x_, i_) (x_=(x_&(!(1<<i_))))
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

//pointer to full array, index of the two sub arrays to be merged
// l to mid is 1st sub array and mid+1 to r is the 2nd sub array
template <typename T>
void merge(T* ary, int l, int mid, int r){
    //memory for storing a copy of the two sub arrays
    int lim1= mid-l+1;
    int lim2= r-mid;
    //temporary storage for a copy of the two sub array
    T temp1[lim1], temp2[lim2];
    
    //copying contents of the two sub arrays to temporary storage
    for(int i= 0; i<lim1; i++){
        temp1[i]= ary[l+i];
    }
    for(int i= 0; i<lim2; i++){
        temp2[i]= ary[mid+i+1];
    }
    
    
    //merge the two sub arrays in to the original
    //(overriding the original array ) in ascending order
    int i1= 0, i2= 0, k= l;
    while(i1<lim1 && i2<lim2){
        if(temp1[i1] <= temp2[i2]){
            ary[k]= temp1[i1];
            i1++;
        }
        else if(temp1[i1] > temp2[i2]){
            ary[k]= temp2[i2];
            i2++;
        }
        k++;
    }
    
    //if one sub array is longer than the other
    //the above loop terminates and
    //the elements that were left in the longer one get added here
    while(i1<lim1){
        ary[k]= temp1[i1];
        i1++;
        k++;
    }
    while(i2<lim2){
        ary[k]= temp2[i2];
        i2++;
        k++;
    }
}

//left and right index limit of current sub array
template <typename T>
void mergeSort(T* ary, int l, int r){
    //if there is only one element per sub array
    if(l>=r) return;
    int mid= l+(r-l)/2;
    
    mergeSort(ary, l, mid);
    mergeSort(ary, mid+1, r);
    merge(ary, l, mid, r);
}

//wrapper function
template <typename T>
void mergeSort(T* st, T* nd){
    //calling the recursive function
    //sending array, and index of start and end points of the entire array
    mergeSort(st, 0, nd-st-1);
}


int main(void)
{
    using namespace std;
    
    const int sizea= 10;
    int ary[sizea]= {55, -9, 2, 77, 0, 21, 66, 21, -6, 100};
    
    mergeSort(ary, ary+sizea);
    
    for(int i= 0; i<sizea; i++){
        cout<< ary[i] <<" ";
    }
    cout<<endl;
    
    return 0;
}
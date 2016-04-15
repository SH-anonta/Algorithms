//Power set generation!
//Generate a power set of a set, store in a 2D vector

/*
 *Generate power set using bit mask:
 * power set of {A,B,C}
 * 0 = this element is not present, 1= this element is
 * 
 * 0 -> 000 no element 1 -> 001 1st element
 * 2 -> 010 2nd element 3 -> 011 1st and 2nd element
 * * ... (2^3)-1 or 7 -> 111 all three elements
 * Using this property of binary representation
 * we can get all combinations of the set elements
 * and as a whole these combination/subsets are our Power set :)
 */

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

typedef long long LL;            //"%lld"
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef unsigned long long ULL;  //"%llu"


short COUNT_;
#define SS pf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++COUNT_);
#define DD(x_) cout<<">>>>( "<<++COUNT_<<" ) "<<#x_<<": "<<x_<<endl;
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;



bool comp(const vector<int>& a,const  vector<int>& b){return a.size() < b.size();}

//arguments:
//1. array/set to generate power set of
//2. length of the array^
//3. the 2D vector in which the power set will be saved
template <typename T>
void powerSet(T* set, int len, vector<vector<T> >& pset)
{
     //sets limit to 2 raised to the power of len
     //there are total of 2^n combinations of the set elements
    int lim= (1<<len);
    pset.resize(lim);
    
    for(int mask= 0; mask<lim; mask++)
    {
        for(int i= 0; i<len; i++)
        {
            if((mask & 1<<i) != 0) //bit masking
            {
//                cout<<set[i] <<" ";
                pset[mask].push_back(set[i]);
            }
            
        }
            //separating each subset
//            cout<<endl;
    }
    
}


int main(void)
{
    double tt;
    const int setSize= 5;
    vector<vector<int> > pset;
//    int set[setSize]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int set[setSize]= {1, 2, 3, 4, 5};
    
    powerSet(set, setSize, pset);
    
    //execution time of generating power set of a set of 10 elements
    tt= (double)(clock())/CLOCKS_PER_SEC;
    
    //printing the stored power set

    //number of subsets //also equal to 2^setSize
    int subsets= pset.size(); 
    int elements;   //#of elements of current subset
    for(int i= 0; i<subsets; i++)
    {
        elements= pset[i].size();
        for(int j= 0; j<elements; j++)
        {
            cout<<pset[i][j] <<" ";
        }
        cout<<endl;
    }
    
    cout<< "Execution time>>>> :"<< tt <<endl;
    return 0;  
}




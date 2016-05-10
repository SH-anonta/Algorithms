//Implementation of two stacks in one array
//For space efficiency, the stacks stacks start piling elements form
//opposite sides of the array

#include <iostream>
#include <cstdlib>
using namespace std;

//Binary stack/ 2stacks in one array
template <typename T>
class binStack{
private:
    //length of array, position of top for stack 1 and 2
    int len, peek1, peek2;
    T* data;
    
public:
    binStack(int sz){ //size of the whole array
        data = new T[sz];
        len = sz;
        peek1= -1;
        peek2= sz;
    }
    
    //All both stacks have their own methods same name but numbered 1 and 2
    
    
    int size1(){
        return peek1+1;
    }
    
    int size2(){
        return len-peek2;
    }
    
    bool full(){
        return peek1 == peek2-1;
    }    
    
    bool empty1(){
        return peek1 == -1;
    }
    
    bool empty2(){
        return peek2 == len;
    }
    
    T& top1(void){
        return data[peek1];
    }
    
    T& top2(void){
        return data[peek2];
    }
    
    void push1(T obj){
        //if there is no space between the two stacks
        if(full()){ 
            cerr<<"Stack Overflow Error!"<<endl;
            exit(1);
        }
        
        peek1++;
        data[peek1] = obj;
    }
    
    void push2(T obj){
        //if there is no space between the two stacks
        if(full()){
            cerr<<"Stack Overflow Error!"<<endl;
            exit(1);
        }
        
        peek2--;
        data[peek2] = obj;
        
    }
    
    T pop1(void){
        if(empty1()){ //if first stack has no elements
            cerr<<"Stack Underflow Erroe!"<<endl;
            exit(1);
        }
        
        peek1--;
        return data[peek1+1];
    }
    
    T pop2(void){
        if(empty2()){ //if second stack has no elements
            cerr<<"Stack Underflow Erroe!"<<endl;
            exit(1);
        }
        peek2++;
        return data[peek1-1];
    }
    
};


int main(void)
{
    binStack<int> stacks(6);
    
    stacks.push1(1);
    stacks.push1(2);
    stacks.push1(3);
//    stacks.push1(7);

    stacks.push2(9);
    stacks.push2(8);
    stacks.push2(7);

    cout<<"stack 1:"<<endl;
    
    cout<< stacks.top1() <<endl;
    stacks.pop1();
    cout<< stacks.top1() <<endl;
    stacks.pop1();
    cout<< stacks.top1() <<endl;
    stacks.pop1();
    
    cout<<"\nstack 2:"<<endl;
    
    cout<< stacks.top2() <<endl;
    stacks.pop2();
    cout<< stacks.top2() <<endl;
    stacks.pop2();
    cout<< stacks.top2() <<endl;
    stacks.pop2();
    
    return 0;
}
//Simple implementation of fixed sized stack using array

#include <iostream>

using namespace std;

namespace myStack{
    
    template <typename T>
    class stack{
    private:
        int peek, capacity;
        T* array;
    public:
        stack(int sz){
            peek= -1;
            capacity = sz;
            array = new T[sz];
        }

        bool empty(){
            return peek == -1;
        }
        
        bool full(){
            return peek == capacity - 1;
        }
        
        void push(T obj){
            if(full()){
                cerr<<"Stack full  overflow error!"<<endl;
                return;
            }
            peek++;
            array[peek] = obj;
        }
        
        void pop(){
            if(empty()){
                cerr<<"Stack empty underflow error!"<<endl;
                return;
            }
            peek--;
        }
        
        T top(){
            if(empty()){
                cerr<<"Stack empty!"<<endl;
            }
            
            return array[peek];
        }
    };
}

class pin{
    int x, y;
};

int main(void)
{
    myStack::stack<int> a(10);
    
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    
    cout<< a.top() <<endl;
    a.pop();
    cout<< a.top() <<endl;
    a.pop();
    cout<< a.top() <<endl;
    a.pop();
    cout<< a.top() <<endl;
    a.pop();
    
    
    return 0;
}
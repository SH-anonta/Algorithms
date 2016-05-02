//Simple implementation of fixed sized stack using array

#include <iostream>

using namespace std;

namespace myStack{
    
    template <typename T>
    class stack{
    private:
        int position, capacity;
        T* array;
    public:
        stack(int sz){
            position= -1;
            capacity = sz;
            array = new T[sz];
        }

        bool empty(){
            return position == -1;
        }
        
        bool full(){
            return position == capacity - 1;
        }
        
        void push(T obj){
            if(full()){
                cerr<<"Stack full  overflow error!"<<endl;
                return;
            }
            position++;
            array[position] = obj;
        }
        
        void pop(){
            if(empty()){
                cerr<<"Stack empty underflow error!"<<endl;
                return;
            }
            position--;
        }
        
        T top(){
            if(empty()){
                cerr<<"Stack empty!"<<endl;
            }
            
            return array[position];
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
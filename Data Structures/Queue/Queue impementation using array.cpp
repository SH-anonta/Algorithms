//Simple implementation of a fixed sized Queue using an array
//the head and tail of the queue is circulated across the array

#include <iostream>
#include <cmath>
#include <cstdlib>

template <typename T>
class Queue{ 
private:
    //head tail position, enqueue limit, and current number of elements in the queue
    int head, tail, enqLmit, elementCount;
    T* data;
    
public:
    Queue(int cap){
        enqLmit = cap;
        data = new T[cap];
        elementCount= 0;
        head= 0;
        tail= cap-1;
    }
    
    T& front(){
        if(empty()){
            std::cerr<<"Error: Attempt to take data form empty Queue!"<<std::endl;
            exit(1);
        }
        
        return data[head];
    }
    
    T& back(void){
        if(empty()){
            std::cerr<<"Error: Attempt to take data form empty Queue!"<<std::endl;
            exit(1);
        }
        
        return data[tail];
    }
    
    bool empty(void){
        return (elementCount == 0);
    }
    
    bool full(void){
        return (elementCount == enqLmit);
    }
    
    int size(void){
        return elementCount;
    }
    
    int capacity(void){
        return enqLmit;
    }
    
    void enqueue(const T& obj){
        if(full()){
            std::cerr<< "Queue overflow error!" <<std::endl;
            return;
        }
        
        tail = (tail+1)%enqLmit;
        data[tail]= obj;
        elementCount++;
    }
    
    void dequeue(void){
        if(empty()){
            std::cerr<< "Queue underflow error!" <<std::endl;
            return;
        }
        
        head = (head+1)%enqLmit;
        elementCount--;
    }
};

int main(void)
{
    using std::cout;
    using std::endl;
    
    Queue<int> q(6);
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
//    q.enqueue(7);     //Expect overflow
    
    cout<< "is the queue full: " << q.full() <<endl;
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
//    q.dequeue();      //Expect underflow
    
    cout<< q.front() <<endl;
    cout<< q.back() <<endl;
    
    return 0;
}
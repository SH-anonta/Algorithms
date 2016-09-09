//Prority queue implementation using max binary heap implementation using complete binary tree
//using array in background

//all content inserted into the heap is stored in data array
//incase insertion exceeds array size, it automatically
//doubles the array's size, resizing can also be done through


#include <iostream>
#include <cstdlib>
#include <cstdio>


template <typename T>
class priorityQueue{
    //root stars at index 1
    T* data;
    //node capacity and count of elements inserted
    //rml = right most leaf's index int data
    int nodeCap, nodeCount, rml;
    static const int defaultCapacity= 30;

public:

    //default constructor
    priorityQueue(){
        nodeCap= defaultCapacity;
        nodeCount= 0;
        rml= 0;
        resize(nodeCap);
    }

    //constructor
    priorityQueue(const unsigned int initial_size){
        //1 more since root starts from index1
        nodeCap= initial_size+1;
        nodeCount= 0;
        rml= 0;
        resize(nodeCap);
    }
    
    //copy constructor
    priorityQueue(const priorityQueue& copy_from){
        //1 more since root starts from index1
        nodeCap= copy_from.nodeCap;
        nodeCount= copy_from.nodeCount;
        rml= copy_from.rml;
        if(data != NULL) delete[] data;
        data= new int[nodeCap];
        //copying the data over
        for(int i= 1; i<=rml; i++){
            data[i]= copy_from.data[i];
        }
    }

    //resizes the data array and copies the content to new location
    void resize(unsigned int new_size){
        nodeCap= new_size;
        T* to_delete= data;
        data = new T[new_size];
        
        int copy_upto= ((nodeCount< new_size)? nodeCount: new_size);
        //copy over data from old storage to new
        for(int i= 1; i<= copy_upto; i++){
            data[i]= to_delete[i];
        }

        if(to_delete != NULL) delete[] to_delete;
    }

    bool empty(){
        return nodeCount == 0;
    }

    unsigned int size(){
        return nodeCount;
    }

    unsigned int capacity(){
        return nodeCap;
    }

    void clear(){
        nodeCap= defaultCapacity;
        resize(nodeCap);
        nodeCount= 0;
        if(data != NULL) delete[] data;
    }

    //retrieve the top of heap
    const T& top(){
        if(empty()){
            std::cerr<< "Heap underflow error!" <<std::endl;
            exit(1);
        }

        //return element at the top of heap
        return data[1];
    }

    //max heapify the data teh data array
    //heapify_from which node
    void heapify(int heapify_from){
        int i= heapify_from;

        //swap last added element with it's parent until it's
        //at it's right place in the heap or it reaches root (index 1)
        while(i != 1 && data[i] > data[i/2]){
            std::swap(data[i], data[i/2]);
            i /= 2; //update index to new position
        }
    }

    void push(const T& dt){
        if(nodeCount+1 >= nodeCap){
            //if data array is too small, double it's size
            resize(2*nodeCap);
        }

        nodeCount++;
        //inserting new element into the complete binary tree
        rml++;
        data[rml]= dt;
        heapify(rml);
    }

    void pop(){
        if(empty()){
            std::cerr<< "Heap underflow error!" <<std::endl;
            exit(1);
        }

        nodeCount--;
        //replace root with right most leaf
        data[1]= data[rml];
        rml--;

        int i= 1, lchild, rchild;

        while(i<rml){
            lchild= 2*i;
            rchild= 2*i+1;
            if(data[lchild]>data[rchild] && lchild <= rml){
                std::swap(data[i], data[lchild]);
                i= lchild;
            }
            else if(rchild <= rml){
                std::swap(data[i], data[rchild]);
                i= rchild;
            }
            else break;
        }
    }

    //print data array
    void print(){
        for(int i= 1; i<= rml; i++){
            std::cout<< data[i] << " ";
        }
        std::cout<<std::endl;
    }

    ~priorityQueue(){
        delete[] data;
    }
};


int main(void)
{
    using namespace std;
    priorityQueue<int> a(1);

    char c;
    int ii;
    cout<< "Enter p to push an element(number)\nanything else to pop the top element\n";
    cout<< "state of the underlying heap will be printed\nalong with it's size and capacity"<<endl;
    while(cin>>c){
        if(c == 'p'){
            cin>>ii;
            a.push(ii);
        }
        else{
            a.pop();
        }

        cout<<"Heap: ";
        a.print();
        cout<<"Size: "<< a.size() <<"\n";
        cout<<"Capacity: "<< a.capacity()<<endl;
    }
    

    return 0;
}

//sort the given array using heap sort
//data structure used is a min heap
//time complexity: O(nlogn)
//space complexity: O(n)

#include <iostream>
#include <cstdlib>
#include <cstdio>

//declaration of class
template <typename T>
class minHeap;

template <typename T>
void heapSort(T* st, T* nd){
    const int ary_size= nd-st;

    minHeap<T> heap(ary_size);

    //insert the array into the min heap
    for(int i= 0; i<ary_size; i++){
        heap.push(st[i]);
    }

    //extracting the elements from heap
    //in ascending order and putting them into the array
    for(int i= 0; i<ary_size; i++){
//        heap.print();
        st[i]= heap.top();
        heap.pop();
    }
}

int main(void){
    using namespace std;


    const int len= 10;
    int a[len]= {50,1,-5,3,6,0,99,-5,0, 30};

    heapSort(a, a+len);

    for(int i= 0; i<len; i++){
        cout<< a[i] << " ";
    }
    cout<<endl;

    return 0;
}


template <typename T>
class minHeap{
    //root stars at index 1
    T* data;
    //node capacity and count of elements inserted
    //rml = right most leaf's index int data
    int nodeCap, nodeCount, rml;
    static const int defaultCapacity= 30;

public:

    //default constructor
    minHeap(){
        nodeCap= defaultCapacity;
        nodeCount= 0;
        rml= 0;
        resize(nodeCap);
    }

    //constructor
    minHeap(const unsigned int initial_size){
        //1 more since root starts from index1
        nodeCap= initial_size+1;
        nodeCount= 0;
        rml= 0;
        resize(nodeCap);
    }

    //resizes the data array and copies the content to new location
    void resize(unsigned int new_size){
        nodeCap= new_size;
        T* to_delete= data;
        data = new T[new_size];
        int copy_upto= ((nodeCount< new_size )? nodeCount: new_size);
        //copy over data from old storage to new
        for(int i= 1; i<= copy_upto; i++){
            data[i]= to_delete[i];
        }

        delete[] to_delete;
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
        nodeCount= 0;
        delete[] data;
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
        while(i != 1 && data[i] < data[i/2]){
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
            if(data[lchild]<data[rchild] && lchild <= rml){
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

    ~minHeap(){
        delete[] data;
    }
};

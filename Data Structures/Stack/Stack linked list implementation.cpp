// Stack implemented using singly linked list

#include <iostream>
#include <cstdlib>

template <typename T>
class Stack{
private:
    class Node{
    public:
        Node* previous;
        T data;
        
        Node(const T& item){
            data = item;
            previous = NULL;
        }
        Node(){
            previous = NULL;
        }
    };
    
    int nodeCount;
    Node* peek;
    
public:
    //Default constructor
    Stack(){
        peek= NULL;
        nodeCount= 0;
    }
    
    //copy constructor
    Stack(const Stack& cpy){
//        if(this == &cpy){
//            return;
//        }
//        
//        clear();
//        if(cpy.empty()){
//            return;
//        }
        nodeCount = cpy.nodeCount;
        peek = new Node(cpy.peek->data);
        Node* i= cpy.peek->previous; //points to copy Stack
        Node* j= peek;               //points to this Stack
        
        for(Node* i= cpy.peek->previous; i!=NULL; i= i->previous, j= j->previous){
            j->previous = new Node(i->data);
        }
        
    }
    
    bool empty(){
        return nodeCount == 0;
    }
    
    T& top(){
        if(empty()){
            std::cerr<< "Stack underflow error!"<<std::endl;
            exit(1);
        }
        return peek->data;
    }
    
    void push(const T& item){
        nodeCount++;
        Node* temp = new Node(item);
        temp->previous = peek;
        peek = temp;
    }
    
    void pop(){
        if(empty()){
            std::cerr<< "Stack underflow error!"<<std::endl;
            return;
        }
        
        nodeCount--;
        Node* temp= peek->previous;
        delete peek;
        peek = temp;
    }
    
    void clear(){
        if(nodeCount == 0) return;
        Node* i= peek;
        Node* temp;
        while(i != NULL){
            temp= i->previous;
            delete i;
            i= temp;
        }
        
        peek= NULL;
        nodeCount= 0;
    }
    
    //TODO
    Stack& operator=(const Stack& cpy){

    }
    
    ~Stack(){
        clear();
    }
    
    //print all node of stack
    void print(){
        for(Node* i = peek; i!=NULL; i= i->previous){
            std::cout<< i->data <<" ";
        }
        std::cout<<std::endl;
    }
};

int main(void)
{
    using namespace std;
    Stack<int> s;
    
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(5);
    
    Stack<int> d(s);
    
//    s.print();
    d.print();
    
    d.pop();
    d.clear();
    
    
    return 0;
}
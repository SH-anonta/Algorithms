// Stack implimented using singly linked list
//Bug: Explicitly calling clear() causes un predictable behaviour

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
        Node* i= peek;
        Node* temp;
        while(i != NULL){
            using namespace std;
            // cout<< "Previous: "<< i->previous <<endl;
            
            temp= i->previous;
            delete i;
            i= temp;
        }
    }
    
    ~Stack(){
        clear();
    }
};

int main(void)
{
    using namespace std;
    Stack<int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;
    s.pop();
    
    s.push(1);
    s.push(2);
    s.push(3);
    
//    s.clear();
    
    
    return 0;
}
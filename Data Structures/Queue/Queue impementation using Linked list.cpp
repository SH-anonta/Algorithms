// Queue implementation using Linked list

#include <iostream>
#include <cstdlib>

template <typename T>
class Queue{
private:
    class Node{
    public:
        T data;
        Node* next;
        Node(){next = NULL;}
        Node(const T& cpy){
            data = cpy;
            next = NULL;
        }
    };
    Node *head, *tail;
    int nodeCount;
    
public:
    //default constructor
    Queue(){
        head= tail= NULL;
        nodeCount= 0;
    }
    
    //copy constructor
    Queue(Queue& cpy){
        if(cpy.empty()){
            head= tail= NULL;
            nodeCount= 0;
            return;
        }
        head= tail= new Node(cpy.head->data);
        for(Node* i= cpy.head->next; i!=NULL; i= i->next){
            push(i->data);
        }
    }
    
    int size(){
        return nodeCount;
    }
    bool empty(){
        return nodeCount == 0;
    }
    
    void push(const T& cpy){
        //if queue if empty
        if(nodeCount == 0){
            head= tail= new Node(cpy);
        }
        else{
            tail->next = new Node(cpy);
            tail = tail->next;
        }
        nodeCount++;
    }
    
    void pop(){
        if(nodeCount == 0){
            std::cerr<< "Queue underflow error!\n";
            return;
        }
        
        Node* temp= head;
        head= head->next;
        delete temp;
        nodeCount--;
    }
    
    T& front() const{
        if(nodeCount == 0){
            std::cerr<< "Queue underflow error!\n";
            exit(1);
        }
        return head->data;
    }
    
    T& rear() const{
        if(nodeCount == 0){
            std::cerr<< "Queue underflow error!\n";
            exit(1);
        }
        return tail->data;
    }
    
    void clear(){
        //if Queue is already empty
        if(nodeCount == 0) return;
        Node* i= head;
        Node* temp;
        while(i != NULL){
            temp= i->next;
            delete i;
            i= temp;
        }
        
        head= tail= NULL;
        nodeCount= 0;
    }
    
    //for testing
    void print(){
        for(Node* i= head; i!=NULL; i= i->next){
            std::cout<< i->data <<" ";
        }
        std::cout<<std::endl;
    }
    
    ~Queue(){
        clear();
    }
};


//std::cout<< "AAAAAAAAA"<<std::endl;

int main(void)
{
    using namespace std;
    
    Queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    q.pop();
    q.push(4);
//    cout<< q.rear() <<endl;
    q.clear();
    Queue<int> qq(q);
    
    qq.print();
    
    return 0;
}
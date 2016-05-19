//This is an implementation of a doubly linked list
//This data structure supports the operations listed below
//
// constructors: default constructor, copy constructor
// Push and Pop form back and front
// clear the whole list
// Basic getters: front and back node->data
// 
// TODO: previous pointer, insert, remove, swap, delete, iterator
// Assignment operator, find, concat two lists, 

//// Bug: Copy Constructor, new object has garbage value and program crashes to traverse it

#include <iostream>
#include <cstdio>

using namespace std;


short CC_;
#define NL pf("\n");
#define dcc (double)
#define PP getchar();
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

template <typename T>
class List
{
//private:
    public:     //TODO: make private!
    class Node{
    public:
        Node* next;
//        Node* previous;
        T data;
        //constructors
        Node(void){
            next= NULL;
        }
        Node(const T& store):data(store){
            next= NULL;
        }
    };
    
    //Instance variables
    int nodeCount;
    Node* head;
    Node* tail;
    
public:
    //Default constructor
    List(){
        nodeCount= 0;
        tail= NULL;
        head= NULL;
    }
    
    //TODO: Fix bug Copy constructor
    List(const List& cpy){
        //doing self copy would result in erasing it's own data
        if(this == &cpy){
            SS
            return;
        }
        
        clear();
        Node* i= cpy.head;
        while(i != NULL){
            this->pushBack(i->data);
            i = i->next;
        }
    }
    
    //Destructor
    ~List(){
        clear();
    }
    
    T& front(){
        return head->data;
    }
    
    T& back(){
        return tail->data;
    }
    bool empty(){
        return nodeCount == 0;
    }
    
    int size(){
        return nodeCount;
    }
    
    void clear(){
        nodeCount= 0;
        if(empty()) return;
        Node* i= head;
        Node* iback;
        
        while(i != NULL){
            iback= i;
            i = i->next;
            delete iback;
        }
        
        head = tail = NULL;
    }
    
    void pushBack(const T& element){
        nodeCount++;
        if(tail == NULL){
            head = tail = new Node(element);
            return;
        }
        
        tail->next= new Node(element);
        tail = tail->next;
    }
    
    void pushFront(const T& element){
        nodeCount++;
        if(head == NULL){
            head = tail = new Node(element);
            return;
        }
        
        Node* temp = new Node(element);
        temp->next= head;
        head = temp;
    }
    
    void popFront(){
        nodeCount--;
        delete head;
        head = head->next;
    }
    
    //TODO add popBack()
    
    void print(){
        Node* i= head;
        //Until the next pointer is 0
        while(i != NULL){
            std::cout<< i->data <<" ";
            i= i->next;
        }
        std::cout<<std::endl;
    }
};

int main(void)
{
    List<int> a;
    
    a.pushBack(12);
    a.pushBack(13);
    a.pushBack(14);
    
    a.pushFront(212);
    a.pushFront(293);
    a.pushFront(292);
    
    cout<< "Linked List a:\n";
    
    a.print();
    

    List<int> b(a);
    
    
    cout<< "Linked List b:\n";
    b.print();
    
    return 0;
}
//This is an implementation of a doubly linked list
//This data structure supports the operations listed below
//
// constructors: default constructor, copy constructor
// Push and Pop form back and front
// clear the whole list
// Basic getters: front and back node->data
// 
// TODO: previous pointer, insert, remove, swap, delete, iterator
// Copy constructor for List and array, Assignment operator

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
    
    //Copy constructor
    List(const List& cpy){
        //doing self copy would result in erasing it's own data
        if(this == &cpy){
            SS
            return;
        }
        
        clear();
        Node* i= cpy.head;
        while(i != NULL){
            pushBack(i->data);
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
        delete head;
        head = head->next;
    }
    
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
    List<int> l;
    
    l.pushBack(12);
    l.pushBack(13);
    l.pushBack(14);
    
    l.pushFront(212);
    l.pushFront(293);
    l.pushFront(292);
    
    cout<< "Linked List l:\n";
    l.print();
    
    
    List<int> m(l);
    
    cout<< "Linked List l:\n";
    m.print();
    
    return 0;
}
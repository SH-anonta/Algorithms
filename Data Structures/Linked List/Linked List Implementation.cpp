//Author: Anonta Sofen Haque
//This is an implementation of a doubly linked list
//This data structure supports the operations listed below
//TODO:  Assignment operator, find, concat two lists, 
//// TODO Bugs: Copy constructor, do deep copy

#include <iostream>
#include <cstdio>
#include <cstdlib>

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
    private:
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
        Node* i= cpy.head;
        head= tail= new Node(i->data);
        i = i->next;
        nodeCount++;
        while(i != NULL){
            tail->next = new Node(i->data);
            i = i->next;
            tail = tail->next;
            nodeCount++;
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
    
    inline bool empty(){
        return nodeCount == 0;
    }
    
    inline int size(){
        return nodeCount;
    }
    
    //removes idx th node
    void remove(int idx){
        if(idx<0 || idx >= nodeCount){
            std::cerr<< "Invalid index of list!\n";
            exit(1);
        }
        if(empty()){
            std::cerr<< "List underflow error!\n";
            return;
        }
        if(idx == 0){
            popFront();
            return;
        }
        
        Node* i= head, *temp;
        while(idx-- > 1) i = i->next;
        temp= i->next;
        i->next = temp->next;
        delete temp;
        nodeCount--;
    }
    
    void clear(){
        if(empty()){
            return;
        }
        nodeCount= 0;
        Node* i= head;
        Node* iback = NULL;
        
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
        if(empty()){
            std::cerr<< "List underflow error!\n";
            return;
        }
        
        Node* temp= head;
        head = head->next;
        delete temp;
        nodeCount--;
    }
    
    void popBack(){
        if(empty()){
            std::cerr<< "List underflow error!\n";
            return;
        }
        
        int i = nodeCount - 1;
        Node* nd = head;
        while(i-- >1) nd = nd->next;
        
        delete nd->next;
        nd->next = NULL;
        nodeCount--;
    }
    
    //insert a node containing dt at idx th position
    void insert(int idx, const T& dt){
        if(idx<0 || idx >= nodeCount){
            std::cerr<< "Invalid index of list!\n";
            exit(1);
        }
        if(idx == 0){
            pushFront(dt);
            return;
        }
        
        Node* i= head, *temp;
        while(idx-- > 1) i = i->next;
        temp= new Node(dt);
        temp->next = i->next;
        i->next = temp;
        nodeCount++;
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
    
    //print reverse
    void rprint(Node* hd){
        if(hd == NULL) return;
        rprint(hd->next);
        std::cout<< hd->data <<" ";
        if(hd == head) std::cout<<std::endl;
    }
    
    //wrapper function for ^ reverse print
    void rprint(){
        rprint(head);
    }
    
    //BUG
//    List(const List& cpy){
//        //doing self copy would result in erasing it's own data
//        if(this == &cpy){
//            return;
//        }
//        
//        clear();
//        Node* i= cpy.head;
//        while(i != NULL){
//            this->pushBack(i->data);
//            i = i->next;
//        }
//    }
    
    T& operator[](int idx){
        if(idx<0 || idx >= nodeCount){
            std::cerr<< "Invalid index of list!\n";
            exit(1);
        }
        Node* i= head;
        while(idx--) i = i->next;
        
        return i->data;
    }
    
};

int main(void)
{
    using namespace std;
    
    List<int> a;
    
    a.pushBack(12);
    a.pushBack(13);
    a.pushBack(14);
    
    a.pushFront(33);
    a.pushFront(29);
    a.pushFront(22);
    
    cout<< "Linked List a:\n";
    
    a.print();
//    a.rprint();
    
//    a.popFront();
//    a.popFront();
//    a.popBack();
    
//    a.remove(5);
    
    a.insert(0, 11);
    a.insert(3, 1);
    a.print();
    a.rprint();
    
//    a[3] = 13;
//    cout<< a[3] <<endl;
    
//    cout<< a.size()<<endl;
    
    return 0;
}
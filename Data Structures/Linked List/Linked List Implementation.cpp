#include <iostream>
#include <cstdio>

using namespace std;


short CC_;
#define sf scanf
#define pf printf
#define NL pf("\n");
#define dcc (double)
#define PP getchar();
#define SS pf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

template <typename T>
class List
{
//private:
public:
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
    //constructors
    List(){
        nodeCount= 0;
        tail= NULL;
        head= NULL;
    }
    
    //Destructor
    ~List(){
        clear();
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
    
    void pushBack(T element){
        nodeCount++;
        if(tail == NULL){
            head = tail = new Node(element);
            return;
        }
        
        tail->next= new Node(element);
        tail = tail->next;
    }
    
    void print(){
        Node* i= head;
        //Until the next pointer is 0
        while(i != NULL){
            cout<< i->data <<endl;
            i= i->next;
        }
        
    }
};

int main(void)
{
    List<int> l;
    
    l.pushBack(12);
    l.pushBack(13);
    l.pushBack(14);
    l.pushBack(72);
    
    l.print();
    
    return 0;
}
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

//// Bug:

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

<<<<<<< HEAD
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
            return;
        }
=======
//constants
const int SZ= 1E6;
const int INF= (1<<29);
const double EPS= 1E-9;
const double PI= 2*acos(0.0);

//functions templates
template <class T>void DA(T* x, int l){for(int i=0; i<l;i++)cout<<"["<<i<<"]>> "<<x[i]<<'\n';}
template <class T>inline void sary(T* st, T* nd){while(st<nd)cin>>*st++;/*sf("%d", st++);*/}
template <class T>void tobin(T n,char*bin){int pos= 1<<((int)log2(n));while(pos>=1){if((n & pos)==0)*bin='0';else*bin='1';pos>>=1;bin++;}*bin='\0';}
template <class T>int strOccur(string&s,T&tgt){int oc= 0, p= s.find(tgt);while(p != string::npos){p = s.find(tgt, p+1);oc++;}return oc;}
template <class T>inline T LCM(T x,T y){return((x*y)/__gcd(x,y));}
int bigMod(int b,int e,int m){if(e==0)return 1;if(!e&1){int temp=bigMod(b,e/2,m)%m;return(temp*temp)%m;}else return((b%m)*(bigMod(b,e-1,m))%m)%m;}
LL todec(char* bin){LL dec= 0;short i= 0, len= strlen(bin) -1;while(bin[i]){if(bin[i++]=='1'){dec += 1<<len;} len--;}return dec;}
inline LL POW(LL base, int exp){LL p= 1; while(exp-->0){p *= base;} return p;}
bool ispal(char* str, int len){for(int i= 0; i<len/2; i++){if(str[i]==str[len-i-1]){}else return false;}return true;}
bool comp(const int& a,const int& b){return a>b;}

>>>>>>> parent of a34727c... template update

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
    bool empty(){
        return nodeCount == 0;
    }
    
    int size(){
        return nodeCount;
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
    
};

int main(void)
{
    List<int> a;
    
    a.pushBack(12);
    a.pushBack(13);
    a.pushBack(14);
    
    a.pushFront(33);
    a.pushFront(29);
    a.pushFront(22);
    
    cout<< "Linked List a:\n";
    
    a.print();
    
    List<int> b(a);
    b = a;
    b.print();
    
    return 0;
}
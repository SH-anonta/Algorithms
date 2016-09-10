//undirected and unweighted graph using adjacency lists

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

//Debug macros
short CC_;
#define sf scanf
#define pf printf
#define PP getchar();
#define NL cout<<"\n";
#define pqueue priority_queue
#define testb(x_, i_) ((x_&1<<i_)!=0)
#define setb(x_, i_) (x_=(x_|(1<<i_)))
#define clrb(x_, i_) (x_=(x_&(!(1<<i_))))
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;


template <typename T>
class undirectedGraph{
    class Node{
    public:
        T data;
        Node* next;
        
        Node(){
            data= T();
            next= NULL;
        }
        Node(const T& dt){
            data= dt;
            next= NULL;
        }
    };
    
    //array of list/nodes
    Node* data;
    int nodeCap, nodeCount, edgeCount, lastNode;
    static const int default_nodeCap= 10;
    public:
        
    //default constructor
    undirectedGraph(){
        nodeCount= 0;
        lastNode= -1;
        nodeCap= default_nodeCap;
        resize(nodeCap);
        data= NULL;
    }
    
    undirectedGraph(int initial_capacity){
        //making data null
        nodeCount= 0;
        lastNode= -1;
        nodeCap= initial_capacity;
        resize(nodeCap);
        data= NULL;
//        memset(data, 0, sizeof(Node*)*nodeCap);
        resize(nodeCap);
    }
    
    void resize(int new_cap){
        Node* to_delete= data;
        
        //adding 5 more node space just for safety
        if(nodeCount < new_cap) new_cap= nodeCount+5;
        data= new Node[new_cap];
        //copy data from old memory to new memory
        //outer loop traverses from vertex to vertex
        //inner loop visits all of it's edges
        for(int i= 0; i<nodeCount; i++){
            data[i]= to_delete[i];
        }
        
        delete[] to_delete;
    }
    
    void addVertex(const T& dt){
        if(data == NULL){
            resize(default_nodeCap);
            lastNode= 0;
            nodeCount++;
            data[0]= Node(dt);
            return;
        }
        if(nodeCap <= nodeCount){
            resize(2*nodeCap);
        }
        
        nodeCount++;
        lastNode++;
        data[lastNode]= Node(dt);
    }
    
    void addEdge(const T& u, const T& v){
        static bool added_to_v= false;
        if(data == NULL || empty()){
            return;
        }
        
        for(int i= 0; i<=lastNode; i++){
            if(data[i].data == u){
                Node* temp= data[i].next;
                data[i].next= new Node(v);
                data[i].next->next=temp;
            }
        }
        
        //to add the edge to vertex v
        if(added_to_v == false){
            added_to_v= true;
            addEdge(v, u);
        }
        else added_to_v= false;
    }
    
    int size(){
        return nodeCount;
    }
    
    bool empty(){
        return nodeCount == 0;
    }
    
    void clear(){
        for(int i= 0; i<nodeCount; i++){
            for(Node* j= &data[i], *temp; j!=NULL;){
                temp= j;
                j= j->next;
                delete temp;
            }
        }
    }
    
    //print the adjacency list
    void print(){
        for(int i= 0; i<nodeCount; i++){
            std::cout<< i <<": ";
            for(Node* j= &data[i]; j!=NULL; j= j->next){
                std::cout<< j->data << "->";
            }
            std::cout<<"\\0"<<std::endl;
        }
    }
    
    ~undirectedGraph(){
        clear();
    }
};

int main(void)
{
    undirectedGraph<int> a;
    a.addVertex(1);
    a.addVertex(2);
    a.addVertex(3);
    
    a.addEdge(1, 3);
    a.addEdge(2, 3);
    a.addEdge(2, 1);
    a.print();
    
    return 0;
}
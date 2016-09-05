#include <iostream>
#include <cstdio>

using namespace std;

namespace{
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
}

template <typename T>
class binarySearchTree{
private:
    class Node{
    public:
        T data;
        Node *lChild, *rChild;
        
        Node(){
            data= T();
            lChild= rChild= NULL;
        }
        
        Node(const T& dt){
            data= dt;
            lChild= rChild= NULL;
        }
    };
    Node* root;
    int nodeCount;
    
public:    
    //default constructor
    binarySearchTree(){
        root= NULL;
        nodeCount= 0;
    }
    
    bool empty(){
        return nodeCount == 0;
    }
    
    int size(){
        return nodeCount;
    }
    
    //wrapper function
    const T* find(const T& target){
        if(empty()){
            std::cerr<< "Underflow error!"<<std::endl;
        }
        
        Node* temp= find(root, target);
        if(temp == NULL) return NULL;
        return &temp->data;
    }
    
    //find and return pointer to found element. NULL if not found
    Node* find(Node* next, const T& target){
        //target not found
        if(next == NULL) return NULL;
        //target found
        else if(next->data == target) return next;
        else if(next->data < target) return find(next->rChild, target);
        else return find(next->lChild, target);
    }
    
    Node* insert(Node* next, const T& dt){
        if(next == NULL){
            return new Node(dt);
        }
        
        if(dt == next->data){
            nodeCount--;    //decreasing previously increased count as duplicates are not allowed
            return next;
        }
        else if(dt < next->data)
            next->lChild= insert(next->lChild, dt);
        else
            next->rChild= insert(next->rChild, dt);
        
        return next;
    }
    
    //Find and return pointer to in-order successor in the tree
    Node* inorderSuccessor(Node* subRoot){
        subRoot= subRoot->rChild;
        while(subRoot->lChild != NULL){
            subRoot= subRoot->lChild;
        }
        
        return subRoot;
    }
    
    void insert(const T& dt){
        nodeCount++;
        if(root == NULL){
            root = new Node(dt);
            return;
        }
        
        insert(root, dt);
    }
    
    
    //wrapper function
    void remove(const T& target){
        if(empty()){
            return;
        }
        
        //if remove was successful / returned non null pointer
        if(find(root, target)){
            nodeCount--;
            remove(root, target);
            if(nodeCount == 0) root= NULL;
        }
    }
    
    Node* remove(Node* next, const T& target){
        if(next == NULL) return NULL;
        
        if(target == next->data){
            //node has only one or no child
            if(next->lChild == NULL){
                Node* temp= next->rChild;
                delete next;
                return temp;
            }
            //node has only one or no child
            else if(next->rChild == NULL){
                Node* temp= next->lChild;
                delete next;
                return temp;
            }
            //node has two children
            //replace this node with next larger element in the tree
            Node* inorder_successor= inorderSuccessor(next);
            next->data= inorder_successor->data;
            next->rChild= remove(next->rChild, inorder_successor->data);    
        }
        else if(target < next->data)
            next->lChild= remove(next->lChild, target);
        else
            next->rChild= remove(next->rChild, target);
        
        return next;
    }
    
    
    void clear(Node* doom){
        if(doom == NULL) return;
        if(doom->lChild != NULL)
            clear(doom->lChild);
        if(doom->rChild != NULL)
            clear(doom->rChild);
        delete doom;
    }
    
    //wrapper function
    void clear(){
        if(!empty()) clear(root);
    }
    
    //traverse and print each element in-order
    void printInOrder(Node* next){
        if(next == NULL) return;
        else{
            printInOrder(next->lChild);
            std::cout<< next->data <<" ";
            printInOrder(next->rChild);
        }
    }
    
    //in order traversal wrapper function
    void printInOrder(){
        if(empty()) return;
        printInOrder(root);
        std::cout<<std::endl;
    }
    
    
    ~binarySearchTree(){
        clear();
    }
};

int main(void)
{
    using namespace std;
    
    binarySearchTree<int> a;
    
    char cmd;
    int temp;
    
    cout<< "press p *number* to insert a number in the bst"<<endl;
    cout<< "press r *number* to remove a number in the bst"<<endl;
    while(cin>>cmd){
        if(cmd == 'p'){
            cin>>temp;
            a.insert(temp);
        }
        else if(cmd == 'r'){
            cin>>temp;
            a.remove(temp);
        }
        
//        DD(a.root)
        a.printInOrder();
        cout<< "Size: "<< a.size() <<endl;
//        cout<< "ios: "<< ((a.inorderSuccessor(a.root) != NULL)? a.inorderSuccessor(a.root)->data : 99999) <<endl;
    }
    
    
    return 0;
}
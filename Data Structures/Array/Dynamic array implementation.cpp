// Dynamic array implementation
// in other words Simplified version of vector class
// array's size must be changed manually 

#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
    int capacity;
//    int elementCount;
    T* data;
    
public:
    //Constructors
    //Default
    Vector(){
        capacity = 0;
        data = NULL;
    }
    
    explicit Vector(int sz){
        data = new T[sz];
        capacity = sz;
    }
    
    Vector(int sz, const T& cont){
        data = new T[sz];
        capacity = sz;
        for(int i= 0; i<sz; i++){
            data[i] = cont;
        }
    }
    
    Vector(T& cpy){
        if(cpy.capacity > capacity){
            clear();
            data = new T[cpy.capacity];
        }   
        
        capacity = cpy.capacity;
        for(int i= 0; i<capacity; i++){
            data[i] = cpy.data[i];
        }
    }
    
    //TODO copy constructor
    Vector(const Vector& cpy){
        if(this == &cpy) return;
        
        clear();
        resize(cpy.capacity);   //TODO check for bugs
        for(int i= 0; i<cpy.capacity; i++){
            data[i] = cpy.data[i];
        }
    }
    
    //Destructor
    ~Vector(){
        delete[] data;
    }
    
    void resize(int newSize){
        T* temp= new T[newSize];
        if(newSize < capacity) capacity = newSize;
        
        for(int i= 0; i<capacity; i++){
            temp[i] = data[i];
        }
        
        capacity = newSize;
        swap(data, temp);
        delete[] temp;
    }
    
    void clear(){
        delete[] data;
        capacity = 0;
        data= NULL;
    }
    
    int size(){
        return capacity;
    }
    
    void insert(int index, const T& cpy){
        if(index<0 || index>capacity-1){
            std::cerr<< "Can not remove! Invalid index\n";
            return;
        }
        
        for(int i= capacity-1; i>index; i--){
            data[i] = data[i-1];
        }
        data[index]= cpy;
    }
    
    
    void remove(const int index){
        if(index<0 || index>capacity-1){
            std::cerr<< "Can not remove! Invalid index\n";
            return;
        }
        
        for(int i= index; i<capacity-1; i++){
            data[i] = data[i+1];
        }
    }
    
    T& operator[](int index){
        return data[index];
    }
    
    void operator=(Vector& cpy){
        if(cpy.capacity > capacity){
            clear();
            data = new T[cpy.capacity];
        }   
        
        capacity = cpy.capacity;
        for(int i= 0; i<capacity; i++){
            data[i] = cpy.data[i];
        }
    }
    
    //print whole array
    void print(){
        for(int i= 0; i<capacity; i++){
            cout<< data[i] <<" ";
        }
        cout<<endl;
    }
    
};

int main(void)
{
    Vector<int> a(5);
    
    a[0]= 1;
    a[1]= 2;
    a[2]= 3;
    a[3]= 4;
    
    a.remove(1);
    a.remove(0);
    a.insert(0, 3);
    a.insert(2, 8);
    a.insert(3, 5);
    
    a.print();
    
    
    return 0;
}
// Dynamic array implementation

#include <iostream>

using namespace std;

template <typename T>
class dArray
{
private:
    int dCount;
    T* data;
    
public:
    //Constructors
    //Default
    dArray(){
        data = NULL;
    }
    
    explicit dArray(int sz){
        data = new T[sz];
        dCount = sz;
    }
    
    dArray(int sz, const T& cont){
        data = new T[sz];
        dCount = sz;
        for(int i= 0; i<sz; i++){
            data[i] = cont;
        }
    }
    
    //TODO copy constructor
    dArray(const dArray& cpy){
        if(this == &cpy) return;
        
        clear();
        resize(cpy.dCount);   //TODO check for bugs
        for(int i= 0; i<cpy.dCount; i++){
            data[i] = cpy[i];
        }
    }
    
    //Destructor
    ~dArray(){
        delete[] data;
    }
    
    void resize(int newSize){
        T* temp= new T[newSize];
        if(newSize < dCount) dCount = newSize;
        
        for(int i= 0; i<dCount; i++){
            temp[i] = data[i];
        }
        
        dCount = newSize;
        swap(data, temp);
        delete[] temp;
    }
    
    void clear(){
        delete[] data;
        dCount = 0;
        data= NULL;
    }
    
    int size(){
        return dCount;
    }
    
    T& operator[](int index){
        return data[index];
    }
    
    void operator=(dArray& cpy){
        if(cpy.dCount > dCount){
          
            clear();
            data = new T[cpy.dCount];
        }   
        
        dCount = cpy.dCount;
        for(int i= 0; i<dCount; i++){
            data[i] = cpy[i];
        }
    }
    
    void print(){
        for(int i= 0; i<dCount; i++){
            cout<< data[i] <<" ";
        }
        cout<<endl;
    }
    
};

int main(void)
{
    dArray<int> a(5);
    
    a[0]= 1;
    a[1]= 2;
    a[2]= 3;
    a[3]= 4;
    
    a.print();
    
    a.resize(10);
    
    a[4]= 23;
    a.print();
    return 0;
}
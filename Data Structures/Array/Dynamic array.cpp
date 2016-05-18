// Dynamic array implementation

#include <iostream>

using namespace std;

template <typename T>
{
private:
    int capacity;
    T* data;
    
public:
    //Constructors
    //Default
        capacity = 0;
        data = NULL;
    }
    
        data = new T[sz];
        capacity = sz;
    }
    
        data = new T[sz];
        capacity = sz;
        for(int i= 0; i<sz; i++){
            data[i] = cont;
        }
    }
    
    //TODO copy constructor
        if(this == &cpy) return;
        
        clear();
        resize(cpy.capacity);   //TODO check for bugs
        for(int i= 0; i<cpy.capacity; i++){
            data[i] = cpy[i];
        }
    }
    
    //Destructor
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
    
    T& operator[](int index){
        return data[index];
    }
    
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
    
    a[0]= 1;
    a[1]= 2;
    a[2]= 3;
    a[3]= 4;
    
    
    a.resize(10);
    
    a[4]= 23;

    a.print();
    
    
    b= a;
    
    b.print();
    return 0;
}

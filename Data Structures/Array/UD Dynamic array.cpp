//UNDER DEVELOPMENT
// Dynamic array implementation

#include <iostream>

using namespace std;

template <typename T>
class dynamicArray
{
private:
    int dCount;
    int dCapacity;
    T* data;
    
public:
    //Constructors
    //Default
    dynamicArray(){
        data = NULL;
    }
    
    explicit dynamicArray(int sz){
        data = new T[sz];
        dCount = sz;
    }
    
    dynamicArray(int sz, const T& cont){
        data = new T[sz];
        dCount = sz;
        for(int i= 0; i<sz; i++){
            data[i] = cont;
        }
    }
    
    //Destructor
    ~dynamicArray(){
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
    
};

int main(void)
{
    
    return 0;
}
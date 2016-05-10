//Multidimensional arrays are just arrays that keep pointers to other arrays
//To make a dynamic array we'll be creating the array at runtime using only the amount of space needed
//In this particular code, wee will make a 2D array that has variable sized sub arrays of variable number of elements

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //to make a dynamic 2D array of fixed size at runtime:
    
    //size of array(row) and sub arrays(col) 
    const int row= 9, col= 8;
    
    //CREATING THE 2D ARRAY
    int** seq= new int*[row];
    //creating row number of subsequences / array to store them
    for(int i= 0; i<row; i++)
    {
        int* subSeq= new int[col];
        
        //storing address to the subsequence in the sequence array
        seq[i] = subSeq;
    }
    
    
    //DELETING THE 2D ARRAY
    //deleting the sequences
    for(int i= 0; i<row; i++){
        delete[] seq[i];
    }
    //deleting the array containing pointers to those sequences
    delete[] seq;
    
    
    
    //to make a dynamic 2D array of variable size at runtime:
    int no_of_sequences, no_of_elements, a, b;
    //n is the number of sequence to store
    cin>>no_of_sequences;
    
    //Name: sequence set, an array of pointers
    //Creating the array which will contain pointers to the sub arrays
    int** seqSet = new int*[(const int)no_of_sequences];

    //this loop creates k sized arrays, and takes input from the 
    for(int i= 0; i<no_of_sequences; i++){
        cin>>no_of_elements;
        //creating array of needed size to store the sequence
        int* seq = new int[(const int)no_of_elements];
        
        //taking input to the sequence
        for(int j= 0; j<no_of_elements; j++){
            cin>>seq[j];
        }
        
        //storing the address of the sequence in the sequence set
        seqSet[i]= seq;
    }

    
    //deleting the sequences
    for(int i= 0; i<no_of_sequences; i++){
        delete[] seqSet[i];
    }
    //deleting the array containing pointers to those sequences
    delete[] seqSet;
    
    return 0;
}

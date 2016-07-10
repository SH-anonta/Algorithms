//This code sums the individual digits number (iteratively)
//then does the same to the sum until a 1 digit number is obtained
//So 64689 = 6+4+6+8+9 = 23 = 3+3 = 6

#include <iostream>

//Sums digits of a number until 1 digit number is obtained
template <typename T>
int sumDigits(T num){
    T temp;
    while(num >9 || num< -9){
        temp= 0;
        while(num != 0){
            temp+= num%10;
            num /= 10;
        }
        num = temp;
    }
    
    return num;
}

int main(void)
{
    using namespace std;
    
    cout<< sumDigits(64689) <<endl;
    
    return 0;
}
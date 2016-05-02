//This code sums the individual digits number
//then does the same to the sum until a 1 digit number is achived

#include <iostream>

using namespace std;

//Sums digits of a number until 1digit number is achived
int sumDigits(int num){
    int sum= 0;
    if(num < 10) return num;
    else{
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sumDigits(sum);
    }
}

int main()
{
	cout<< sumDigits(458741) <<endl;
	return 0;
}
//Code generates factorial of numbers in big integers scale
package jd1;

import java.util.Scanner;
import java.math.*;


class JD1{
    
    static BigInteger bigFactorial(BigInteger num){
        BigInteger fact = BigInteger.ONE;
        
        while(!num.equals(BigInteger.ONE)){
            fact = fact.multiply(num);
            num = num.subtract(BigInteger.ONE);
        }
        
        return fact;
    }
    
    public static void main(String args[]){
        JD1 MAIN = new JD1();
        Scanner sc = new Scanner(System.in);
        
        BigInteger n;
        System.out.print("Enter a number: ");
        n= sc.nextBigInteger();
        
        BigInteger ans= bigFactorial(n);
        System.out.println("Factorial:\n" + ans);
    }
}
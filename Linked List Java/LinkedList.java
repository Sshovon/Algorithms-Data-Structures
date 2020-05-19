import java.math.BigInteger;
import java.util.Scanner;



public class LinkedList{

    static BigInteger fact(int n){
        BigInteger ans = BigInteger.ONE;
        
        for(int i=2;i<=n;i++)
            ans=ans.multiply(BigInteger.valueOf(i));


        return ans;
    }

    public static void main(String ... args){
        Scanner sc= new Scanner(System.in);
        int x= sc.nextInt();
        String s= fact(x).toString();
        System.out.println(s.length());      
    }

}


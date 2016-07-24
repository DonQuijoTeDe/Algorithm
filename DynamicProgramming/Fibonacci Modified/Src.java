import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BigInteger t1 = input.nextBigInteger();
        BigInteger t2 = input.nextBigInteger();

        BigInteger[] bigint = new BigInteger[21];
        bigint[1] = t1;
        bigint[2] = t2;

        int n = input.nextInt();

        for(int i=3;i<=n;i++){
            bigint[i] = bigint[i-2].add(bigint[i-1].pow(2));
        }

        System.out.println(bigint[n]);
    }
}

package alphacode;

import java.util.Objects;
import java.util.Scanner;

public class Main {

    public static boolean isSmallerThan26(char a, char b){
        if(a>='3') return false;
        return a != '2' || b < '7';
    }

    public static void main(String[] args){
        String alphaCode;
        Scanner sc = new Scanner(System.in);
        while(true){
            alphaCode = sc.nextLine();
            if(Objects.equals(alphaCode, "0")) break;
            int[] dp = new int[alphaCode.length()];
            dp[0] = 1;
            if(alphaCode.length()>=2){
                if (isSmallerThan26(alphaCode.charAt(0), alphaCode.charAt(1)))
                {
                    if (alphaCode.charAt(1) == '0')
                    {
                        dp[1] = 1;
                    }
                    else
                    {
                        dp[1] = 2;
                    }
                }
                else
                {
                    dp[1] = dp[0];
                }
            }
            for (int i = 2; i < alphaCode.length(); i++)
            {
                if (isSmallerThan26(alphaCode.charAt(i-1), alphaCode.charAt(i)))
                {
                    if (alphaCode.charAt(i) == '0')
                    {
                        dp[i] = dp[i - 2];
                    }
                    else if (alphaCode.charAt(i-1) == '0')
                    {
                        dp[i] = dp[i - 1];
                    }
                    else
                    {
                        dp[i] = dp[i - 1] + dp[i - 2];
                    }
                }
                else
                {
                    dp[i] = dp[i - 1];
                }
            }
            System.out.println(dp[alphaCode.length()-1]);
        }
    }
}

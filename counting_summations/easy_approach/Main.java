package counting_summations.easy_approach;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long[][] dp = new long[(n + 1)][(n + 1)];
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - i];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[n][n]);
    }
}

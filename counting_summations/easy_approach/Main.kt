package counting_summations.easy_approach

import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val n: Int = sc.nextInt()

    val dp = Array(n + 1) { LongArray(n + 1) }
    dp[0][0] = 1

    for (j in 1..n) {
        dp[0][j] = 0
    }

    for (i in 1..n) {
        for (j in 0..n) {
            if (i <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i]
            } else {
                dp[i][j] = dp[i - 1][j]
            }
        }
    }
    print(dp[n][n])
}
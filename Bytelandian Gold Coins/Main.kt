package bytelandian_gold_coins

import java.util.Scanner
import java.util.HashMap

val dp = HashMap<Long, Long>()

fun maxCoin(n: Long): Long {
    if (!dp.containsKey(n)) {
        dp[n] = maxOf(n, maxCoin(n / 2) + maxCoin(n / 3) + maxCoin(n / 4))
    }
    return dp[n]!!
}

fun main() {
    val scanner = Scanner(System.`in`)
    var n : Long
    dp[0L] = 0L
    while (scanner.hasNextLong()) {
        n = scanner.nextLong()
        println(maxCoin(n))
    }
}

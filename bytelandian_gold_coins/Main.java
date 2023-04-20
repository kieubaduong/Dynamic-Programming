package bytelandian_gold_coins;

import java.util.HashMap;
import java.util.Scanner;

public class Main {
    private static HashMap<Long, Long> dp = new HashMap<Long, Long>();

    public static long maxCoin(long n) {
        if (!dp.containsKey(n)) {
            dp.put(n, Math.max(n, maxCoin(n / 2) + maxCoin(n / 3) + maxCoin(n / 4)));
        }
        return dp.get(n);
    }

    public static void main(String[] args) {
        dp.put(0L, 0L);
        try (Scanner sc = new Scanner(System.in)) {
            while (sc.hasNextLong()) {
                System.out.println(maxCoin(sc.nextLong()));
            }
        }
    }
}
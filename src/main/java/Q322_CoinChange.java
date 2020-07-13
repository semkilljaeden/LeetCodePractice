/***
 * 1hr, went into the wrong direction
 * Runtime: 45 ms, faster than 12.78% of Java online submissions for Coin Change.
 * Memory Usage: 42.5 MB, less than 5.42% of Java online submissions for Coin Change.
 */
public class Q322_CoinChange {
    int[] memo;
    public int coinChange(int[] coins, int amount) {
        if(coins.length == 0 || amount == 0) {
            return 0;
        }
        memo = new int[amount];

        return rec(coins, amount);
    }

    public int rec(int[] coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return - 1;
        }
        if(memo[amount - 1] != 0) {
            return memo[amount - 1];
        }
        int result = Integer.MAX_VALUE;
        for(int i = 0; i < coins.length; i++) {
            int r = rec(coins, amount - coins[i]);
            if(r >= 0) {
                result = Math.min(result, r + 1);
            }
        }
        memo[amount - 1] = (result == Integer.MAX_VALUE) ? -1 : result;
        return memo[amount - 1];
    }
}

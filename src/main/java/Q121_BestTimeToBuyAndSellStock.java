/***
 * 13mins easy
 * Runtime: 1 ms, faster than 99.22% of Java online submissions for Best Time to Buy and Sell Stock.
 * Memory Usage: 39.3 MB, less than 73.69% of Java online submissions for Best Time to Buy and Sell Stock.
 */
public class Q121_BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0) {
            return 0;
        }
        int low = prices[0];
        int high = prices[0];
        int price = 0;
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] > prices[i - 1]) {
                if(prices[i] > high) {
                    high = prices[i];
                    int tp = high - low;
                    if(tp > price) {
                        price = tp;
                    }
                }
            }
            else if(prices[i] < prices[i - 1]) {
                if(prices[i] < low) {
                    low = prices[i];
                    high = low;
                }
            }
        }
        return price;
    }
}

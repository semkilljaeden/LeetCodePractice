import java.util.Arrays;

/***
 * 6mins brutal force
 * Runtime: 17 ms, faster than 37.36% of Java online submissions for Count Number of Teams.
 * Memory Usage: 38.6 MB, less than 24.69% of Java online submissions for Count Number of Teams.
 */
public class Q1395_CountNumberOfTeams {
    public int numTeams(int[] rating) {
        int count = 0;
        for(int i = 0; i < rating.length; i++) {
            for(int j = i + 1; j < rating.length; j++) {
                if(rating[j] < rating[i]) {
                    for(int h = j + 1; h < rating.length; h++) {
                        if(rating[h] < rating[j]) {
                            count++;
                        }
                    }
                }
                else if(rating[j] > rating[i]) {
                    for(int h = j + 1; h < rating.length; h++) {
                        if(rating[h] > rating[j]) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }

    public int numTeamsDP(int[] rating) {
        int[] dp = new int[rating.length];
        int count = 0;
        for(int i = 0; i < rating.length; i++) {
            for(int j = i; j >= 0; j--) {
                if(rating[j] > rating[i]) {
                    dp[i]++;
                    count += dp[j];
                }
            }
        }
        Arrays.fill(dp, 0);
        for(int i = 0; i < rating.length; i++) {
            for(int j = i; j >= 0; j--) {
                if(rating[j] < rating[i]) {
                    dp[i]++;
                    count += dp[j];
                }
            }
        }
        return count;
    }
}

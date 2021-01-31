#include<vector>

using namespace std;
//read the answer. sieve...

/*
Runtime: 40 ms, faster than 73.56% of C++ online submissions for Count Primes.
Memory Usage: 19.4 MB, less than 13.33% of C++ online submissions for Count Primes.
Next challenges:
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n, 0);
        if (n < 3)
        {
            return 0;
        }
        prime[0] = 1, prime[1] = 1;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i] == 0) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 1;
                }
            }
        }
        return count(prime.cbegin(), prime.cend(), 0);
    }
};
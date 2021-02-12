#include<vector>
using namespace std;
//5:11
//read the answer, useful algo to decide rectangle overlapping
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return c(A, B, C, D, E, F, G, H);

    }
    int c(long A, long B, long C, long D, long E, long F, long G, long H) {
        long full = (C - A) * (D - B) + (G - E) * (H - F);
        if (!(A <= G && C >= E && B <= H && D >= F))
        {
            return full;
        }

        long is = (min(C, G) - max(E, A)) * (min(D, H) - max(B, F));
        return full - is;

    }

};
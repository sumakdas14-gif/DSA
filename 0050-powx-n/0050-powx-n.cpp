class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        bool isNegative = (N < 0);
        if (isNegative) {
            N = -N;
        }

        // Use long double internally to eliminate intermediate precision drift
        long double result = 1.0;
        long double current_product = x;

        while (N > 0) {
            if (N % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }

        return isNegative ? (double)(1.0L / result) : (double)result;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0;
        long long evenCount = 1; // Base case for prefix sum 0 (which is even)
        long long currentSum = 0;
        long long result = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            currentSum += num;

            if (currentSum % 2 != 0) { // If current prefix sum is odd
                result = (result + evenCount) % MOD;
                oddCount++;
            } else { // If current prefix sum is even
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }

        return result;
    }
};
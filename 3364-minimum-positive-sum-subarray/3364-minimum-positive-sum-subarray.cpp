class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        
        // Iterate over all possible subarray lengths from l to r
        for (int len = l; len <= r; ++len) {
            // Check all subarrays of the current length
            for (int i = 0; i <= n - len; ++i) {
                int currentSum = 0;
                for (int j = i; j < i + len; ++j) {
                    currentSum += nums[j];
                }
                
                // We only care about positive sums
                if (currentSum > 0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }
        
        // If minSum wasn't updated, no such subarray exists
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};
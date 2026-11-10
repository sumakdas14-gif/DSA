class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Find the element just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Swap them
            swap(nums[i], nums[j]);
        }
        
        // Reverse the remaining elements to get the next lexicographical permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};
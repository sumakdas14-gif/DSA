class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // If we have reached the end of the array, add the current permutation to result
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            // Place the current element at the 'start' position
            swap(nums[start], nums[i]);
            
            // Recurse for the remaining elements
            backtrack(nums, start + 1, result);
            
            // Backtrack (restore the array to its original state)
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};
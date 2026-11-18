class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
        // If the current permutation is of the same length as nums, add it to results
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip if the element is already visited in the current path
            if (visited[i]) continue;
            
            // To handle duplicates: if the current element is equal to the previous one,
            // and the previous one was not used in this branch, skip it to avoid duplicate permutations.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            visited[i] = true;
            current.push_back(nums[i]);
            
            backtrack(nums, visited, current, result);
            
            // Backtrack
            current.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        
        // Sort the array first so duplicate elements are adjacent
        sort(nums.begin(), nums.end());
        
        backtrack(nums, visited, current, result);
        return result;
    }
};
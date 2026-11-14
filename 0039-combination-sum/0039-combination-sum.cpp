class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue; // Since candidates are positive, we can skip if it exceeds target
            
            current.push_back(candidates[i]);
            // Pass 'i' again because the same element can be chosen multiple times
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
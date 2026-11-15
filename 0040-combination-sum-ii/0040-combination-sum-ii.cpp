class Solution {
private:
    void backtrack(int index, int target, vector<int>& candidates, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates at the same tree level
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            // If the current candidate exceeds the remaining target, stop searching this branch
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            // i + 1 ensures each element is used only once
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort to handle duplicates and allow early stopping
        sort(candidates.begin(), candidates.end());
        
        backtrack(0, target, candidates, current, result);
        return result;
    }
};
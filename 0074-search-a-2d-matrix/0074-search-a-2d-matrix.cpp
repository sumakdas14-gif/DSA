class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = (m * n) - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Convert 1D mid index back to 2D row and column coordinates
            int row = mid / n;
            int col = mid % n;
            int midVal = matrix[row][col];
            
            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};
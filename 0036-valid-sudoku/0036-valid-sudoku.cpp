class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track the presence of digits (1-9) in rows, columns, and 3x3 boxes
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // Skip empty cells
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '0';
                int box_index = (i / 3) * 3 + (j / 3);
                
                // If the number is already present in the current row, column, or box, it's invalid
                if (rows[i][num] || cols[j][num] || boxes[box_index][num]) {
                    return false;
                }
                
                // Mark the number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_index][num] = true;
            }
        }
        
        return true;
    }
};
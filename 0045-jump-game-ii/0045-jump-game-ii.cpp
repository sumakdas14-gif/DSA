#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        // We don't need to iterate up to the last element because 
        // the jump happens before or at the second-to-last element.
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Keep track of the farthest reachable index from the current position
            farthest = std::max(farthest, i + nums[i]);
            
            // If we reach the boundary of the current jump, we increment our jump count
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // Early exit if we can already reach or exceed the last index
                if (currentEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};
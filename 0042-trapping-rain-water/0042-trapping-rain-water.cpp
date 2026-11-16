#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left]; // Update max on the left
                } else {
                    totalWater += leftMax - height[left]; // Water trapped
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right]; // Update max on the right
                } else {
                    totalWater += rightMax - height[right]; // Water trapped
                }
                right--;
            }
        }
        
        return totalWater;
    }
};
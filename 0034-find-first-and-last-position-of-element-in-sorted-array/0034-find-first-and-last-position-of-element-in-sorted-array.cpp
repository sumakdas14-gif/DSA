#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        // If the target isn't found at all, no need to search for the end
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid; // Record potential answer
                if (isFirst) {
                    right = mid - 1; // Keep searching left for an earlier occurrence
                } else {
                    left = mid + 1;  // Keep searching right for a later occurrence
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bound;
    }
};
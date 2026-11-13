#include <vector>
#include <deque>

class Solution {
public:
    long long countNonDecreasingSubarrays(std::vector<int>& nums, long long k) {
        long long ans = 0;
        long long cost = 0;
        std::deque<int> dq; // Stores indices with nums[i] in non-increasing order
        
        int n = nums.size();
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            int num = nums[i];
            
            // Maintain monotonic stack/deque property
            while (!dq.empty() && nums[dq.back()] < num) {
                int l = dq.back();
                dq.pop_back();
                int r = dq.empty() ? j + 1 : dq.back();
                // Add the extra operations needed when raising elements to `num`
                cost += static_cast<long long>(r - l) * (num - nums[l]);
            }
            
            dq.push_back(i);
            
            // Shrink the window from the right if cost exceeds k
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }
            
            // Add all valid subarrays ending between i and j
            ans += (j - i + 1);
        }
        
        return ans;
    }
};
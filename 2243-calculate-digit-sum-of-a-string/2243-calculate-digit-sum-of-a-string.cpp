#include <string>

class Solution {
public:
    std::string digitSum(std::string s, int k) {
        // Repeat the process while the length of s is greater than k
        while (s.length() > k) {
            std::string nextRound = "";
            
            // Process the string in chunks of size k
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                
                // Calculate the sum of digits in the current group
                for (int j = i; j < i + k && j < s.length(); j++) {
                    sum += s[j] - '0';
                }
                
                // Append the sum string to the next round string
                nextRound += std::to_string(sum);
            }
            
            s = nextRound; // Update s for the next round
        }
        
        return s;
    }
};
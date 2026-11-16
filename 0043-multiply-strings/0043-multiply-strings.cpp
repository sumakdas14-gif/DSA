#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        std::vector<int> result(n1 + n2, 0);
        
        // Multiply each digit from right to left
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                
                int sum = digit1 * digit2 + result[i + j + 1];
                
                result[i + j + 1] = sum % 10; // Store current digit
                result[i + j] += sum / 10;    // Carry to the next position
            }
        }
        
        // Convert vector to string, ignoring leading zeros
        std::string resStr = "";
        for (int num : result) {
            if (!(resStr.empty() && num == 0)) {
                resStr.push_back(num + '0');
            }
        }
        
        return resStr.empty() ? "0" : resStr;
    }
};
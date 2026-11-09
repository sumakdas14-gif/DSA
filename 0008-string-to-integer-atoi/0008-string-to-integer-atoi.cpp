class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // 1. Whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) return 0;
        
        // 2. Signedness
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        // 3. Conversion and 4. Rounding
        long long result = 0;
        while (i < n &&isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check overflow/underflow
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return result * sign;
    }
};
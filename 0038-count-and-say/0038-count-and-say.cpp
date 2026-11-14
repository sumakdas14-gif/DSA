class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        
        for (int i = 2; i <= n; ++i) {
            string next = "";
            int length = current.length();
            
            for (int j = 0; j < length; ) {
                int count = 1;
                while (j + 1 < length && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
                next += to_string(count) + current[j];
                j++;
            }
            current = next;
        }
        
        return current;
    }
};
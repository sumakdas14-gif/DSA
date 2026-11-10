#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Sort the strings
        sort(strs.begin(), strs.end());
        
        // The common prefix of the whole array must be a common prefix 
        // of the lexicographically first and last strings in the sorted array.
        string first = strs[0];
        string last = strs.back();
        
        int minLength = min(first.length(), last.length());
        int i = 0;
        
        while (i < minLength && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};
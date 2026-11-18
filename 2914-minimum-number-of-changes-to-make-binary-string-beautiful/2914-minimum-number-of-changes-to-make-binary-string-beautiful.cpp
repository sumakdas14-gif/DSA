class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        
        // Check the string in non-overlapping pairs of characters (step of 2)
        for (int i = 0; i < s.length(); i += 2) {
            // If the characters in the pair don't match, we need 1 change to make them uniform
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        
        return changes;
    }
};
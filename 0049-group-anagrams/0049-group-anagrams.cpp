#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }

            // Build a unique key from character counts
            string key;
            key.reserve(s.size() * 2);
            for (int i = 0; i < 26; ++i) {
                key += '#';
                key += to_string(count[i]);
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& entry : groups) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};
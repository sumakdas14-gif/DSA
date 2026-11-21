class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        // DFS 1: Determine the new parent for every node simultaneously
        auto find_parents = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int prev_ancestor = last_seen[char_idx];

            if (u != 0 && prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }

            last_seen[char_idx] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            // Backtrack state before returning to parent
            last_seen[char_idx] = prev_ancestor;
        };

        find_parents(find_parents, 0);

        // Build the modified tree
        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        // DFS 2: Calculate subtree sizes on the final tree
        vector<int> ans(n, 1);
        auto count_sizes = [&](auto& self, int u) -> int {
            for (int v : new_adj[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        count_sizes(count_sizes, 0);
        return ans;
    }
};
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            // First leaf node found gives the shortest root-to-leaf path
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }

            if (node->left != nullptr) {
                q.push({node->left, depth + 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, depth + 1});
            }
        }

        return 0;
    }
};
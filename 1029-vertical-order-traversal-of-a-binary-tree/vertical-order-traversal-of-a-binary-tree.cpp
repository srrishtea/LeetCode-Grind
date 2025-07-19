/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            TreeNode* node = current.first;
            int x = current.second.first;
            int y = current.second.second;
            nodes[x][y].push_back(node->val);
            
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& col : nodes) {
            vector<int> column;
            for (auto& row : col.second) {
                vector<int>& vals = row.second;
                sort(vals.begin(), vals.end());
                column.insert(column.end(), vals.begin(), vals.end());
            }
            result.push_back(column);
        }
        
        return result;
    }
};
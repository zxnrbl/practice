#include <bits/stdc++.h>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;

        dfs(vec, root);

        return vec;
    }

private:
    void dfs(vector<int>& vec, TreeNode* root) {
        if(root == nullptr)
            return;

        dfs(vec, root->left);
        vec.emplace_back(root->val);
        dfs(vec, root->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution s;

    return 0;
}

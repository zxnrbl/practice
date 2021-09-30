#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> s;

        inOrderDFS(root, s);

        for(int i = 1; i < k; ++i) {
            cout << s.front() << "\n";
            s.pop();
        }

        return s.front()->val;
    }

private:
    void inOrderDFS(TreeNode* root, queue<TreeNode*>& s) {
        if(root == nullptr) return;

        inOrderDFS(root->left, s);
        s.push(root);
        inOrderDFS(root->right, s);
    }
};

int main() {
    array<TreeNode, 4> test1;
    test1.at(0).val = 3;
    test1.at(0).left = &test1.at(1);
    test1.at(0).right = &test1.at(2);
    test1.at(1).val = 1;
    test1.at(1).left = nullptr;
    test1.at(1).right = &test1.at(3);
    test1.at(2).val = 4;
    test1.at(2).left = nullptr;
    test1.at(2).right = nullptr;
    test1.at(3).val = 2;
    test1.at(3).left = nullptr;
    test1.at(3).right = nullptr;

    Solution s;

    cout << s.kthSmallest(test1.data(), 1) << endl;

    return 0;
}

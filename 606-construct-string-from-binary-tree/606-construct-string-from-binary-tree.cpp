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
    void formulateString(string& ans, TreeNode* node) {
        if (node == nullptr)
            return;
        ans.append(to_string(node -> val));
        ans.push_back('(');
        formulateString(ans, node -> left);
        if(ans.back() == '(' and node -> right == nullptr)
            ans.pop_back();
        else
            ans.push_back(')');
        ans.push_back('(');
        formulateString(ans, node -> right);
        if(ans.back() == '(')
            ans.pop_back();
        else
            ans.push_back(')');
    }
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        formulateString(ans, root);
        return ans;
    }
};
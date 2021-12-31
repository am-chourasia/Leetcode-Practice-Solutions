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
struct Minmax{
    int min;
    int max;
    Minmax(){
        min = INT_MAX;
        max = INT_MIN;
    }
    Minmax(int minimum, int maximum){
        min = minimum;
        max = maximum;
    }
};
class Solution {
    int ans;
public:
    int maxAncestorDiff(TreeNode* root) {
        ans = INT_MIN;
        helper(root);
        return ans;
    }
    Minmax helper(TreeNode* node){
        if(node == nullptr)
            return Minmax();
        if(node->right == nullptr and node->left == nullptr)
            return Minmax(node->val, node->val);
        Minmax left = helper(node->left);
        Minmax right = helper(node->right);
        Minmax descendant = Minmax(min(left.min, right.min), max(left.max, right.max));
        int difference1 = abs(node->val - descendant.min);
        int difference2 = abs(node->val - descendant.max);
        ans = max({ans, difference1, difference2});
        return Minmax(min(descendant.min, node->val), max(descendant.max, node->val));
    }
};
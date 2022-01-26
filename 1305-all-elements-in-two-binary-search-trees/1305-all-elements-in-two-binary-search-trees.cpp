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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        makeList(root1, list1);
        makeList(root2, list2);
        return merge(list1, list2);
    }
    void makeList(TreeNode* root, vector<int>& list){
        if(root == nullptr)
            return;
        makeList(root->left, list);
        list.push_back(root->val);
        makeList(root->right, list);
    }
    vector<int> merge(vector<int>& list1, vector<int>& list2){
        int n = list1.size();
        int m = list2.size();
        vector<int> merged(n+m);
        int i = 0, j = 0;
        
        for(int k = 0; k < n+m; k++){
            if(i < n and j < m){
               if(list1[i] < list2[j])
                   merged[k] = list1[i++];
               else
                   merged[k] = list2[j++];
            }
            else if(i < n){
                merged[k] = list1[i++];
            }
            else {
                merged[k] = list2[j++];
            }
        }
        
        return merged;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        std::stack<ListNode*> stack;
        vector<int> ans;
        
        ListNode* curr = head;
        while(curr != nullptr){
            while(not stack.empty() and stack.top()->val < curr->val){
                stack.top() -> val = curr -> val;
                stack.pop();
            }
            stack.push(curr);
            curr = curr -> next;
        }
        
        while(not stack.empty()){
            stack.top() -> val = 0;
            stack.pop();
        }
        
        curr = head;
        while(curr != nullptr){
            ans.push_back(curr -> val);
            curr = curr -> next;
        }
        
        return ans;
    }
};
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
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node!=nullptr){
            node = node->next;
            n++;
        }
        node = head;
        int ans = 0;
        while(n--){
            ans += (node->val == 1) ? (1<<n) : 0;
            node = node->next;
        }
        return ans;
    }
};
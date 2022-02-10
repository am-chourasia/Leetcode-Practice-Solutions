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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        ListNode *it1, *it2;
        it1 = list1;
        it2 = list2;
        ListNode *head = nullptr;
        if(it1->val < it2->val){
            head = it1;
            it1 = it1->next;
        } else {
            head = it2;
            it2 = it2->next;
        }
        
        ListNode* node = head;
        
        while(it1 != nullptr and it2 != nullptr){
            if(it1->val < it2->val){
                node->next = it1;
                it1 = it1->next;
            } else {
                node->next = it2;
                it2 = it2->next;
            }
            node = node->next;
        }
        while(it1 != nullptr){
            node->next = it1;
            it1 = it1->next;
            node = node->next;
        }
        while(it2 != nullptr){
            node->next = it2;
            it2 = it2->next;
            node = node->next;
        }
        return head;
    }
};
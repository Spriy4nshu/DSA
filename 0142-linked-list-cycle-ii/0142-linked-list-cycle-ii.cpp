/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hSet;
        ListNode* curr = head;
        while(curr != nullptr) {
            if(hSet.find(curr) != hSet.end()) {
                return curr;
            }
            else {
                hSet.insert(curr);
            }
            curr = curr->next;
        }
        return nullptr;
    }
};
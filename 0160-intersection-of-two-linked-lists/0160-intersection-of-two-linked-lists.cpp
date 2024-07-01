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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int p1Count = 0;
        int p2Count = 0;
        while(p1 != nullptr) {
            if(p1 != nullptr) p1 = p1->next;
            p1Count++;
        }
        while(p2 != nullptr) {
            p2 = p2->next;
            p2Count++;
        }
        p1 = headA;
        p2 = headB;
        for(int i = 0; i < abs(p1Count - p2Count); i++) {
            if(p1Count > p2Count) {
                p1 = p1->next;
            }
            else {
                p2 = p2->next;
            }
        }
        if(p1 == p2) return p1;
        while(p1 != p2 && p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2) return p1;
        }
        return nullptr;
    }
};
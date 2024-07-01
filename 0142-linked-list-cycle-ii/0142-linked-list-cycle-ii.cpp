/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// hastset based solution
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> hSet;
//         ListNode* curr = head;
//         while(curr != nullptr) {
//             if(hSet.find(curr) != hSet.end()) {
//                 return curr;
//             }
//             else {
//                 hSet.insert(curr);
//             }
//             curr = curr->next;
//         }
//         return nullptr;
//     }
// };

// slow and fast pointer based solution
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                break;
            }
        }
        if(fast == nullptr || fast->next == nullptr) return nullptr;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
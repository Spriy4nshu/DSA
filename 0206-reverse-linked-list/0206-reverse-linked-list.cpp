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

// Slow-Fast Pointer
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) return head;
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         ListNode* fast = head->next;
//         while(fast != nullptr){
//             curr->next = prev;
//             prev = curr;
//             curr = fast;
//             fast = fast->next;
//         }
//         curr->next = prev;
//         return curr;
//     }
// };

// Recursive
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) return head;
//         ListNode *result = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return result;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *result = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return result;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr->next != nullptr){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }

        return curr;
    }
};
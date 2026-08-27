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


 // optimal approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        ListNode* current= head;
        while(current!= NULL){
           ListNode* next = current->next;

            current->next = last;

            last = current;
            current = next;

        }
    return last;
    }
};
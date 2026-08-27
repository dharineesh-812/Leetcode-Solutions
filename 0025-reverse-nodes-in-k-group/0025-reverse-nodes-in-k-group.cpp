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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
            return head;

        ListNode *cur = head;
        ListNode *newhead = nullptr;
        ListNode *tail = nullptr;

        while(cur != NULL){
            ListNode* check = cur;
            int count  = 0;

            while(check != NULL && count < k){
                count++;
                check = check -> next;
            }
            if(count < k){
                if(tail != NULL)
                    tail -> next = cur;
                if(newhead == nullptr)
                    newhead = cur;
                break;
            }
            ListNode *grouphead = cur;
            ListNode *prev = nullptr;
            ListNode *nextnode = nullptr;
            int cnt = 0;
            while(cur != NULL && cnt < k){
                nextnode = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = nextnode;
                cnt++;
            }
            if(tail != nullptr)
                tail -> next = prev;
            if(newhead == nullptr)
                newhead = prev;
            tail = grouphead;
        }
        return newhead;
    }
};
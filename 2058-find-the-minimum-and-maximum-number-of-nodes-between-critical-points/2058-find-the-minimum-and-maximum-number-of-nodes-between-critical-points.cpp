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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
            return {-1 , -1};
        ListNode *temp = head;
        ListNode *prev = nullptr;
        int first = -1 , cur = -1 , mn = 1e9 , mx = -1e9 , i = 0 , last = -1;

        while(temp){
            if(prev != NULL && temp -> next != NULL){
                if(((prev -> val > temp -> val) && (temp -> next -> val > temp -> val)) || ( (prev -> val < temp -> val) && (temp -> next -> val < temp -> val))){
                    if(first != -1){
                        mn = min(mn , abs(i - last));
                        mx = max(mx , abs(i - first));
                    }
                    else{
                        first = i;
                    }
                    last = i;
                }

            }
            i++;
            prev = temp ;
            temp = temp -> next;
        }
        if(mn == 1e9 && mx == -1e9)
            return {-1 , -1};
        return{mn , mx};
    }
};
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
    ListNode* rev(ListNode *prev, ListNode *head){
        if(head==NULL) return prev;
        ListNode *next = head->next;
        head->next = prev;
        return rev(head,next);
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *head2 = rev(NULL,slow);
        ListNode *temp = head;
        while(head2!=NULL){
            ListNode *next = head2->next;
            prev = temp->next;
            head2->next = NULL;
            temp->next = head2;
            temp->next->next = prev;
            if(temp->next->next!=NULL){
                temp = temp->next->next;
            }
            else{
                temp = temp->next;
            }
            head2=next;
        }
    }
};

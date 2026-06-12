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
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode *head = NULL;
        ListNode *temp = NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                if(head==NULL){
                    head = new ListNode(list1->val);
                    temp = head;
                }
                else{
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                }
                list1=list1->next;
            }
            else if(list1->val > list2->val){
                if(head==NULL){
                    head = new ListNode(list2->val);
                    temp = head;
                }
                else{
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }
                list2=list2->next;
            }
            else{
                if(head==NULL){
                    head = new ListNode(list1->val);
                    temp = head;
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }
                else{
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }
                list1=list1->next;
                list2=list2->next;
            }
            if(list1==NULL){
                temp->next = list2;
            }
            if(list2==NULL){
                temp->next = list1;
            }
        }
        return head;
    }
};

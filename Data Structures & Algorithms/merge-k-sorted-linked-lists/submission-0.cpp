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
   ListNode *merge(ListNode *l1, ListNode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *res = NULL;
        ListNode *p = NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                if(res==NULL){
                    res = new ListNode(l1->val);
                    p = res;
                }
                else{
                    p->next = new ListNode(l1->val);
                    p = p->next;
                }
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                if(res==NULL){
                    res = new ListNode(l2->val);
                    p = res;
                }
                else{
                    p->next = new ListNode(l2->val);
                    p = p->next;
                }
                l2 = l2->next;
            }
            else{
                if(res==NULL){
                    res = new ListNode(l1->val);
                    p = res;
                    p->next = new ListNode(l2->val);
                    p = p->next;
                }
                else{
                    p->next = new ListNode(l1->val);
                    p = p->next;
                    p->next = new ListNode(l2->val);
                    p = p->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(l1!=NULL){
            p->next = l1;
        }
        else if(l2!=NULL){
            p->next = l2;
        }
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return divide(lists,0,lists.size()-1);
    }
    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        if(l>r){
            return NULL;
        }
        if(l==r) return lists[l];
        int mid = l + (r-l) /2;
        ListNode *left = divide(lists,l,mid);
        ListNode *right = divide(lists,mid+1,r);
        return merge(left,right);
    }
};

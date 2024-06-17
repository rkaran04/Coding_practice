// https://leetcode.com/problems/reverse-nodes-in-k-group/



(* /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */ *)
class Solution {
public:

    void reverse_ll(ListNode* head, ListNode* tail){
        cout<<"reverse start"<<endl;
        cout<<head->val<<endl;
        if(head==NULL || head->next==NULL || head==tail) return ;

        ListNode* prev=head;
        ListNode* curr=head->next;
        prev->next=NULL;

        while(curr->next){
            ListNode* temp=curr->next;
            curr->next=prev;
            if(curr==tail) break;
            prev=curr;
            curr=temp;
        }
        curr->next=prev;
        cout<<"reverse end"<<endl;
        return;
        

    }



    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* first=head;
        ListNode* last=head;
        ListNode* nxt=head;
        ListNode* ans=head;

        while(1){
            int temp=k-1;
            first=nxt;
            last=nxt;

            while(temp && last->next){
                last=last->next;
                temp--;
            }
           
            if(temp==0 && ans==head && k!=1) ans=last;

            nxt=last->next;
            if(temp>0){
                if(prev!=NULL) prev->next=first;
                break;
            }
            reverse_ll(first,last);
            
            if(prev!=NULL) prev->next=last;
            prev=first;
            if(nxt==NULL) break;
        }
        return ans;
    }
};

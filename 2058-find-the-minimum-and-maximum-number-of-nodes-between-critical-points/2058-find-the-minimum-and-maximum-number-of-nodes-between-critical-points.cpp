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
        if(head->next==nullptr || head->next->next==nullptr ) return {-1,-1}; 
        vector<int> ci;
        ListNode* temp=head->next;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nxt=curr->next;
        int i=1;
        while(temp->next!=nullptr){
            //max dis b/w critical points
            if(nxt!=nullptr){
                if((curr->val> prev->val && curr->val>nxt->val) ||
                (curr->val<prev->val && curr->val<nxt->val)){
                    ci.push_back(i);
                }
                prev=curr;
                ListNode* temp=nxt;
                curr=nxt;
                nxt=temp->next;
            }
            temp=temp->next;
            i++;
        }   

        int mn,mx;
        if(ci.size()<2) return {-1,-1};
        mx=ci[ci.size()-1]-ci[0];
        mn=INT_MAX;
        for(int i=0;i<ci.size()-1;i++){
            mn=min(mn,ci[i+1]-ci[i]);
        }

        return {mn,mx};
    }
};
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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // smaller val = higher priority
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,
                        vector<ListNode*>,
                        Compare> pq;

        for(auto node:lists) {
            if(node!=nullptr) pq.push(node);
        } //push nodes in list

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if(node->next != nullptr)
                pq.push(node->next);
        }

        return dummy->next;
    }
};
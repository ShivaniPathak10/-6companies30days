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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> list;
        for(auto i: lists)
        {
            while(i)
            {
                list.push_back(i-> val);
                i= i->next;
            }
        }
        sort(list.begin(),list.end());
        ListNode* node=new ListNode(0);
        ListNode* head= node;
        for(auto i:list)
        {
            ListNode* newNode =new ListNode(i);
            node->next=newNode;
            node=node->next;
        }
        return head->next;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = head;
        ListNode* rev = head;
        ListNode* node= head;
        while(start!=nullptr){
            if(head->val == val){
                rev = head->next;
                head = rev;
                node = head;
                start=start->next;
            }else if(start->val == val){
                ListNode* nextnode = start->next;
                start = rev;
                rev->next = nextnode;
                start = nextnode;

            }else{
                rev = start;
                start = start->next;
            }
        }
        // if(head==nullptr){
        //     node=nullptr;
        // }
        return node;
    }
};

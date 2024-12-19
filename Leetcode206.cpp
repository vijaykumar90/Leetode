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
    ListNode* reverseList(ListNode* head) {
        ListNode* mainLL = head;
        ListNode* rev = nullptr;
        while (mainLL != nullptr){
            ListNode* nextnode = mainLL->next;
            mainLL->next = rev;
            rev = mainLL;
            mainLL = nextnode;            
        }

        return rev;

    }
};

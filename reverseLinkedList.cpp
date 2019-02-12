// https://leetcode.com/problems/reverse-linked-list/
// Jan 21, 2019
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    stack<ListNode*> nodeStack;
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL){
            ListNode* lastNode = head;
            while(this->nodeStack.size() > 1){
                lastNode->next = this->nodeStack.top();
                lastNode = this->nodeStack.top();
                this->nodeStack.pop();
            }
            if(nodeStack.size() == 1){
                lastNode->next = this->nodeStack.top();
                this->nodeStack.top()->next = NULL;
                this->nodeStack.pop();
            }
            return head;
        }
        this->nodeStack.push(head);
        return reverseList(head->next);
    }
};
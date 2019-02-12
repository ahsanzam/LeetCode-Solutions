/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //basically as we go down the list, we store an array of nodes and at every k call, we reverse this array and attach it to the beginning of the returned element of the next recursive call  
    ListNode* recurse(ListNode* currNode, vector<ListNode*>* nodeArr, int reverseSize, int currNum){
        if(currNum == reverseSize){ //reverse currNum+1 nodes if we're at k or if we're at end of list
            for(int i=0; i<currNum; i++) //reverse 
                (*nodeArr)[i]->next = (*nodeArr)[(i-1)%(currNum)];
            ListNode* newLast = (*nodeArr)[0]; //store pointer to new last node 
            ListNode* newFirst = (*nodeArr)[currNum-1]; //store pointer to new first node 
            //reverse remaining nodes in list if there are any nodes remaining
            ListNode* nextNode = currNode ? recurse(currNode, nodeArr, reverseSize, 0) : currNode; 
            //attach the remaining nodes to the last node from this function call's reversal 
            newLast->next = nextNode;
            return newFirst; //return the first node from this function call's reversal
        }
        else if(!currNode){ //don't reverse the leftover numbers if we're at the last node but not at currNum == reverseSize
            return (*nodeArr)[0];
        }
        else{ //we're not at k nor at end of list so keep going
            (*nodeArr)[currNum] = currNode; //add currNode to arr
            return recurse(currNode->next, nodeArr, reverseSize, currNum+1);            
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodeArr;
        for(int i=0; i<k;  i++)
            nodeArr.push_back(head);
        ListNode* toReturn = recurse(head, &nodeArr, k, 0);
        return toReturn;
    }
    
};
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        if(temp == nullptr) return temp;
        while(temp->next != nullptr){
            int val1 = temp->val;
            int val2 = temp->next->val;
            
                while( val1 && val2){
                    int maxx = max(val1,val2);
                    int minn = min(val1,val2);
                    val1 = maxx%minn;
                    val2 = minn;
                }
                
            ListNode* btw = new ListNode( abs(val1-val2), temp->next);
            temp->next = btw;
            temp = temp->next->next;

        }
        return head;
        
    }
};
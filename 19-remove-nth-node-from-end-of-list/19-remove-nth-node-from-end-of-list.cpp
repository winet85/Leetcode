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
    void addNode(ListNode* head, ListNode* node){
        ListNode *it = head;
        
        while(it->next != nullptr){
            it = it->next;
        }
        
        it->next = new ListNode(node->val, node->next);
        
        return ;
    }
    void removeNode(ListNode* head, ListNode* node){
        ListNode *it = head, *pre = head;
        
        while(it != nullptr && it != node){
            pre = it;
            it = it->next;
        }
        
        if(it == head){
            head = it->next;
        }else{
            pre->next = node->next;    
        }
        
        // free(node);
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *rit = head, *lit = head, *pre_lit = head, *it = nullptr;
        int ri = 1, li = 1;
        ListNode *ret = head;
        while(rit != nullptr){
            
            if(ri - li >= n){
                pre_lit = lit;
                lit = lit -> next;
                ++li;
            }
            
            rit = rit->next;
            ++ri;
        }
        
        // cout << lit->val << endl;
        if(pre_lit == lit){
            ret = pre_lit->next;
        }else{
            pre_lit->next = lit->next;
        }
        delete lit;
        // cout << pre_lit->val << ", " << lit->val << endl;
        return ret;
    }
};
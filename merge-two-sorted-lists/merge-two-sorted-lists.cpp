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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *it1 = list1, *it2 = list2;
        ListNode *ret = new ListNode(), *ret_it = ret;
        
        while(it1 != nullptr || it2 != nullptr){
            
            if(it1 != nullptr && it2 != nullptr){
                if(it1->val < it2->val){
                    ret_it->next = new ListNode(it1->val);
                    ret_it = ret_it->next;
                    it1 = it1->next;
                }else{
                    ret_it->next = new ListNode(it2->val);
                    ret_it = ret_it->next;
                    it2 = it2->next;
                }
            }else if(it1 == nullptr && it2 != nullptr){
                ret_it->next = new ListNode(it2->val);
                ret_it = ret_it->next;
                
                it2 = it2->next;
            }else if(it1 != nullptr && it2 == nullptr){
                ret_it->next = new ListNode(it1->val);
                ret_it = ret_it->next;
                it1 = it1->next;
            }else{
                break;
            }
            
        }
        
//         ret_it = ret;
//         while(ret_it != nullptr){
//             cout << ret_it->val << ",";
//             ret_it = ret_it->next;
//         }
        
//         cout << endl;
        return ret->next;
    }
};
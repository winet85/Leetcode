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
double pow(int x, int n){
    double ret;
    
    if(n == 0) return 1;
    
    for(int i = 0; i < n; ++i){
        ret *= x;
    }
    
    return ret;
}

void print_nodes(ListNode *node){
    
    ListNode *it = node;
    cout<< "print_nodes : " << it->next << endl;
    while(it != nullptr ){          
        cout << it->val << " ";
        it = it->next;
    }
    
    cout << endl;
}

void add_node(ListNode *node, int x){
    
    ListNode *it = node;
    
    while(it->next != nullptr ){          
        it = it->next;
        // cout << it <<  endl;
    }
    it->next = new ListNode(x);
    // cout<< "add data(" << it << ") : " << it->val << endl;
    
    // print_nodes(node);

}


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int val1 = 0, val2 = 0;
        
//         ListNode *ret = new ListNode();
//         ListNode *node1 = l1;
//         ListNode *node2 = l2;
        
//         int cnt = 0;
//         bool flip = false;
//         while(node1 != nullptr || node2  != nullptr || flip== true){
//             int sum = 0;
//             if(node1 != nullptr && node2 != nullptr){
//                 sum = node1->val + node2 -> val;
//                 node1 = node1->next;
//                 node2 = node2->next;
//             }else if(node1 != nullptr){
//                 sum = node1->val;
//                 node1 = node1->next;
//                 node2 = nullptr;
//             }else if(node2 != nullptr){
//                 sum = node2->val;
//                 node2 = node2->next;
//                 node1 = nullptr;
//             }else{
//                 node2 = nullptr;
//                 node1 = nullptr;
//             }
            
//             if(flip){
//                 sum += 1;
//             }
            
//             if(sum >= 10){
//                 flip = true;
//                 sum -=10;
//             }else{
//                 flip = false;
//             }
            
//             add_node(ret, sum);
//         }
       
//         print_nodes(ret);
//         // while()
//         return ret->next;
//     }

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *n1 = l1, *n2 = l2;
        ListNode *ret = new ListNode();
        ListNode *cur = ret, *pre = ret;
        while(n1 != nullptr || n2 != nullptr){
            int a = 0, b = 0;
            int sum = 0;
            int next_flip = 0;
            if(n1 != nullptr){
                a = n1->val; 
                n1 = n1->next;
            }
            
            if(n2 != nullptr){
                b = n2->val;
                n2 = n2->next;
            }
            
            if(cur == nullptr){
                cur = new ListNode();
                pre -> next = cur;
            }
            
            sum = a + b + cur->val;
            next_flip = sum/10 > 0 ? 1 : 0;
            sum = sum % 10;
            
            if(next_flip == 1){
                cur->next = new ListNode(1);
            }
                
            cur->val = sum;             
            pre = cur;
            cur = cur->next;
            
            
           
        }
        
        return ret;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <map>
class Solution {
public:
    Node* findNode(Node* ori, Node* cp, Node* n){
        Node *it = ori, *ret = cp;
    
        while(it != nullptr && it != n){
            it = it->next;
            ret = ret->next;
        }
        
        return ret;
    }
//     Node* copyRandomList(Node* head) {
//         Node *it = head;
//         Node *ret = new Node(-1);
//         Node *r_it = ret;
        
//         while(it != nullptr){
//             r_it->next = new Node(it->val);
            
//             it = it ->next;
//             r_it = r_it->next;
//         }
        
//         it = head;
//         r_it = ret->next;
        
//         while(it != nullptr){
//             Node *r = it->random;
            
//             if(r != nullptr){
//                 r_it->random = findNode(head, ret->next, r);
//             }
//             it = it ->next;
//             r_it = r_it->next;
//         }
            
        
//         return ret->next;
//     }
     Node* copyRandomList(Node* head) {
        Node *it = head;
        Node *ret = new Node(-1);
        Node *r_it = ret;
        map<Node*,Node*> table;
        
        
        while(it != nullptr){
            r_it->next = new Node(it->val);
            table.insert(pair<Node*, Node*>(it, r_it->next));
            it = it ->next;
            r_it = r_it->next;
        }
        
        it = head;
        r_it = ret->next;
        
        while(it != nullptr){
            Node *r = it->random;
            
            if(r != nullptr){
                map<Node *, Node *>::iterator i = table.find(r);
                r_it->random = i->second;
            }
            it = it ->next;
            r_it = r_it->next;
        }
            
        
        return ret->next;
    }
};
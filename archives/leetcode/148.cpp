#include <bits/stdc++.h>
using namespace std;

// 148. Sort List
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* NewHead = new ListNode();
        ListNode* head = NewHead;
        while(left && right) {
            if(left->val < right->val) {
                head->next = left;
                left = left->next;
            }
            else {
                head->next = right;
                right = right->next;
            }
            head = head->next;
        }
        if(left) head->next = left;
        else head->next = right;
        
        return NewHead->next;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};
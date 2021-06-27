#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 92. Reverse Linked List II
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;

        ListNode* init = head;
        for(int i=1; i<left-1; i++) head = head->next;
        ListNode* start = head;
        head = head->next;
        ListNode* curr = head;

        if(left == 1) {
            head = init;
            curr = head;
        }

        for(int i=1; i<=right-left+1; i++) head = head->next;
        ListNode* end = head;
        ListNode* prev = end;

        while(curr != end) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if(left == 1) return prev;
        start->next = prev;
        return init;
    }
};

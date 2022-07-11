#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *d = NULL;
        while(head != NULL)
        {
            ListNode *hp = head->next;
            head->next = d;
            d = head;
            head = hp;
        }
        return d;
    }
};

int main(){
    
    return 0;
}
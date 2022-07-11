#include<iostream>
using namespace std;

// T-> O(n/k*k) => n/k groups and for each group k iterations => O(n)
// S-> O(1)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = dummy, *nex = dummy;
        int count = 0;
        while(cur->next != NULL)
        {
            cur = cur->next;
            count++;
        }
        while(count>=k)
        {
            cur = prev->next;
            nex = cur->next;
            for(int i = 1; i<k; i++)
            {
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            count -= k;
        }
        return dummy->next;
    }
};

int main(){
    
    return 0;
}
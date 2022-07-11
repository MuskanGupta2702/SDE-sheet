#include<iostream>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Stiver method
// TC -> O(N)
// SC ->O(1)

// we take 3 pointers slow and fast to see if there exists a cycle and the point they collide.
// the distance from the point they collide and head is same 

// L1 = nC -L2 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head, *entry = head; 
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
            {
                while(entry != slow)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

// Here i used hashset 
// TC -> O(N)
// SC ->O(N)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        unordered_set <ListNode*> mpp;
        while(head != NULL)
        {
            if(mpp.find(head) != mpp.end()) return head;
            mpp.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

int main(){
    
    return 0;
}
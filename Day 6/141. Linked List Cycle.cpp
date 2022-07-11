#include<iostream>
#include<unordered_set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// My method 
// T -> O(N)
// S -> O(N)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        unordered_set<ListNode *> mpp;
        while(head != NULL)
        {
            if(mpp.find(head) != mpp.end()) return true;
            mpp.insert(head);
            head = head->next;
        }
        return false;
    }
};


// slow and fast pointer method
// T -> O(N)
// S -> O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *s = head, *f = head;
        while(f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;
            if(s == f) return true;
        }
        return false;
    }
};

int main(){
    
    return 0;
}
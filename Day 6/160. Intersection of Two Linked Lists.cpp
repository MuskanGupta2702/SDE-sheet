#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *d1 = headA, *d2 = headB;
        while(d1 != d2)
        {
            d1 = d1->next;
            d2 = d2->next;
            if(d1 == NULL && d2 !=NULL)
            {
                d1 = headB;
            }
            if(d2 == NULL && d1 !=NULL)
            {
                d2 = headA;
            }
        }
        return d1;
        
    }
};

int main(){
    
    return 0;
}
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

// My method

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL, *l4, *pNew;
        int d = 0, a = 0;
        while(l1 != NULL && l2 != NULL)
        {
            pNew = new ListNode;
            pNew->val = l1->val + l2->val + d;
            d = 0;
            if(pNew->val >= 10)
            {
               d = pNew->val /10; 
               pNew->val %= 10;
            }
            pNew->next = NULL;
            if(l3 == NULL)
            {
                l3 = pNew;
                l4 = pNew;
            }
            else
            {
                l4->next = pNew;
                l4 =  l4->next;
            }
            l1 = l1->next;
            l2 = l2->next;
            
        }
        while(l1 != NULL)
        {
            pNew = new ListNode;
            pNew->val = l1->val + d; d = 0;
            if(pNew->val >= 10)
            {
               d = pNew->val /10; 
               pNew->val %= 10;
            }
            pNew->next = NULL;
            l4->next = pNew;
            l4 =  l4->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            pNew = new ListNode;
            pNew->val = l2->val + d; d = 0;
            if(pNew->val >= 10)
            {
               d = pNew->val /10; 
               pNew->val %= 10;
            }
            pNew->next = NULL;
            l4->next = pNew;
            l4 =  l4->next;
            l2 = l2->next;
        }
        if(d ==1)
        {
            pNew = new ListNode;
            pNew->val = d;
            pNew->next = NULL;
            l4->next = pNew;
        }
        return l3;
    }
};

// Striver method

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * d = new ListNode(); //To create dummy node
        ListNode *temp = d;
        int c = 0;
        while(l1 != NULL || l2 != NULL || c)
        {
            int  sum = 0;
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += c;
            c = sum / 10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return d->next;
    }
};
int main(){
    
    return 0;
}
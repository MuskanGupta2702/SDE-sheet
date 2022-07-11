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

// **My method**
// T -> O(n + n) = O(n)
// S -> O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *hp = head;
        int count = 1;
        while(hp->next != NULL)
        {
            hp = hp->next;
            count++;
        }
        int d = count - n;
        hp = head;
        if(d == 0)
        {
            head = hp->next;
            delete hp;
            return head;
        }
        while(d>1)
        {
            hp = hp->next;
            d--;
        }
        ListNode *n2d = hp->next;
        hp->next = n2d->next;
        delete n2d;
        return head;
    }
};

// **My method**
// T -> O(n) 
// S -> O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode; //Creating dummy node
        start->next = head;
        ListNode *slow = start;
        ListNode *fast = start;
        for(int i =1; i<=n; i++)
        {
            fast = fast->next;
        }
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};

int main(){
    
    return 0;
}
#include<iostream>
using namespace std;

// **My method**
// T -> O(n) + O(n/2)
// S -> O(1)

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
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode *hp = head;
        int count = 1;
        while(hp->next != NULL)
        {
            hp = hp->next;
            count++;
            // cout<<"Count = "<<count<<endl;
        }
        // cout<<"Final Count = "<<count<<endl;
        int Hcount = 1;
        while(Hcount != (count/2)+1)
        {
            head = head->next;
            Hcount++;
        }
        return head;
    }
};



// **Tortoise method**
// Logic: slow pointer moves by 1 and fast pt by 2 and when fast reaches last node(odd no. of list) or points to null (even no. of list) slow reaches mid of list and  we return slow 
// T -> O(n/2)
// S -> O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head; 
        while(fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    
    return 0;
}
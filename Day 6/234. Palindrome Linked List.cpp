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
    bool isPalindrome(ListNode* head) {
        ListNode *hp = head;
        int count = 1;
        stack<int> st;
        while(hp != NULL)
        {
            st.push(hp->val);
            hp = hp->next;
            count++;
        }
        for(int i = 1; i<=count/2; i++)
        {
            if(head->val != st.top())
                return false;
            head = head->next;
            st.pop();
        }
        return true;  
    }
};

int main(){
    
    return 0;
}
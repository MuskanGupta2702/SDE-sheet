#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Dumm solution
//  Suppose 4->5->6->7   delete = 5
//  Ans 4->6->7
// Solution replace node with 5 with value of next node and change next of 5 with node->next->next

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(){
    
    return 0;
}
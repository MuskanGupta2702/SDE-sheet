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
// T -> O(n1 + n2)
// S -> O(n1 + n2)



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *hp1 = list1, *hp2 = list2; 
        ListNode *hp3 = NULL , *hp4 = NULL;
        
        while(hp1 != NULL && hp2 != NULL)
        {
            ListNode *pNew = (ListNode*)malloc(sizeof(ListNode));
            if(hp1->val <= hp2->val)
            {
                pNew->val = hp1->val;
                pNew->next = NULL;
                if(hp3 == NULL)
                {
                    hp3 = pNew;
                    hp4 = pNew;
                }
                else{
                    hp4->next = pNew;
                    hp4 = pNew;
                }
                hp1 = hp1->next;
                
            }
            else
            {
                pNew->val = hp2->val;
                pNew->next = NULL;
                if(hp3 == NULL)
                {
                    hp3 = pNew;
                    hp4 = pNew;
                }
                else{
                    hp4->next = pNew;
                    hp4 = pNew;
                }
                hp2 = hp2->next;
            }
        }
        
        while(hp1 != NULL)
        {
            ListNode *pNew = (ListNode*)malloc(sizeof(ListNode));
            pNew->val = hp1->val;
            pNew->next = NULL;
            hp4->next = pNew;
            hp4 = pNew;
            hp1 = hp1->next;
        }
        while(hp2 != NULL)
        {
            ListNode *pNew = (ListNode*)malloc(sizeof(ListNode));
            pNew->val = hp2->val;
            pNew->next = NULL;
            hp4->next = pNew;
            hp4 = pNew;
            hp2 = hp2->next;
        } 
        return hp3;
    }
};

// **In place method**
// T -> O(n1 + n2)
// S -> O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1,list2);
        ListNode *res = list1;
        while(list1 != NULL && list2 != NULL)
        {
            ListNode *temp = NULL;
            while(list1 != NULL && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1,list2);
        }
        return res;
    }
};

int main(){
    
    return 0;
}
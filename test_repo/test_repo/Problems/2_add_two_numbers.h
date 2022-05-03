#include <iostream>

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

     void addNode(int a_Val)
     {
         ListNode* tmp = new ListNode(0);
         tmp->val = a_Val;
         tmp->next = nullptr;

         if (next)
         {

         }
         else
         {
             next = tmp;
         }
     }

     void printList()
     {

     }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

void testAddTwoNumbers();
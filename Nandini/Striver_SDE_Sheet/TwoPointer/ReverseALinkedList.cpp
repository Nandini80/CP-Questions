#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
       ListNode* slow = head;
       ListNode* fast  = head;
       ListNode* before= NULL;
       ListNode* after = NULL;
       while(fast && fast->next)
       {
         fast = fast->next->next;

         after = slow->next;
         slow->next = before;
         before = slow;
         slow = after;
       }     

       if(fast && !fast->next) slow = slow->next;

       while(slow)
       {
         if(slow->val != before->val) return false;
         slow = slow->next;
         before = before->next;  
       } 
       return true;  
    }
};
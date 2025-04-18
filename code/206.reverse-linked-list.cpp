// Category: algorithms
// Level: Easy
// Percent: 78.57006%

// Given the head of a singly linked list, reverse the list, and return the
// reversed list.
//
//  
// Example 1:
//
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
//
//
// Example 2:
//
// Input: head = [1,2]
// Output: [2,1]
//
//
// Example 3:
//
// Input: head = []
// Output: []
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the list is the range [0, 5000].
// 	-5000 <= Node.val <= 5000
//
//
//  
// Follow up: A linked list can be reversed either iteratively or recursively.
// Could you implement both?

using namespace std;

// Definition for singly-linked list.
/*struct ListNode {*/
/*  int val;*/
/*  ListNode *next;*/
/*  ListNode() : val(0), next(nullptr) {}*/
/*  ListNode(int x) : val(x), next(nullptr) {}*/
/*  ListNode(int x, ListNode *next) : val(x), next(next) {}*/
/*};*/

class Solution {
public:
  // iterative
  ListNode *reverseList(ListNode *head) {
    /*ListNode *curr = head;*/
    /*ListNode *temp = head;*/
    /*ListNode *prev = nullptr;*/
    /*while (curr) {*/
    /*  temp = curr->next;*/
    /*  curr->next = prev;*/
    /*  prev = curr;*/
    /*  curr = temp;*/
    /*}*/
    /*return prev;*/
    if (head == nullptr)
      return head;
    return reverseListRec(head, nullptr);
  }

  ListNode *reverseListRec(ListNode *curr, ListNode *prev) {
    if (curr->next == nullptr) {
      curr->next = prev;
      return curr;
    }
    ListNode *next = curr->next;
    curr->next = prev;
    return reverseListRec(next, curr);
  }
};

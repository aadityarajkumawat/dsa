#ifndef ListNode_H
#define ListNode_H

class ListNode {
   public:
    int val;
    ListNode* next;

    ListNode();
    ListNode(int val);
    ListNode(int val, ListNode* next);

    void traversal();
};

#endif

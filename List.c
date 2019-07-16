/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    assert(head);
    
    if(head->next==NULL)
        return head;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    

}

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    
        if(pListHead==NULL)
            return NULL;
        
        struct ListNode* slow = pListHead;
        struct ListNode* fast = pListHead;
        while(--k && fast!=NULL)
            fast = fast->next;
        if(fast==NULL)
            return NULL;
        
        while(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
        
        
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    
    struct ListNode* head,*tail;
    
    if(l1->val<l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    tail = head;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val<l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1!=NULL)
        tail->next = l1;
    if(l2!=NULL)
        tail->next = l2;
    
    return head;

}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead==NULL)
            return NULL;
        struct ListNode *lessHead,*greaterHead,*lesstail,*greatertail;
        lesstail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        greatertail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur = pHead;
        
        while(cur)
        {
            if(cur->val<x)
            {
                lesstail->next = cur;
                lesstail = lesstail->next;
            }
            else
            {
                greatertail->next = cur;
                greatertail = greatertail->next;
            }
            cur = cur->next;
        }
        
        lesstail->next = greaterHead->next;
        greatertail->next = NULL;
        pHead = lessHead->next;
        
        
        return pHead;
        
    }
};
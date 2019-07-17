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

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        if(pHead->next==NULL)
            return pHead;
        
        struct ListNode* n0,*n1,*n2;
        
        n0 = NULL;
        n1 = pHead;
        n2 = n1->next;
        
        while(n2!=NULL)
        {
            if(n1->val != n2->val)
            {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
            else
            {
                while(n2 && n2->val==n1->val)
                    n2 = n2->next;
                
                if(n0)//这是防止特殊情况 111112，避免输出错误
                    n0->next = n2;
                else
                    pHead = n2;
                
                n1 = n2;
                if(n2)
                    n2 = n2->next;
            }
            
        }
        
        
        return pHead;
        
    }
};
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    struct ListNode* reverseList(struct ListNode* head)
    {
        struct ListNode* newhead = NULL;
        struct ListNode* cur = head;
        while(cur)
        {
            struct ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
    bool chkPalindrome(ListNode* A) {
        int i = 0;
        
        struct ListNode* cur = A;
        while(cur)
        {
            cur = cur->next;
            ++i;
        }
        cur = A;
        int mid = i/2;
        
        while(mid--)
        {
            cur = cur->next;
        }
        struct ListNode* head1 = A;
        struct ListNode* head2 = reverseList(cur);
        mid = i/2;//此处因为之前的运算mid已经为0，如果不重新赋值进入循环，会出现错误
        while(mid--)
        {
            if(head1->val==head2->val)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
                return false;
        }
        return true;
        
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL&&headB==NULL)
        return NULL;
    
    struct ListNode * curA = headA;
    struct ListNode * curB = headB;
    
    int A = 0,B = 0;
    
    while(curA)
    {
        curA = curA->next;
        ++A;
    }
    while(curB)
    {
        curB = curB->next;
        ++B;
    }
    if(A>B)
    {
        int i = A-B;
        while(i--)
            headA = headA->next;
    }
    else if(B>A)
    {
        int i = B-A;
        while(i--)
            headB = headB->next;
    }
    while(headA&&headB)
    {
        if(headA==headB)
            return headA;
        else
        {
            headA = headA->next;
            headB = headB->next;
        }
        
    }
    return NULL;
    
    
    
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
        ListNode* front,*back;
        ListNode* frontHead,*backHead;
        front = frontHead =  (struct ListNode*)malloc(sizeof(struct ListNode));
        back = backHead =  (struct ListNode*)malloc(sizeof(struct ListNode));
        
        struct ListNode* cur = pHead;
        while(cur)
        {
            if(cur->val<x)
            {
                front->next = cur;
                front = front->next;
            }
            else
            {
                back->next = cur;
                back = back->next;
            }
            cur = cur->next;
        }
        front->next = backHead->next;
        back->next = NULL;
        pHead = frontHead->next;
        
        return pHead;
        
        
    }
};
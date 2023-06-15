#include<bits/stdc++.h>
using namespace std;

/*
<aside>
💡 **Question 1**

Given two linked list of the same size, the task is to create a new linked list using those linked lists. The condition is that the greater node among both linked list will be added to the new linked list.

</aside>
*/

struct Node {
    int data;
    Node* next;
};

Node* newList(Node* head1, Node* head2)
{
    Node *temp1 = head1, *temp2 = head2, *ptr;
    Node *root = NULL, *temp;
 
    while (temp1 != NULL) {
        temp = new Node;
        temp->next = NULL;
 
        if (temp1->data < temp2->data)
            temp->data = temp2->data;
        else
            temp->data = temp1->data;
 
        if (root == NULL)
            root = temp;
        else {
            ptr = root;
            while (ptr->next != NULL)
                ptr = ptr->next;
 
            ptr->next = temp;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return root;
}



/*
<aside>
💡 **Question 2**

Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once.

For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60.

</aside>
*/

 
  struct ListNode {
      int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* prev;
        ListNode* curr;
        prev=head;
        curr=head->next; 
        while(curr!=NULL){
            if(prev->val==curr->val)
            {
                prev->next=curr->next;
            }
            else{
                prev=curr; 
            }
            curr=curr->next;  
        }
        
        return head;
    }

/*
<aside>
💡 **Question 3**

Given a linked list of size **N**. The task is to reverse every **k** nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of *k* then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

</aside>
*/

ListNode* reverseKGroup(ListNode* head, int k) {
           ListNode * dummy = new ListNode(0);
           dummy->next = head;
        
           ListNode* curr = dummy , *nex = dummy , *pre = dummy;
           int cnt = 0;
           while(curr->next) {
               curr = curr->next;
               cnt++;
           }
            
           while(cnt >= k) {
               curr = pre->next;
               nex = curr->next;
               for(int i=1;i<k;i++) {
                   curr->next = nex->next;
                   nex->next = pre->next;
                   pre->next = nex;
                   nex = curr->next;
               }  
               pre = curr;
               cnt-=k;
           }
        return dummy->next;
}

/*
<aside>
💡 **Question 4**

Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the function) in an efficient way. Give the complexity of your algorithm.

</aside>
*/
Node *kAltReverse(Node *head, int k)
{
    Node* current = head;
    Node* next;
    Node* prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
    }
    if(head != NULL)
    head->next = current;
    count = 0;
    while(count < k-1 && current != NULL )
    {
    current = current->next;
    count++;
    }
 
    if(current != NULL)
    current->next = kAltReverse(current->next, k);
    return prev;
}


/*
<aside>
💡 **Question 5**

Given a linked list and a key to be deleted. Delete last occurrence of key from linked. The list may have duplicates.

</aside>
*/

void deleteLast(struct Node* head, int x)
{
    struct Node *temp = head, *ptr = NULL;
    while (temp) {
        if (temp->data == x) 
            ptr = temp;        
        temp = temp->next;
    }
    if (ptr != NULL && ptr->next == NULL) {
        temp = head;
        while (temp->next != ptr) 
            temp = temp->next;       
        temp->next = NULL;
    }
    if (ptr != NULL && ptr->next != NULL) {
        ptr->data = ptr->next->data;
        temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }
}


/*
<aside>
💡 **Question 6**

Given two sorted linked lists consisting of **N** and **M** nodes respectively. The task is to merge both of the lists (in place) and return the head of the merged list.

**Examples:**

Input: a: 5->10->15, b: 2->3->20

Output: 2->3->5->10->15->20

Input: a: 1->1, b: 2->4

Output: 1->1->2->4

</aside>
*/

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 
/*
<aside>
💡 **Question 7**

Given a **Doubly Linked List**, the task is to reverse the given Doubly Linked List.

</aside>
*/
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void reverse(Node** head_ref) {
    Node* current = *head_ref;
    Node* temp = NULL;
 
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

/*
<aside>
💡 **Question 8**

Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

</aside>
*/
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
 
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    if (*head_ref == NULL || n <= 0)
        return;
    struct Node* current = *head_ref;
    int i;
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
    if (current == NULL)
        return;
    deleteNode(head_ref, current);
}


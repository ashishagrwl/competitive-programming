#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

struct listNode {
    int data;
    listNode *next;
};


// get-the-value-of-the-node-at-a-specific-position-from-the-tail

int GetlistNode(listNode *head,int positionFromTail) {
    listNode *target = head;
    listNode *last = target;
    while (positionFromTail--) {
        last = last->next;
    }
    while (last->next) {
        target = target->next;
        last = last->next;
    }
    return target->data;
}

// delete-duplicate-value-nodes-from-a-sorted-linked-list

listNode* RemoveDuplicates(listNode *head) {
    if (NULL == head)
        return head;
    listNode* unique = head;
    while (unique) {
        while (unique->next && unique->data == unique->next->data) {
            unique->next = unique->next->next;
        }
        unique = unique->next;
    }
    return head;
}

// compare-two-linked-lists

int CompareLists(listNode *headA, listNode* headB) {
    while (headA && headB) {
        if (headA->data != headB->data)
            break;
        headA = headA->next;
        headB = headB->next;
    }
    if (!headA && !headB) {
        return 1;
    }
    else {
        return 0;
    }
}

// Insert at head

// listNode* Insert(listNode *head,int data) {
//   listNode* temp = new listNode;
//   temp->data = data;
//   temp->next = head;
//   return temp;
// }

// Insert at tail

listNode* Insert(listNode *head,int data) {
    listNode *iter = head;
    listNode *temp = new listNode;
    temp->data = data;
    temp->next = NULL;
    if (!head)
        return temp;
    while (iter->next)
        iter = iter->next;
    iter->next = temp;
    return head;
}

// find-the-merge-point-of-two-joined-linked-lists

int FindMergelistNode(listNode *headA, listNode *headB) {
    int countA = 0, countB = 0, diff = 0;
    listNode *temp = headA;
    while (temp) {
        countA++;
        temp = temp->next;
    }
    temp = headB;
    while (temp) {
        countB++;
        temp = temp->next;
    }
    diff = (countA>countB)?(countA-countB):(countB-countA);
    temp = (countA>countB)?headA:headB;
    listNode* temp2 = (countA>countB)?headB:headA;
    while (diff--) {
        temp = temp->next;
    }
    while (temp && temp2) {
        if (temp->data == temp2->data)
            return temp->data;
        temp = temp->next;
        temp2 = temp2->next;
    }
    return 0;
}

// detect-whether-a-linked-list-contains-a-cycle

int HasCycle(listNode* head) {
    listNode* slow = head;
    listNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

// print-the-elements-of-a-linked-list-in-reverse

void ReversePrint(listNode *head) {
    if (!head)
        return;
    ReversePrint(head->next);
    cout << head->data << endl; 
}

// reverse-a-linked-list
//  recursive
listNode* reverseList (listNode* curr, listNode* prev=NULL) {
    if (!curr->next) {
        curr->next = prev;
        return curr;
    }
    listNode* _next = curr->next;
    curr->next = prev;
    return reverseList (_next, curr);
}
void doReverseList (listNode** head) {
    if (!head)
        return;
    *head = reverseList(*head);
}

//  iterative
listNode* Reverse(listNode* head) {
    if (!head)
        return NULL;
    listNode* curr = head, *prev = NULL;
    while (curr->next) {
        listNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    return curr;
}

listNode* Delete(listNode *head, int position) {
    listNode *temp = head;
    if (0 == position) {
        delete head;
        return temp->next;
    }
    position--;
    while (position--) {
        temp = temp->next;
    }
    listNode *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
    return head;
}


void Print(listNode *head) {
    bool ok = false;
    while(head != NULL)
    {
        if(ok)cout<<" ";
        else ok = true;
        cout<<head->data;
        head = head->next;
    }
}

listNode* Push(listNode *head,int x) {
   listNode *temp = new listNode();
   temp->data = x;
   temp->next = NULL;
   if(head == NULL) {
       return temp;
   }
   listNode *temp1;
   for(temp1 = head;temp1->next!=NULL;temp1= temp1->next);
   temp1->next = temp;return head;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        listNode *head = NULL;
        while(true) {
            int x;
            cin>>x;
            if (-1 == x)
                break;
            head = Push(head,x);
        }
        // int n;cin>>n;
        // cout<<GetlistNode(A,n)<<"\n";
        //RemoveDuplicates(A);
        Print(head);
        head = Reverse(head);
        Print(head);
    }
}
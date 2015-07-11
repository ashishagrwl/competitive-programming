#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

struct listNode {
    int data;
    listNode *next;
};

struct dListNode {
    int data;
    dListNode *next;
    dListNode *prev;
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
    cout << '\n';
}

void Print (dListNode *head) {
    bool ok = false;
    while(head != NULL)
    {
        if(ok)cout<<" ";
        else ok = true;
        cout<<head->data;
        head = head->next;
    }
    cout << '\n';
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

// insert-a-node-at-a-specific-position-in-a-linked-list
listNode* InsertNth(listNode *head, int data, int position) {
    listNode* _new = new listNode();
    listNode* temp = head;
    _new->data = data;
    _new->next = NULL;
    if (!head || !position) {
        _new->next = head;
        return _new;
    }
    for (int i = 0; i < (position-1); ++i) {
        temp = temp->next;
    }
    _new->next = temp->next;
    temp->next = _new;
    return head;
}

listNode* MergeLists(listNode *headA, listNode* headB) {
    if (!headA)
        return headB;
    if (!headB)
        return headA;
    listNode* headNew = NULL, *iterA = headA, *iterB = headB, *iterNew = NULL;
    if (iterA->data < iterB->data) {
        headNew = iterA;
        iterA = iterA->next;
    } else {
        headNew = iterB;
        iterB = iterB->next;
    }
    iterNew = headNew;
    while (iterA && iterB) {
        if (iterA->data < iterB->data) {
            iterNew->next = iterA;
            iterNew = iterNew->next;
            iterA = iterA->next;
        } else {
            iterNew->next = iterB;
            iterNew = iterNew->next;
            iterB = iterB->next;
        }
    }
    if (iterA)
        iterNew->next = iterA;
    else if (iterB)
        iterNew->next = iterB;
    return headNew;
}

// insert-a-node-into-a-sorted-doubly-linked-list
dListNode* SortedInsert(dListNode *head, int data) {
    dListNode* temp = new dListNode;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!head)
        return temp;
    if (data < head->data) {
        temp->next = head;
        head->prev = temp;
        return temp;
    }
    dListNode* marker = head;
    while (marker->next && (marker->next->data < data))
        marker = marker->next;
    temp->prev = marker;
    temp->next = marker->next;
    if (marker->next)
        marker->next->prev = temp;
    marker->next = temp;
    return head;
}

// reverse-a-doubly-linked-list
dListNode* Reverse(dListNode* head) {
    if (!head)
        return NULL;
    dListNode* temp = head, *temp2=NULL;
    while (true) {
        temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        if (!temp->prev)
            break;
        temp = temp->prev;
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    // listNode *headA = NULL;
    // while(true) {
    //     int x;
    //     cin>>x;
    //     if (-1 == x)
    //         break;
    //     headA = Push(headA,x);
    // }
    dListNode *headA = NULL, *tail = NULL;
    while (true) {
        int x=0;
        cin >> x;
        if (-1 == x)
            break;
        dListNode *temp = new dListNode;
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;
        if (!headA) {
            headA = tail = temp;
            continue;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
    }
    Print(headA);
    headA = Reverse(headA);
    Print(headA);
    cout << flush;
    return 0;
}
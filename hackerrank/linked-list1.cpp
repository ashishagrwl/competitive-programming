#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *next;
};


// get-the-value-of-the-node-at-a-specific-position-from-the-tail

int GetNode(Node *head,int positionFromTail) {
    Node *target = head;
    Node *last = target;
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

Node* RemoveDuplicates(Node *head) {
    if (NULL == head)
        return head;
    Node* unique = head;
    while (unique) {
        while (unique->next && unique->data == unique->next->data) {
            unique->next = unique->next->next;
        }
        unique = unique->next;
    }
    return head;
}

// compare-two-linked-lists

int CompareLists(Node *headA, Node* headB) {
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

// Node* Insert(Node *head,int data) {
//   Node* temp = new Node;
//   temp->data = data;
//   temp->next = head;
//   return temp;
// }

// Insert at tail

Node* Insert(Node *head,int data) {
    Node *iter = head;
    Node *temp = new Node;
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

int FindMergeNode(Node *headA, Node *headB) {
    int countA = 0, countB = 0, diff = 0;
    Node *temp = headA;
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
    Node* temp2 = (countA>countB)?headB:headA;
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

int HasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

// print-the-elements-of-a-linked-list-in-reverse

void ReversePrint(Node *head) {
    if (!head)
        return;
    ReversePrint(head->next);
    cout << head->data << endl; 
}

// reverse-a-linked-list

Node* Reverse(Node *head) {
    int count=0;
    stack<Node*> st;
    Node* temp = head;
    if (!temp || !temp->next)
        return temp;
    while (temp) {
        s.push(temp);
        temp = temp->next;
        count++;
    }
    count/=2;
    
}

Node* Delete(Node *head, int position) {
    Node *temp = head;
    if (0 == position) {
        delete head;
        return temp->next;
    }
    position--;
    while (position--) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
    return head;
}


void Print(Node *head) {
    bool ok = false;
    while(head != NULL)
    {
        if(ok)cout<<" ";
        else ok = true;
        cout<<head->data;
        head = head->next;
    }
}

Node* Push(Node *head,int x) {
   Node *temp = new Node();
   temp->data = x;
   temp->next = NULL;
   if(head == NULL) {
       return temp;
   }
   Node *temp1;
   for(temp1 = head;temp1->next!=NULL;temp1= temp1->next);
   temp1->next = temp;return head;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        Node *A = NULL;
        int m;cin>>m;
        while(m--) {
            int x;
            cin>>x;
            A = Push(A,x);
        }
        // int n;cin>>n;
        // cout<<GetNode(A,n)<<"\n";
        //RemoveDuplicates(A);
        ReversePrint(A);
        Print(A);
    }
}
#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Function to find the middle node
ListNode* middleNode(ListNode* head) {
        
    ListNode* fastPtr = head;
    ListNode* slowPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL){
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}

//Function To build the linked list
ListNode* buildLinkedList(){
    int n;

    cout<<"####### Program to find the middle node of a linked list ######"<<endl;
    cout<<"Enter the Number of elements: ";
    cin>>n;

    ListNode* head;
    ListNode* tail = head;

    for(int i = 0; i < n; i++){
        int x;
        cout<<"Enter element number "<<i+1<<" : ";
        cin>>x;

        if(i == 0){
            head = new ListNode(x);
            tail = head;
            continue;
        }
        
        ListNode* newNode = new ListNode(x);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int main(){

    ListNode* head = buildLinkedList();

    cout<<"The middle node is : "<<middleNode(head)->val<<endl;

    return 0;
}

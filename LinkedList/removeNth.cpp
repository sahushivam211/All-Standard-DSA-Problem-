#include<bits/stdc++.h>
using namespace std;

// !-----

// Time Complexity: O(N)
// Space Complexity: O(1)

// ------!



// structure of a node.
struct Node {
   int val;
   Node *next;
   Node() : val(0), next(nullptr) {}
   Node(int x) : val(x), next(nullptr) {}
   Node(int x, Node *next) : val(x), next(next) {}
};


Node* removeNthFromEnd(Node* head, int n) {
   Node *slow=head, *fast=head;
   
   // iterate fast pointet till n
   for(int i=0;i<n;i++){
      fast=fast->next;
   }
   if(!fast){
      head=head->next;
      return head;
   }
   
   // iterate slow and fast pointers till fast reaches end of list.
   while(fast->next){
      slow=slow->next;
      fast=fast->next;
   }

   // Replace next node of slow pointer with next to next node of slow pointer.
   slow->next=slow->next->next;
   
   return head;
}

// helper function to print elements of list.
void print(Node *head){
   while(head){
      cout<<head->val<<" ";
      head=head->next;
   }
   cout<<endl;
}

int main(){
   // formation of list
   Node *head=new Node(1);
   head->next=new Node(2);
   head->next->next=new Node(3);
   head->next->next->next=new Node(4);
   head->next->next->next->next=new Node(5);

   printf("List elements before deleting: ");
   print(head);

   int ind;
   printf("Enter a index (between 1 and size of list): ");
   cin>>ind;

   Node *ans=removeNthFromEnd(head,ind);
   printf("List elements after deleting: ");
   print(ans);
}
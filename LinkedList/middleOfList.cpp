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


// function to return middle node of a linked list.
Node* middleNode(Node* head) {
    Node *slow=head, *fast=head;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
	Node *head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(4);
	head->next->next->next->next=new Node(5);

	Node *ans=middleNode(head);
	printf("Middle node of linked list is: ");
	cout<<ans->val<<endl;
}
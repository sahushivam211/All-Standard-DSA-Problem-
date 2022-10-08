 #include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
      int data;
      Node* next ;
    // constructor  
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    // DESTRUCTOR
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory freed for node with data = "<<value<<endl;
    }
}; 

// Linked list creation 

void insertAtHead(Node* &head,int d){

    // creating node for d 
     Node * newNode = new Node(d); // node ban gya uska address newNode me hai
     newNode -> next = head;  // newNode is now pointing to what head is pointing !
     head = newNode ;        // updating head 
}

 //METHOD 1 : using map to detect loop in  a linked list
 // TC = O(n) ; SC = O(n)
bool detectLoop(Node *head){

    // if empty list then return false
    if(head == NULL){
        return 0;
    }

    Node * temp = head;
    map<Node*,bool> visited;

    while(temp!=NULL){

        if(visited[temp] == true){
            return 1; // loop detected !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return 0 ;  // means Loop NOT DETECTED !!!!!!!!!!!!!!!!!!!!!!
}

 //METHOD 2 : Using slow and fast pointers
 // TC = O(n) ; SC = O(1)
Node* floydDetectLoop(Node *head){

    if(head == NULL){
        return head ;   // no cycle/loop 
    }

    Node * slow = head;
    Node*fast = head;

    while(fast!=NULL && slow!=NULL){

        fast = fast->next;
        if(fast!= NULL){
            fast = fast->next;
        }
        slow  = slow->next;
        if(slow == fast){
             // LOOP --------------- DETECTED-----------------
             cout<<"\ncycle is present at slow->data : "<<slow->data<<endl;
             return slow;
        }
    }
    return NULL;
    
}

int main()
{

 Node* head = new Node(10);
 Node * tail = head;
 insertAtHead(head,14);
 insertAtHead(head,6);
 insertAtHead(head,-5);
   
  tail->next = head->next->next;   // MAKING LOOP manually

   cout<<floydDetectLoop(head)<<endl;

    return 0;
}

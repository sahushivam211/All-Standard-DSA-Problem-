bool isPalindrome(ListNode* head) {
     
        stack<ListNode*> st;
        ListNode *curr = head;
        while(curr)
        {
            st.push(curr);
            curr = curr->next;
        }
        
        while(st.top() != head)
        {
            if(head->val != st.top()->val)
            {
                return false;
            }
            if(head->next == st.top())
                break;
            st.pop();
            head = head->next;
        }
        return true;
    }

//Accepted    16 ms    cpp
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        stack<ListNode *> S;
        ListNode *node = head;
        while(node){
            S.push(node);
            node = node->next;
        }
        ListNode * rear = NULL;
        int reIndex = 0;
        while(!S.empty()){
            if(n == reIndex){
                break;
            }
            else{
                rear = S.top();
                S.pop();
                reIndex++;
            }
        }
        
        if(n == reIndex){
            if(rear){
                if(!S.empty()){
                    node = S.top();
                    node->next = rear->next;
                }
                else{
                    head = rear->next;
                }
            }
            else{
                if(!S.empty()){
                    node = S.top();
                    node->next = NULL;
                }
                else{
                    return NULL;
                }
            }
        }
        return head;
    }
    
};


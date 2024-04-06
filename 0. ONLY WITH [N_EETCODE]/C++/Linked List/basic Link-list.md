# Creating a Linked List:

```C++

class Node{
    Public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    Public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};
int main(){
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point
}

//0x11b7f90
//2
```
# Corner case in addition and deletion:

- check if deleting or updating the node is out of bound .
- check if deleting or updating the node is head
- consider the next value
# Middle of the Linked List:

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next  ){
            slow = slow-> next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```
# reverse of a link list:

### Recursive:

![image](https://github.com/NIBRAS-N/Competitive-Programming-From-Scratch/assets/83491751/36c8e75c-ae06-43b5-a22a-a7b343dd1d6e)

```C++
 ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* last = rev(head->next);

        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* reverseList(ListNode* head) {
       
        return rev(head);
    }
```

### iterative

```C++
ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        // cout<<head<<" "<<head->next<<endl;
        // head=head->next;
        // cout<<head<<" "<<head->next<<endl;
        // cout<<curr->next<<endl;
        // head  = head->next;
        //  cout<<head<<" "<<curr<<" "<<curr->next<<endl;
        while(curr!= NULL){
             ListNode *temp = curr->next;
             curr->next=prev;
             prev=curr;
             curr = temp;
         }
         return prev;

        //return rev(head);
    }
```

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node* rev(Node*head)
    {
        if(head==NULL||head->next==NULL)return head;
        
        Node* newhead=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    Node *reverse(Node *head, int k)
    {
        Node*second=nullptr;
        Node*temp=head;
        k--;
        while(k--)
        {
            temp=temp->next;
        }
        if(temp==nullptr || temp->next==nullptr)
            return head;
        second=temp->next;
        temp->next=nullptr;
        Node*first=rev(head);
        second=rev(second);
        temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=second;
        return first;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
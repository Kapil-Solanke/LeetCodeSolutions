//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node*left,Node*right)
    {
        if(left==NULL)return right;
        if(right==NULL)return left;
        if(left->data>right->data)
        {
            Node*temp=left;
            left=right;
            right=temp;
        }
        Node*curr=left;
        Node*prev=curr;
        Node*temp=right;
        while(curr&&temp)
        {
            if(temp->data<curr->data)
            {
                Node*tmpnxt=temp->next;
                prev->next=temp;
                temp->next=curr;
                
                temp=tmpnxt;
                prev=prev->next;
            }
            else
            {
                prev=curr;
                
                curr=curr->next;
            }
        }
        if(temp!=NULL)
            prev->next=temp;
        return left;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
        if(K==1)return arr[0];
        Node*res=arr[0]; 
        for(int i=1;i<K;i++)
        {
            res=merge(res,arr[i]);
        }
        return res;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends
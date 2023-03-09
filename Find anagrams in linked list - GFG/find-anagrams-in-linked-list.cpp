//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<int>freq(26,0),vis(26,0),arr(26,0);
        for(auto ch:s)
            freq[ch-'a']++;
        Node*curr=head;Node*start=head;
        int size=s.size();
        vector<Node*>ans;
        while(curr!=NULL)
        {
            vis[curr->data-'a']++;
            size--;
            if(size==0)
            {
                if(freq==vis)
                {
                    ans.push_back(start);
                    Node*temp=curr->next;
                    curr->next=NULL;
                    start=temp;
                    curr=temp;
                    
                    vis=arr;
                    size=s.length();
                }
                else{
                    vis[start->data-'a']--;
                    size++;
                    start=start->next;
                    curr=curr->next;
                }
            }
            else
                curr=curr->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends
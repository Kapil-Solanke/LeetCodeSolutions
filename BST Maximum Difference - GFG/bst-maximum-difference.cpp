//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long first=0,second=INT_MAX;
    Node* find(Node*root,int target,long long sum)
    {
        if(!root)return NULL;
        
        if(root->data==target){
            first=sum;
            return root;
        }
        sum+=root->data;
        Node*left=find(root->left,target,sum);
        Node*right=find(root->right,target,sum);
        sum-=root->data;
        if(left!=NULL)return left;
        if(right!=NULL)return right;
        return NULL;
    }
    void minsum(Node*root,long long&sum)
    {
        if(!root)return;
        sum+=root->data;
        if(root->left==NULL&&root->right==NULL)
        {
            second=min(second,sum);
        }
        minsum(root->left,sum);
        minsum(root->right,sum);
        sum-=root->data;
    }
    int maxDifferenceBST(Node *root,int target)
    {
        
        long long sum=0;
        Node*node=find(root,target,sum);
        if(node==NULL)return -1;
        sum=0;
        minsum(node,sum);
        return first-second+node->data;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
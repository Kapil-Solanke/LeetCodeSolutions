//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Node{
    public:
    char val;
    vector<Node*>child;
    int count;
    Node(char ch){
        val=ch;
        child.resize(26,NULL);
        count=0;
    }
};
class Trie{
    public:
    Node*root;
    Trie(){
        root=new Node('*');
    }
    
    void add(string word){
        Node*temp=root;
        for(auto&ch:word)
        {
            if(temp->child[ch-'a']==NULL)
            {
                temp->child[ch-'a']=new Node(ch);
            }
            temp->child[ch-'a']->count++;
            temp=temp->child[ch-'a'];
        }
        return;
    }
    int search(string word){
        Node*temp=root;int cnt=0;
        for(auto&ch:word)
        {
            if(temp->child[ch-'a']==NULL)
            {
                return 0;
            }
            cnt=temp->child[ch-'a']->count;
            temp=temp->child[ch-'a'];
        }
        return cnt;
    }
};
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){  
        if(k>str.size())return 0;
        Trie *t=new Trie();
        
        for(int i=0;i<n;++i){
            t->add(arr[i]);
        }
        
        str=str.substr(0,k);
        int cnt=t->search(str);
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
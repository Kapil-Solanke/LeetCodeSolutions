//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode{
    public:
    TrieNode* child[26];
    bool end;
    TrieNode(){
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        end=false;
    }
};
class Trie{
    private:
    TrieNode*root;
    public:
    Trie(){
        root=new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode*temp=root;
        for(auto& ch:word)
        {
            if(temp->child[ch-'a']==NULL)
            {
                // TrieNode*newchild=new TrieNode();
                temp->child[ch-'a']=new TrieNode();
            }
            temp=temp->child[ch-'a'];
        }
        temp->end=true;
        return;
    }
    bool search(string word)
    {
        TrieNode*temp=root;
        for(auto& ch:word)
        {
            if(temp->child[ch-'a']==NULL)
            {
                return false;
            }
            temp=temp->child[ch-'a'];
        }
        return true;
    }
};
class Solution{
public:
    Trie* root=new Trie();
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        for(auto w:s1)
        {
            root->insert(w);
            reverse(w.begin(),w.end());
            root->insert(w);
        }
        int ans=0;
        for(auto w:s2)
        {
            if(root->search(w))
            {
                ans++;continue;
            }
            reverse(w.begin(),w.end());
            if(root->search(w))
            {
                ans++;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
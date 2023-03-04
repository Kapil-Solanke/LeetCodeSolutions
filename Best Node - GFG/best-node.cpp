//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#define ll long long 
class Solution {
  public:
    pair<ll,ll> dfs(int i,vector<vector<int>> &adj,vector<int> &a,vector<int> &vis,ll &ans)
    {
        vis[i]=1;
        ll mini=1e10,maxi=-1e10;
        int flag=0;
        for(auto &x:adj[i])
        {
            if(!vis[x])
            {
                flag=1;
                auto childVal=dfs(x,adj,a,vis,ans);
                mini=min(mini,a[i-1]-childVal.second);
                maxi=max(maxi,a[i-1]-childVal.first);
            }
        }
        if(!flag){
            ll ans1=a[i-1];
            ans=max(ans,ans1);
            return {ans1,ans1};
        }
        ans=max(ans,maxi);
        return {mini,maxi};
    }
    long long bestNode(int N, vector<int> &A, vector<int> &P) 
    {
        vector<vector<int>> adj(N+1);
        vector<int> vis(N+1,0);
        for(int i=1;i<N;i++)
        {
            adj[P[i]].push_back(i+1);
            adj[i+1].push_back(P[i]);
        }
        ll ans=-1e10;
        dfs(1,adj,A,vis,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
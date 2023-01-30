//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


#define pb push_back
class Solution{
  public:
    int  dfs(int node,int parent,int islight,vector<vector<int>>&dp,vector<int>adj[])
    {
        if(dp[node][islight]!=-1)
            return dp[node][islight];
        int ans=0;
        for(auto child:adj[node])
        {
            if(child!=parent)
            {
                if(islight==0)
                {
                    int x=dfs(child,node,1,dp,adj);
                    ans+=x+1;
                }
                else{
                    int x=dfs(child,node,0,dp,adj);
                    int y=dfs(child,node,1,dp,adj);
                    ans+=min(x,y+1);
                }
            }
        }
        return dp[node][islight]=ans;
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        // vector<int>in(N+1,0);
        vector<int>adj[N+1];
        for(auto e:edges)
        {
            adj[e[0]].pb(e[1]);
            adj[e[1]].pb(e[0]);
         
        }
        
        vector<vector<int>>dp(N+1,vector<int>(2,-1));
        vector<vector<int>>dp1(N+1,vector<int>(2,-1));
        return min(dfs(1,-1,0,dp,adj),dfs(1,-1,1,dp1,adj)+1);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
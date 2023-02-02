//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
    vector<int>vis,pathvis;
    int ans=0;
    void dfs(int node,int par,vector<int>adj[])
    {
        vis[node]=1;
        if(par==-1)
            pathvis[node]=node;
        else
            pathvis[node]=node+pathvis[par];
        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                dfs(child,node,adj);
            }
            else if(pathvis[child]!=-1){
                ans=max(ans,pathvis[node]-pathvis[child]+child);
            }
        }
        pathvis[node]=-1;
        return;
    }
  long long largestSumCycle(int N, vector<int> Edge)
  {
      vector<int>adj[N];
      vis.resize(N,0);
      pathvis.resize(N,-1);
      for(int i=0;i<N;i++)
      {
          if(Edge[i]==-1)continue;
          adj[i].push_back(Edge[i]);
      }
      for(int i=0;i<N;i++)
      {
          if(!vis[i])dfs(i,-1,adj);
      }
      return ans==0?-1:ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
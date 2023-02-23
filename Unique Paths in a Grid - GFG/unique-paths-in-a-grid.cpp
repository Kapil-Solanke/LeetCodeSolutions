//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mod=1e9+7;
    int solve(int r,int c,int row,int col,vector<vector<int>> &grid,vector<vector<int>>&dp)
    {
        if(r<0||c<0||r>=row||c>=col||grid[r][c]==0)
            return 0;
        if(r==row-1&&c==col-1)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=0;
        ans+=solve(r+1,c,row,col,grid,dp);
        ans+=solve(r,c+1,row,col,grid,dp);
        ans%=mod;
        
        return dp[r][c]=ans;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        int col=grid[0].size();
        int row=grid.size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        return solve(0,0,row,col,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
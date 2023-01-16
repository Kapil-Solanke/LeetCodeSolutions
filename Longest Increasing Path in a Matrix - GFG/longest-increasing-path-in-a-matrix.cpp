//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int direction[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    int dp[1001][1001];
    int dfs(int r,int c,vector<vector<int>>& matrix, int n, int m)
    {
        if(r<0||c<0||r>=n||c>=m)
            return INT_MIN;
        // if(r==n-1)
        //     return matrix[r][c];
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int ans=1;
        for(int i=0;i<4;i++)
        {
            int newr=r+direction[i][0],newc=c+direction[i][1];
            if(newr<0||newc<0||newr>=n||newc>=m||matrix[newr][newc]<=matrix[r][c])
                continue;
            ans=max(ans,1+dfs(newr,newc,matrix,n,m));
        }
        return dp[r][c]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) 
    {
        memset(dp,-1,sizeof(dp));
        int maxi=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                maxi=max(maxi,dfs(i,j,matrix,n,m));
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        
        vector<int>rx {2, 1, -1, -2, -2, -1, 1, 2};
        vector<int>ry {1, 2, 2, 1, -1, -2, -2, -1 };
        
        int row = arr.size(), col = arr[0].size();
        vector<vector<int>> vis(row, vector<int> (col, 0));
        
        queue<pair<int, int>> q;
        q.push({start_x, start_y});
        vis[start_x][start_y] = 1;
        vector<int>coins;

        while(!q.empty())
        {
            int size = q.size();
            int coin = 0;

            while(size--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                coin += arr[r][c];
                for(int z = 0 ; z < 8 ; z++)
                {
                    int nr = r + rx[z];
                    int nc = c + ry[z];
                    
                    if(nr >= 0 && nc >= 0 && nr < row && nc < col && !vis[nr][nc])
                    {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            coins.push_back(coin);
        }

        int minsteps = -1;
        int n = coins.size();
        int maxi = INT_MIN;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(i + coins[i] < n)
                coins[i] += coins[i + coins[i]];
                
            if(maxi <= coins[i]){
                minsteps = i;
                maxi = coins[i];
            }
        }
        return minsteps;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends
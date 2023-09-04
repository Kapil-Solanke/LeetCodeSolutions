//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>&visited)
    {
        int row=board.size(),col=board[0].size();
        if(r<0||c<0||r>=row||c>=col||board[r][c]=='X'||visited[r][c])
            return;
        visited[r][c]=1;
        dfs(r+1,c,board,visited);
        dfs(r,c+1,board,visited);
        dfs(r-1,c,board,visited);
        dfs(r,c-1,board,visited);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        int row=board.size(),col=board[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int r=0;r<row;r++)
        {
            if(board[r][0]=='O'&&visited[r][0]==0)
                dfs(r,0,board,visited);
            if(board[r][col-1]=='O'&&visited[r][col-1]==0)
                dfs(r,col-1,board,visited);
        }
        for(int c=0;c<col;c++)
        {
            if(board[0][c]=='O'&&visited[0][c]==0)
                dfs(0,c,board,visited);
            if(board[row-1][c]=='O'&&visited[row-1][c]==0)
                dfs(row-1,c,board,visited);
        }
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(board[r][c]=='O'&&visited[r][c]==0)
                    board[r][c]='X';
            }
        }
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
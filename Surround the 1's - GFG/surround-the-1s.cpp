//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        vector<pair<int,int>>dir={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        int row=matrix.size(),col=matrix[0].size();
        int ans=0,count=0,nr,nc;
        for(int r=0;r<row;++r)
        {
            for(int c=0;c<col;++c)
            {
                if(matrix[r][c]==0)continue;
                count=0;
                for(int i=0;i<8;++i){
                    nr=r+dir[i].first;
                    nc=c+dir[i].second;
                    if(nr<0||nc<0||nr>=row||nc>=col||matrix[nr][nc])continue;
                    count++;
                }
                if(count>0&&count%2==0)ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
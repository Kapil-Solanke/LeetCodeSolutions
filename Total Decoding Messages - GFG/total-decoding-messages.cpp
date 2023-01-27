//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int dp[10001];
	    int mod=1e9+7;
	    int solve(int ind,int n, string s)
	    {
	        
	        if(ind<n&&s[ind]=='0')
	            return 0;
	        if(ind>=n)
	            return 1;
	        if(dp[ind]!=-1)
	            return dp[ind];
	        int ways=0;
	        if(s[ind]!='0')
	            ways+=solve(ind+1,n,s)%mod;
	        if(ind+1<n&&((s[ind]=='1'&&s[ind+1]>='0')||(s[ind]=='2'&&s[ind+1]<='6')))
	            ways+=solve(ind+2,n,s)%mod;
	        return dp[ind]=ways%mod;
	    }
		int CountWays(string str){
		    // Code here
		    memset(dp,-1,sizeof(dp));
		    return solve(0,str.size(),str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int dp[1001][1001];
    int mod=1e9+7;
    int generate(int start,int end,int s,int n)
    {
        if(s==n*2)// when we will reach end store our string in ans
        {
            return 1;
        }
        if(dp[start][end]!=-1)return dp[start][end];
        int res=0;
        if(start<n)res+=generate(start+1,end,s+1,n)%mod;// for half values we will have open brackets     
        if(end<start)res+=generate(start,end+1,s+1,n)%mod;// for other half values we will have close brackets     
        return dp[start][end]=res%mod;
    }
    int findCatalan(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return generate(0,0,0,n);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
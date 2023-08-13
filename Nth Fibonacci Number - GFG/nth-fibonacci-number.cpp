//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    int dp[100001];
    int solve(int n)
    {
        if(n<2)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(solve(n-1)%mod+solve(n-2)%mod)%mod;
        
    }
    int nthFibonacci(int n){
        memset(dp,-1,sizeof(dp));
        return solve(n);
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
    ll dp[100000][2];
  public:
    ll solve(ll i,ll prev,vector<vector<ll>> &mp)
    {
        if(i==mp.size())
            return abs(mp[i-1][prev]);
        
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        
        ll a1=abs(mp[i][0]-mp[i-1][prev])+abs(mp[i][1]-mp[i][0]);
        ll a2=abs(mp[i][1]-mp[i-1][prev])+abs(mp[i][1]-mp[i][0]);
        
        return dp[i][prev]=min(a1+solve(i+1,1,mp),a2+solve(i+1,0,mp));
    }
    ll minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        memset(dp,-1,sizeof(dp));
        map<ll,vector<ll>> mp;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mp[types[i]].push_back(locations[i]);
            mx=max(mx,int(mp[types[i]].size()));
        }
        for(int i=0;i<mx;i++)
        {
            mp[0].push_back(0);
        }
        for(auto& it:mp)
        {
            vector<ll> v=it.second;
            sort(v.begin(),v.end());
            mp[it.first]=v;
        }
        vector<vector<ll>> vec;
        int i=0;
        for(auto& x:mp)
        {
            auto it=x.second;
            vector<ll> v={it[0],it[it.size()-1]};
            vec.push_back(v);
            i++;
        }
        // int sz=mp.size();
        return solve(1,0,vec);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
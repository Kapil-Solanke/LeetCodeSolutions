//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr)
  {
      unordered_set<int>s1,s2;
      vector<long long int>ans(k,0);
      for(int i=0;i<k;i++)
      {
        s1.insert(arr[i][0]-1);
        s2.insert(arr[i][1]-1);
        if(s1.size()==n||s2.size()==n)
            ans[i]=0;
        else{
            ans[i]=n*n-(s1.size()+s2.size())*n+s1.size()*s2.size();
        }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
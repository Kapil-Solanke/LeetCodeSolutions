//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &arr){
        // Code here
        vector<int>l(n,0),r(n,0);
        int maxi=-1,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
            l[i]=maxi;
        }
        for(int i=n-1;i>=0;i--)
        {
            mini=min(mini,arr[i]);
            r[i]=mini;
        }
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(l[i]+r[i+1]>=k)
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
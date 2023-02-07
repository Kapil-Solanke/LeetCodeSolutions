//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int neg=0,negind=-1,start=0,maxi=0;
           for(int end=0;end<n;end++)
           {
               if(arr[end]==0)
               {
                   start=end+1;
                   neg=0;
                   negind=-1;
               }
                if(arr[end]<0)
               {
                    neg++;
                    if(negind==-1)
                        negind=end;
               }
                if(neg%2==0)
                    maxi=max(maxi,end-start+1);
                else{
                    maxi=max(maxi,end-(negind+1)+1);
                }
           }
           return maxi;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends
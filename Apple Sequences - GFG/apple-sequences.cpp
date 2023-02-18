//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int apple=0,orange=0,maxi=0,start=0;
        for(int end=0;end<n;end++)
        {
            if(arr[end]=='O')orange++;
            else apple++;
            while(start<=end&&orange>m){
                if(arr[start]=='O')orange--;
                start++;
            }
            maxi=max(maxi,end-start+1);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        vector<int> prev(4, 0);
        prev[0] = 1;
        int mod=1e9+7;
        for(int i = 1; i <= N; i++){
            vector<int> curr(4, 0);
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    if( j == k ) continue;
                    curr[j] += prev[k];
                    curr[j] %= mod;
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
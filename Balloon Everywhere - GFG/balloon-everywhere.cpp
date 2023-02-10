//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        string str="balloon";
        vector<int>need(26,0);
        for(auto i:str)
            need[i-'a']++;
        vector<int>freq(26,0);
        for(auto i:s)
            freq[i-'a']++;
         
        int mini=INT_MAX;
        for(int i=0;i<26;i++)
        {
            if(need[i]==0)continue;
            mini=min(mini,freq[i]/need[i]);
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
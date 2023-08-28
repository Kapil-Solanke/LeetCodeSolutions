//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) {
        unordered_map<char,int>mp;
        int maxi=-1;
        for(int s=0,e=0;e<str.size();++e)
        {
            mp[str[e]]++;
            while(mp.size()>k){
                mp[str[s]]--;
                if(mp[str[s]]==0)mp.erase(str[s]);
                s++;
            }
            if(mp.size()==k)
                maxi=max(maxi,e-s+1);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
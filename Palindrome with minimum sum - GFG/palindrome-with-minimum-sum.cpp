//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string str) {
        // code here
        int n=str.size();
        int s=0,e=n-1;
        while(s<e)
        {
            if(str[s]!='?'&&str[e]!='?'&&str[s]!=str[e])
                return -1;
            if(str[s]=='?'&&str[e]!='?')
            {
                str[s]=str[e];
            }
            if(str[e]=='?'&&str[s]!='?')
            {
                str[e]=str[s];
            }
            ++s,--e;
        }
        string temp="";
        for(int i=0;i<n;++i)
        {
            if(str[i]!='?')
                temp.push_back(str[i]);
        }
        if(temp.size()==0)return 0;
        int sum=0;
        for(int i=0;i<temp.size()-1;++i)
        {
            sum+=abs(temp[i+1]-temp[i]);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
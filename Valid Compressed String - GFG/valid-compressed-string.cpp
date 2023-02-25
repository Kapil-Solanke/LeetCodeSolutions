//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        unordered_set<char>st{'0','1','2','3','4','5','6','7','8','9'};
        int i=0,j=0;
        while(i<S.size()&&j<T.size())
        {
            if(st.find(T[j])!=st.end())
            {
                int count=0;
            while(j<T.length() && isdigit(T[j]))
            {
                count=count*10 + (T[j]-'0');
                j++;
            }
            
            i+=count;
            if(count==0) return 0;
            }
            else if(S[i]!=T[j])return false;
            else i++,j++;
        }
        return i==S.length() && j==T.length();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
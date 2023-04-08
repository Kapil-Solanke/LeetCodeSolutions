//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define pb push_back
#define po pop_back
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>st;
        st.pb(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(st.size()&&((arr[i]<0&&st.back()>=0)||(arr[i]>=00&&st.back()<0)))
            // if(1ll*arr[i]*st.back()<0)
            {
                st.po();
            }
            else{
                st.pb(arr[i]);
            }
        }
        return st;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends
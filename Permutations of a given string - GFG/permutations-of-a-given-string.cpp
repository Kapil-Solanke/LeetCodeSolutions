//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    unordered_set<string>st;
	    void solve(int ind,string s)
	    {
	        if(ind>=s.size())
	        {
	            st.insert(s);
	            return;
	        }
	        for(int j=ind;j<s.size();++j)
	        {
	            swap(s[ind],s[j]);
	            solve(ind+1,s);
	            swap(s[ind],s[j]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    
		    solve(0,s);
		    vector<string>ans(st.begin(),st.end());
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
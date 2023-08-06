//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>ans;
    void solve(int ind,string s)
    {
        if(ind>=s.size()){
            ans.push_back(s);
            return;
        }
        for(int j=ind;j<s.size();++j)
        {
            swap(s[j],s[ind]);
            solve(ind+1,s);
            swap(s[j],s[ind]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        solve(0,S);
        sort(begin(ans),end(ans));
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
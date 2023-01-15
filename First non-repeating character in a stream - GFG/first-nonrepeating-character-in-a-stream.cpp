//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>freq(26,0);
		    queue<int>q;
		    string ans="";
		    for(int i=0;i<A.size();i++)
		    {
		        q.push(A[i]);
		        freq[A[i]-'a']++;
		        while(!q.empty()&&freq[q.front()-'a']>1)
		            q.pop();
		        if(!q.empty())
		            ans.push_back(q.front());
		        else{
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
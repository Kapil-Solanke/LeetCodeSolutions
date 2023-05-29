//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> dict, string p) {
        // code here
        // vector<int>mp(26,0);
        // for(int i=0;i<p.size();++i)
        // {   
        //     if(p[i]>='A'&&p[i]<='Z')
        //         mp[p[i]-'A']=1;
            
        // }
        vector<string>ans;
        for(auto& word:dict)
        {
            string temp="";
            for(int i=0;i<word.size();++i)
            {   
                if(word[i]>='A'&&word[i]<='Z')
                    temp+=word[i];
                
            }
            if(temp.size()<p.size())
                continue;
            bool flag=true;
            for(int i=0;i<p.size();i++)
            {
                if(p[i]!=temp[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        if(ans.size())return ans;
        return {"-1"};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
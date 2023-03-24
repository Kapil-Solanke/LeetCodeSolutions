//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string str) {
        // code here
        int n=str.size();
        int s=0,e=n-1,rev=0;
        bool flag=true;
        
        vector<int>freq(26,0);
        
        for(int i=0;i<n;i++)
            freq[str[i]-'a']++;
            
        string ans;
        string begin="",end="";
        while(s<=e)
        {
            if(flag)
            {
                char ch=str[s++];
                if(freq[ch-'a']>1)
                {
                    freq[ch-'a']--;
                    flag=!flag;
                    rev++;
                }
                else{
                    begin+=ch;
                }
            }
            else{
                char ch=str[e--];
                if(freq[ch-'a']>1)
                {
                    
                    freq[ch-'a']--;
         
                    flag=!flag;
                    rev++;
                }
                else{
                    end=ch+end;
                }
            }
        }
        
        ans=begin+end;
        if(rev%2==1)reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
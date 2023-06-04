//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            int n=s.size();
            vector<string>vec;
            int i=0;
            while(i<n)
            {
                string num="";
                if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
                {   
                    num+=s[i++];
                    vec.push_back(num);
                    continue;
                }
                
                while(i<n&&s[i]>='0'&&s[i]<='9')
                    num+=s[i],i++;
                vec.push_back(num);
            }
            reverse(begin(vec),end(vec));
            string ans="";
            for(int i=0;i<vec.size();i++)
            {
                ans+=vec[i];
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string s="",rev="",ans="";
        s+=str[0];
        rev+=str[0];
        ans=s+rev;
        for(int i=1;i<str.size();i++)
        {
            s=s+str[i];
            rev=str[i]+rev;
            string temp=s+rev;
            if(temp>ans)break;
            ans=temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends
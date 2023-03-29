//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string str)
    {
        // code here
        int count=0;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            int small=0,big=0;
            for(int j=i;j<n;j++)
            {
                if(str[j]>='a'&&str[j]<='z')
                    small++;
                if(str[j]>='A'&&str[j]<='Z')
                    big++;
                if(small==big)count++;
            }
            
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<float,int>map;
        
        int res=0;
        for(int i=0 ; i<n ; i++)
        {
            
            double x= double(denominator[i]-numerator[i])/double(denominator[i]);//x=1-y
            double y= double(numerator[i])/double(denominator[i]);
            if(map.find(x)!=map.end())
            {
                res += map[x];
            }
            map[y]++;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
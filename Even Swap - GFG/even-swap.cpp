//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &arr,int n)
        {
            int prev=0;
            for(int next=prev+1;next<n;next++)
            {
                while(next<n&&(arr[next]+arr[prev])%2==0)
                    next++;
                
                sort(arr.begin()+prev,arr.begin()+next,greater<int>());
                prev=next;
            }
            return arr;
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
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
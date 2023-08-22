//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int ans=0,cnt=0,rsum,csum,maxi=0;
        vector<int>row(n,0);
        for(int i=0;i<n;i++){
            rsum=0,csum=0;
            for(int j=0;j<n;j++){
                rsum+=matrix[i][j];
                csum+=matrix[j][i];
            }
            maxi=max(maxi,max(rsum,csum));
            row[i]=rsum;
        }
        for(int i=0;i<n;i++){
            ans+=maxi-row[i];
        }
        return ans;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
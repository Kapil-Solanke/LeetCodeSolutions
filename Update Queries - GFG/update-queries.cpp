//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> bit(N,vector<int>(17,0));
            int l,r,val;
            for(auto it:U)
            {
                l=it[0]-1;
                r=it[1];
                val=it[2];
                for(int i=0;i<17;i++)
                {
                    if(((val>>i)&1))
                    {

                        bit[l][i]++;
                        if(r<N)
                            bit[r][i]--;
                    }

                }

            }
           for(int i=0;i<N-1;i++)
            {
                for(int j=0;j<17;j++)

                    bit[i+1][j]+=bit[i][j];
            }
            int sum;
            vector<int> ans;

            for(int i=0;i<N;i++)
            {
                sum=0;
                for(int j=0;j<17;j++)
                {
                    if(bit[i][j])

                        sum+=pow(2,j);
                }
                ans.push_back(sum);
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
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
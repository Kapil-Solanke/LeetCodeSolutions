//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int row,int col,int k)
    {
 		// Your code goes here.
 		int sr=0,sc=0,er=row-1,ec=col-1,total=row*col,cnt=0;
 		vector<int>ans;
 		while(cnt<k)
 		{
 		    for(int c=sc;c<=ec;++c){
 		        ans.push_back(a[sr][c]);cnt++;
 		    }
 		    sr++;
 		    
 		    for(int r=sr;r<=er;++r ){
 		        ans.push_back(a[r][ec]);
 		        cnt++;
 		    }
 		    ec--;
 		    for(int c=ec;c>=sc;--c){
 		        ans.push_back(a[er][c]);
 		        cnt++; 
 		    }
 		    er--;
 		    for(int r=er;r>=sr;--r){
 		        ans.push_back(a[r][sc]);
 		        cnt++;
 		    }
 		    sc++;
 		}
 		return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
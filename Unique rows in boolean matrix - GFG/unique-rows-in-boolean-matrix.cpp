//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int m[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>>ans;
        vector<int>arr;
        unordered_set<string>st;
        string temp;
        for(int r=0;r<row;++r){
            temp="";
            arr.resize(col,0);
            for(int c=0;c<col;++c){
                arr[c]=m[r][c];
                temp+=to_string(m[r][c]);
            }
            if(st.count(temp)==0)
            {
                // copy(m[r],m[r]+col,arr);
                ans.push_back(arr);
                st.insert(temp);
            }
        }
        return ans;
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
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends
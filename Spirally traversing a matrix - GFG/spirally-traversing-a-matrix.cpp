//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int total = r*c;
        int count = 0;
        int sRow = 0;
        int eRow = r-1;
        int sCol = 0;
        int eCol = c-1;
        vector<int> v;

        while(count < total)
        {
            //first row
            for(int i = sCol; count < total && i <= eCol; i++){
                v.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;
            
            //last column
            for(int i = sRow; count < total && i <= eRow; i++){
                v.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;
            //last row
            for(int i = eCol; count < total && i >= sCol; i--){
                v.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;
            
            //first column
            for(int i = eRow; count < total && i >= sRow; i--){
                v.push_back(matrix[i][sCol]);
                count++;
            }
            sCol++;
        }
        return v; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
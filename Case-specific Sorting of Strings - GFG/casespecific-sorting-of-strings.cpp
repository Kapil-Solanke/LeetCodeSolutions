//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<int>mp(n); //1 big, 0 small

        string big="";
        string small="";
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                mp[i]=0;small.push_back(str[i]);
            }
            else if(str[i]>='A'&&str[i]<='Z')
            {
                mp[i]=1;big.push_back(str[i]);
            }
        }
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        
        int smallind=0,bigind=0;
        for(int i=0;i<n;i++)
        {
            if(mp[i])
                str[i]=big[bigind++];
            else{
                str[i]=small[smallind++];
            }
        }
        return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
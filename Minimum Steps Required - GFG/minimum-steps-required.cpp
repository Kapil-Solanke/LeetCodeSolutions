//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) 
{
    int n =  str.size();
    string s = "";
    s+=str[0];
    for(int i = 1; i< n; i++)
    {
        if(str[i] !=  str[i-1])
            s+=str[i];
    }
     int  cnta  = 0, cntb = 0;
     for(int  i = 0; i< s.size(); i++)
     {
        if(s[i] == 'a')
            cnta++;
        else
            cntb++;
     }
     return min(cnta , cntb)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends
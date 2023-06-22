//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &b) {
        // code here
        int f=0,t=0,tw=0;
        for(int i=0;i<N;++i)
        {
            if(b[i]==5)f++;
            else if(b[i]==10)f--,t++;
            else if(b[i]==20){
                if(t>0){
                    --t,--f;
                }else{
                    f-=3;
                }
                tw++;
            }
            
            if(f<0||t<0||tw<0)return false;
        }
        return true; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
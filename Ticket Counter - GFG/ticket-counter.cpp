//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        // code here
        int s=0,e=n-1;
        bool flag=true;
        while(s<e)
        {
            if(flag)
            {
                for(int i=0;i<k&&s<e;i++)s++;
                
                if(s==e)return s+1;
            }else{
                for(int i=0;i<k&&s<e;i++)e--;
                
                if(s==e)return e+1;
                
            }
            flag=!flag;
        }
        return s+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
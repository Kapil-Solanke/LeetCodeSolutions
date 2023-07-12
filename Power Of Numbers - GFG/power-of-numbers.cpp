//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    long long solve(int a,int b)
    {
        long long ans=1*1ll;
        long long m=1e9+7;
        while(b)
        {
            int last=b&1;
            if(last){
                ans=(ans%m*a%m);
            }
            a=(a%m*a%m);
            b=b>>1;
        }
        return ans%m;
    }
    long long power(int N,int R)
    {
       //Your code here
        return solve(N,R);
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends
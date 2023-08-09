//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool checkPrime(int n){
        if(n==2)
        return true;
        
        for(int i=2;i<sqrt(n)+1;i++){
            if (n%i==0)
            return false;
        }
        return true;
    }
    long long int largestPrimeFactor(int N){
        // code here
        int prime=0 , temp=N;
       for(int i=2;i<=temp;i++){
           if(temp%i==0 && checkPrime(i)){
               prime=i;
               temp=temp/i;
           }
       }
       return prime;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
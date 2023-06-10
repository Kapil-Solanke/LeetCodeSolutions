//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int temp[n];
            int pos=0, neg=0;
            for(int i=0;i<n;i++){
                temp[i]=arr[i];
                if(arr[i]>=0) pos++;
                else neg++;
            }
            
            if(neg==0 || pos==0) return ;
            
            int pos_index=(n-pos);
            int neg_index=(neg-1);
            
            for(int i=0;i<n;i++){
                if(temp[i]>=0) {
                    arr[pos_index++]=temp[i];
                }else{
                    arr[neg_index--]=temp[i];
                }
            }
            
            reverse(arr, arr + neg);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
         unordered_map<string, int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        unordered_set<string>st;
        for(auto it : mp){
            string temp = it.first;
            reverse(temp.begin(), temp.end());
            if(!mp.count(temp)){
               if(!(it.first == temp)) return false;
               else{
                   st.insert(it.first);
                   if(st.size() > 1) return false;
               }
            }
            else{
                if(it.first == temp){
                   st.insert(it.first);
                   if(st.size() > 1) return false; 
                }
                else{
                   if(it.second != mp[temp]){
                        if(!(it.first == temp)) return false;
                        else{
                           st.insert(it.first);
                           if(st.size() > 1) return false;
                       }
                    }
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends
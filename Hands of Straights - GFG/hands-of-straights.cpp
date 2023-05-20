//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int sz, vector<int> &arr) {
        // code here
        if(n%sz!=0)return false;
        map<int,int>mp;
        for(auto&i:arr)
            mp[i]++;
        
        for(int i=0;i<n/sz;++i)
        {
            int size=sz;
            map<int,int>::iterator it=mp.begin();
            int prev=-1;
            while(size--)
            {
                int curr=it->first;
                it->second--;
                if(prev!=-1&&curr!=prev+1)
                    return false;
                prev=it->first;
                auto next=it;
                next++;
                if(it->second==0)
                    mp.erase(it->first);
                it=next;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
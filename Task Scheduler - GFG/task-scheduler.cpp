//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        vector<int> freq(26);
        for(char c : tasks) freq[c - 'A']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int maxi = 0;
        for(int i=0; i<26; i++) 
        {
            if(!freq[i]) break;
            maxi = max(maxi, i + 1 + ((k + 1) * (freq[i] - 1)));
        }
        return max(maxi, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
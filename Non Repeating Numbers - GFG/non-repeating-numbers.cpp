//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int arrxor=0,right,n1=0,n2=0;
        for(auto&i:nums)arrxor^=i;
        
        for(int i=0;i<64;i++)
        {
            if(arrxor&1<<i){
                right=i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1<<right){
                n1^=nums[i];
            }else{
                n2^=nums[i];
            }
        }
        return {min(n1,n2),max(n1,n2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
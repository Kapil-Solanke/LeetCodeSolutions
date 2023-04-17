//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<vector<int>>v(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v[i][0]=arr[i].dead;
            v[i][1]=arr[i].profit;
        }
        sort(v.begin(),v.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            if(v[i][0]==pq.size())
            {
                if(v[i][1]>pq.top())
                {
                    pq.pop();
                    pq.push(v[i][1]);
                }
            }
            else if(v[i][0]>pq.size())
            {
                pq.push(v[i][1]);
            }
        }
        int count=0,sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();pq.pop();count++;
        }
        return {count,sum};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
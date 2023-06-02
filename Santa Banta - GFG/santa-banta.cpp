//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
  private:
  public:
  vector<int>parent,rank,size;
    DisjointSet(int n)
    {
        parent.resize(n+1,0),rank.resize(n+1,0),size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int parent_u=findParent(u);
        int parent_v=findParent(v);
        if(parent_u==parent_v)
        {
            return;
        }
        if(rank[parent_u]<rank[parent_v])
        {
            parent[parent_u]=parent_v;
        }
        else if(rank[parent_v]<rank[parent_u])
        {
            parent[parent_v]=parent_u;
        }
        else{
            parent[parent_v]=parent_u;
            rank[parent_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);
        if (ultimate_parent_u == ultimate_parent_v)
            return;
        if (size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else
        {
            parent[ultimate_parent_v] = u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }
};
class Solution{
public:
    int MAX_SIZE=1e6;
    vector<int> primes;
    void precompute(){

        vector<bool> isPrime(MAX_SIZE,true);

        vector<int> SPF(MAX_SIZE);

        isPrime[0]=isPrime[1]=false;

        for(int i=2;i<MAX_SIZE;i++){

            if(isPrime[i]){

                primes.push_back(i);

                SPF[i]=i;

            }

            for(int j=0; j<primes.size() and i*primes[j]<MAX_SIZE and primes[j]<=SPF[i]; j++){

                isPrime[i*primes[j]]=false;

                SPF[i*primes[j]]=primes[j];

            }

        }

    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        if(m==0)return -1;
        DisjointSet ds(n);
        for(int i=1;i<=n;i++)
        {
            for(auto x:g[i])
                ds.unionBySize(i,x);   
        }
        int s=0;
        for(int i=1;i<=n;i++)
        {
            s=max(s,ds.size[i]);
        }
        
        if(s==1) return -1;
        return primes[s-1];

    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends
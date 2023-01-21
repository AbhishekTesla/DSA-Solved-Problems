
#include<bits/stdc++.h>
using namespace std;

// Time Complexity => Elog(V) E=>Edges & V=>Vertices 
// Using Priority Queue

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int shortest_path(int node,vector<int>&parent){
        if(parent[node]==S)
        return parent[node];

        shortest_path(parent[node],parent);
        // print path
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // Priority Queue will store edgeWeight and the node {edgeWeight,Node}
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dis(V);
        vector<int>parent(V);
        for(int i=0;i<V;i++)
        parent[i]=i;
       
        for(int i=0;i<V;i++)
        dis[i]=1e9;
        
        dis[S]=0;
        
        pq.push({0,S});
        
        while(!pq.empty()){
           
            int wtg = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWtg = it[1];
                
                if(edgeWtg + wtg < dis[adjNode])
                {
                    vector<int>temp;
                    dis[adjNode] = edgeWtg+wtg;
                    pq.push({dis[adjNode],adjNode});
                    parent[adjNode]=node;
                }
                
            }

        }


        
        return dis;   
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
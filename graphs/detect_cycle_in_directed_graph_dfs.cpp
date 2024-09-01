class Solution {
  public:
  
    int dfs(int i,vector<int> adj[],vector<int>&vis,vector<int>&dfsvis){
        vis[i]=1;
        dfsvis[i]=1;
        // cout<<i<<endl;
        for(auto it:adj[i]){
            if(vis[it]==0) {if(dfs(it,adj,vis,dfsvis)) return 1;}
            else{
                if(dfsvis[it]==1) return 1;
            }
        }
        dfsvis[i]=0;
        return 0;
    }
  
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0) {if(dfs(i,adj,vis,dfsvis)) return true;}
        }
        return false;
        
    }
};

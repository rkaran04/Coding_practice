void dfs(vector<vector<int>>&graph,vector<vector<int>>&vis,int row,int col,vector<int>&dr,vector<int>&dc){
        int n=graph.size();
        int m=graph[0].size();
        vis[row][col]=1;
        ans[row][col]++;
        

        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(vis[nr][nc]==0 ) dfs(graph,vis,nr,nc,dr,dc);
        }
        return;
    }

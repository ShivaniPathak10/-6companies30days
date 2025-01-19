class Solution {
public:
    void dfs(int curr, int prev, int d, vector<int> adj[], int &maxinode, int &ans){
        if (d > ans){
            ans = d;
            maxinode = curr;
        }
        for (auto i : adj[curr]){
            if (i != prev){
                dfs(i, curr, d + 1, adj, maxinode, ans);
            }
        }
    }
    void dfs(int node,int prev,vector<int>adj2[],int &mask2){
        mask2=(mask2|(1<<(node-1)));
        for(auto it:adj2[node]){
            if(it!=prev){
                dfs(it,node,adj2,mask2);
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>res(n-1);
        for(int i=3;i<=(1<<n);i++){
            int mask=i;
            vector<int>adj2[n+1];
            int start=1;
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                if((mask&(1<<(u-1)))&&(mask&(1<<(v-1)))){
                    start=u;
                    adj2[u].push_back(v);
                    adj2[v].push_back(u);
                }
            }
            int mask2=0;
            dfs(start,-1,adj2,mask2);
            if(mask2==mask){
                int ans = 0;
                int maxinode = 0;
                
                dfs(start, -1, 0, adj2, maxinode, ans);
                dfs(maxinode, -1, 0, adj2, maxinode, ans);
                res[ans-1]++;
            }
        }
        return res;
    }
};
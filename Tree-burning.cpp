/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root,vector<int> adj[]){
        if(root==NULL){
            return ;
        }

        if(root->left){
            adj[root->val].push_back(root->left->val);\
            adj[root->left->val].push_back(root->val);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);\
            adj[root->right->val].push_back(root->val);
        }

        buildGraph(root->left,adj);
        buildGraph(root->right,adj);
    }
    int amountOfTime(TreeNode* root, int start) {
        int cnt = 0 ;
        vector<int> adj[100001] ;

        // Convert the Tree to Graph
        buildGraph(root,adj);

        // Simple Apply Breadth first search as we can directly infect the values at same 
        // level/distance from start
        vector<bool> vis(100001,false);
        queue<int> q ;
        q.push(start);
        vis[start] = true ;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();

                for(auto it:adj[node]){
                    if(!vis[it] ){
                        q.push(it);
                        vis[it] = true; 
                    }
                }
            }
            cnt++ ;
        }
        

        return cnt-1 ;
    }
};
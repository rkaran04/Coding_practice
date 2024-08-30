/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  // inorder to store parent
    void inorder(TreeNode*node,unordered_map<TreeNode*,TreeNode*>&mp){
        if(node==NULL) return ;
        // if(node->val==target) t=node;

        if(node->left){
            mp[node->left]=node;
            inorder(node->left,mp);
        }

        if(node->right){
            mp[node->right]=node;
            inorder(node->right,mp);
        }

        return;

    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;

        inorder(root,mp);

        int dist=0;
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<int,int>vis;
        vis[target->val]=1;
        while(!q.empty()){
            if(dist==k) break;
            int size=q.size();
            
            while(size--){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left && vis[temp->left->val]==0) {
                    q.push(temp->left);
                    vis[temp->left->val]=1;}

                if(temp->right && vis[temp->right->val]==0) {
                    q.push(temp->right);
                    vis[temp->right->val]=1;}

                if(mp.find(temp)!=mp.end() && vis[mp[temp]->val]==0) {
                    q.push(mp[temp]);
                    vis[mp[temp]->val]=1;
                }
                        
            }            
            dist++;
        }    
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;    
    }
};

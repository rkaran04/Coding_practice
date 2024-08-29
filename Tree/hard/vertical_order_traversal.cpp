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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,map<int,multiset<int>>>mp;

        vector<vector<int>>tree;
        if(root==NULL) return tree;

        queue<pair<TreeNode*,int>>q;
        int level=0;
        q.push({root,0});
        int mini=1e9;
        int maxi=-1e9;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front().first;
                int col=q.front().second;
                mini=min(col,mini);
                maxi=max(maxi,col);
                q.pop();
                mp[col][level].insert(temp->val);
                if(temp->left) q.push({temp->left,col-1});
                if(temp->right) q.push({temp->right,col+1});

            }
            level++;
        }

        for(int i=mini;i<=maxi;i++){
            vector<int>curr_col;
            for(auto it: mp[i]){
                for(auto num:it.second) {
                    curr_col.push_back(num);}
            }
            tree.push_back(curr_col);
        }

        return tree;
    

    }
};

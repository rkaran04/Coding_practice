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

    TreeNode* recur(vector<int>&preorder,int pl,int pr,vector<int>&inorder,int il,int ir,unordered_map<int,int>&mp){
        int root=preorder[pl];
        TreeNode*curr=new TreeNode(root);
        if(pl==pr) return curr;

        int inroot=mp[root];
        int left=inroot-il;
        int right=ir-inroot;
        
        if(left) curr->left=recur(preorder,pl+1,pl+left,inorder,il,inroot-1,mp);
        if(right) curr->right=recur(preorder,pl+left+1,pr,inorder,inroot+1,ir,mp);
        return curr;
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;

        return recur(preorder,0,n-1,inorder,0,n-1,mp);

        
    
    }
};

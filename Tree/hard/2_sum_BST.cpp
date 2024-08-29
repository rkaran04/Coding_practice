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

// this uses a bst iterator, which give us the next value in the tree just greater or smaller that current depending on the type of iterator. This question
// required a left and right pointer like in the 2 sum problem, which is facilitated by the iterators. Reverse variable is used to distinguish the iterators.
// left(starts from smallest and gets next element) one does inorder traversal basically and right(starts from the largest and gets the just smaller element)
 // one exactly opposite.

class BSTiterator{
    int reverse;
    TreeNode*root;
    stack<TreeNode*>st;
public:
    BSTiterator(int reverse,TreeNode* root){
        this->reverse=reverse;
        this->root=root;

        while(root){
            st.push(root);
            if(reverse==0) root=root->left;
            else root=root->right;
        }
    }   
    

    int getval(){
        if(st.empty()) return -1;
        TreeNode* temp=st.top();
        st.pop();
        int ans=temp->val;
        if(reverse==0){
            temp=temp->right;
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
        }
        else{
            temp=temp->left;
            while(temp){
                st.push(temp);
                temp=temp->right;
            }   
        }
        return ans;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator left=BSTiterator(0,root);  //0-->starts from smallest and gets next element
        BSTiterator right=BSTiterator(1,root);  //1-> starts from the largest and gets the just smaller element
        int l=left.getval();
        int r=right.getval();
        while(l<r){
            if(l+r==k) return true;
            if(l+r<k) l=left.getval();
            else r=right.getval();            
        }
        return false;
    }
};

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
    vector<TreeNode*> ans;
    void dfs(TreeNode* &root, unordered_set<int> &st, bool isRoot){
        if(!root) return;

        bool deleted=st.count(root->val);

        if(isRoot && !deleted) ans.push_back(root);

        dfs(root->left,st,deleted);
        dfs(root->right,st,deleted);

        if(deleted) root=nullptr;
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        dfs(root,st,true); 
        return ans; 
    }
};
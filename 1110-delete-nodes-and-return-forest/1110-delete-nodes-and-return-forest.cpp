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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        if(!root) return ans;

        queue<pair<TreeNode*,bool>> q;
        q.push({root,true});

        while(!q.empty()){
            TreeNode* node=q.front().first;
            bool parent_deleted=q.front().second;
            q.pop();

            bool deleted=st.count(node->val);

            if(parent_deleted && !deleted)  ans.push_back(node);

            if(node->left){
                bool childDeleted = st.count(node->left->val);
                q.push({node->left, deleted});
                if(childDeleted) node->left=nullptr;
            }

            if(node->right){
                bool childDeleted = st.count(node->right->val);
                q.push({node->right, deleted});
                if(childDeleted) node->right=nullptr;
            }

            if(deleted) delete node;
        }

        return ans;
    }
};
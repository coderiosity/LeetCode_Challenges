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
    
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root) return vector<vector<int>>();
        
        int h = height(root);
        vector<vector<int>> res(h);
        
        queue<TreeNode*> q;
        q.push(root);
        int curr = h-1;
        
        while(!q.empty()){
            int s = q.size();
            vector<int>t(s);
            for(int i = 0; i<s; i++){
                TreeNode* f = q.front();
                q.pop();
                
                t[i] = f->val;
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            
            res[curr] = t;
            curr--;
        }
        return res;
        
    }
};

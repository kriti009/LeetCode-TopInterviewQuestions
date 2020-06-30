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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        vector<int> t;
        bool ltr=true;
        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(root);
        // t.push_back(root->val);
        q.push(NULL);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp==NULL){
                if(q.empty())
                    break;
                if(!ltr)
                    reverse(t.begin(),t.end());
                ltr=!ltr;
                v.push_back(t);
                q.push(NULL);
                t.clear();
            }else{
                t.push_back(temp->val);
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
        }
        if(!t.empty() && !ltr)
            reverse(t.begin(),t.end());
        v.push_back(t);
        return v;
    }
};

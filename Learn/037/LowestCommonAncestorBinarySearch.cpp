#include<algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			while(root!=q && root!=p){
				if(root->val>min(p->val,q->val) && root->val<max(p->val,q->val)){
					break;
				}
				
				root=root->val>max(p->val,q->val)?root->left:root->right;
			}
			return root;
		}
};

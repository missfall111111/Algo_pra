
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
		TreeNode* trimBST(TreeNode* root, int low, int high) {
			if(root==nullptr){
				return nullptr;
			}
			
			if(root->val<low){
				if(root->right!=nullptr){
					return trimBST(root->right,low,high);
				}
				else{
					return nullptr;
				}
			}
			
			if(root->val>high){
				if(root->left!=nullptr){
					return trimBST(root->left,low,high);
				}
				else{
					return nullptr;
				}
			}
			
			if(root->right!=nullptr){
				root->right=trimBST(root->right,low,high);
			}
			
			if(root->left!=nullptr){
				root->left= trimBST(root->left,low,high);
			}
			
			return root;
			
		}
};

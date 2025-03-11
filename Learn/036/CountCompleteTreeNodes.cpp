
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
		int ldeep(TreeNode*root) {
			int cnt = 0;
			while (root != nullptr) {
				cnt++;
				root = root->left;
			}
			return cnt;
		}

		int countNodes(TreeNode* root) {
			if (root == nullptr) {
				return 0;
			}
			if (root->left == nullptr && root->right == nullptr) {
				return 1;
			}
			
			int ld=ldeep(root->left);
			int rd=ldeep(root->right);
			if(ld>rd){
				return (1<<rd)+countNodes(root->left);
			}
			else{
				return (1<<ld)+countNodes(root->right);
			}
		}
};

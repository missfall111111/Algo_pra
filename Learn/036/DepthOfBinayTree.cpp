#include <algorithm>
#include<limits>
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
		int maxDepth(TreeNode* root) {
			return root == nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
		}
		
		//最小深度，就是根节点到最上面的叶子节点的深度
		int minDepth(TreeNode* root) {
			if(root==nullptr){
				return 0;
			}
			
			if(root->left==nullptr && root->right==nullptr){
				return 1;
			}
			
			int ldeep=numeric_limits<int>::max();
			int rdeep=numeric_limits<int>::max();
			
			if(root->right!=nullptr){
				rdeep=minDepth(root->right);
			}
			
			if(root->left!=nullptr){
				ldeep=minDepth(root->left);
			}
			
			return min(ldeep,rdeep)+1;
		}
};

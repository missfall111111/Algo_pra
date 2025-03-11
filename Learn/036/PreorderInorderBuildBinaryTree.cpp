#include <vector>
#include <unordered_map>
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
		TreeNode* f(vector<int>&preorder, int l1, int r1, vector<int>&inorder, int l2, int r2, unordered_map<int, int>&InvalueIndex) {
			if(l1>r1){
				return nullptr;
			}
			TreeNode* root = new TreeNode(preorder[l1]);
			if (l1 == r1) {
				return root;
			}
			int midPos = InvalueIndex[preorder[l1]];
			root->left = f(preorder, l1 + 1, l1 + midPos-l2, inorder, l2, midPos - 1, InvalueIndex);
			root->right = f(preorder, l1 + midPos-l2+ 1, r1, inorder, midPos + 1, r2, InvalueIndex);
			return root;
		}
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			if(preorder.size()==0 || inorder.size()==0||preorder.size()!=inorder.size()){
				return nullptr;
			}
			unordered_map<int, int>InvalueIndex;
			for (int i = 0; i < inorder.size(); i++) {
				InvalueIndex[inorder[i]] = i;
			}
			return f(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, InvalueIndex);
		}
};

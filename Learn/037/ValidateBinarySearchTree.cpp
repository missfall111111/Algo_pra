#include<limits>
#include<stack>
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

//class Solution {
//	public:
//		bool isValidBST(TreeNode* root) {
//			stack<TreeNode*>stk;
//			TreeNode*pre=nullptr;
//			while(!stk.empty() || root!=nullptr){
//				if(root==nullptr){
//					root=stk.top();
//					stk.pop();
//					if(pre!=nullptr && pre->val>=root->val){
//						return false;
//					}
//					pre=root;
//					root=root->right;
//				}
//				else{
//					stk.push(root);
//					root=root->left;
//				}
//			}
//			return true;
//		}
//};


class Solution {
public:
	long x,d;
	bool isValidBST(TreeNode* root) {
		if(root==nullptr){
			x=numeric_limits<long>::max();
			d=numeric_limits<long>::min();
			return true;
		}
		
		bool lok=isValidBST(root->left);
		long lmin=x;
		long lmax=d;
		
		bool rok=isValidBST(root->right);
		long rmin=x;
		long rmax=d;
		
		x=min(min(lmin,rmin),(long)root->val);
		d=max(max(lmax,rmax),(long)root->val);
		return lok&&rok&&root->val>lmax&&root->val<rmin;
	}
};

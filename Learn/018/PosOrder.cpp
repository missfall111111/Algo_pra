#include<iostream>
#include<vector>
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


//左右中
class Solution {
	public:
		vector<int> postorderTraversal(TreeNode* root) {
			TreeNode* cur=root;
			vector<int>res;
			TreeNode* pre=NULL;
			stack<TreeNode*>s;
			
			while(cur || !s.empty()){
				while(cur){
					s.push(cur);
					cur=cur->left;
				}
				
				cur=s.top();
				if(cur->right==NULL || cur->right==pre){
					pre=cur;
					res.push_back(cur->val);
					s.pop();
					cur=NULL;
				}
				else{
					cur=cur->right;
				}
			}
			
			return res;
		}
};

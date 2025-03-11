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


//左中右
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			TreeNode* cur=root;
			stack<TreeNode*>s;
			vector<int>res;
			while(cur || !s.empty()){
				while(cur){
					s.push(cur);
					cur=cur->left;
				}
				cur=s.top();
				res.push_back(cur->val);
				s.pop();
				
				if(cur->right){
					cur=cur->right;
				}
				else{
					cur=NULL;
				}
			}
			return res;
		}
};

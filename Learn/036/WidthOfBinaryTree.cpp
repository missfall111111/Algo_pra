#include<algorithm>

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


const int MAXN=3000;
TreeNode* arr[MAXN];
int idx [MAXN];
int l=0;
int r=0;

class Solution {
	public:
		int widthOfBinaryTree(TreeNode* root) {
			int ans=1;
			arr[r]=root;
			idx[r++]=1;
			l=r=0;
			while(l!=r){
				ans=max(ans,idx[r-1]-idx[l]+1);
				int t=r-l;
				for(int i=0;i<t;i++){
					TreeNode* tar=arr[l];
					if(tar->left!=nullptr){
						arr[r]=tar->left;
						idx[r++]=idx[l]*2;
					}
					if(tar->right!=nullptr){
						arr[r]=tar->right;
						idx[r++]=idx[l]*2+1;
					}
					l++;
				}
			}
			return ans;
		}
};

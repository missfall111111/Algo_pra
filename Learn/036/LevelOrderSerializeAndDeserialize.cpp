#include <string>
#include <sstream>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			if (root == nullptr) {
				return string("");
			}
			queue<TreeNode*>q;
			ostringstream o;
			q.push(root);
			o << to_string(root->val) << " ";
			while (!q.empty()) {
				int t = q.size();
				for (int i = 0; i < t; i++) {
					TreeNode* head = q.front();
					if (head->left != nullptr) {
						q.push(head->left);
						o << to_string(head->left->val) << " ";
					} else {
						o << "# ";
					}

					if (head->right != nullptr) {
						q.push(head->right);
						o << to_string(head->right->val) << " ";
					} else {
						o << "# ";
					}

					q.pop();
				}
			}
			return o.str();
		}

		TreeNode* genNode(istringstream &i) {
			string token;
			i >> token;
			if (token == "#") {
				return nullptr;
			} else {
				return new TreeNode(stoi(token));
			}
		}
		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			if (data == "") {
				return nullptr;
			}
			istringstream i(data);
			string token;
			i >> token;
			TreeNode*root = new TreeNode(stoi(token));
			queue<TreeNode*>q;
			q.push(root);
			while (!q.empty()) {
				TreeNode*head = q.front();
				head->left = genNode(i);
				head->right = genNode(i);
				if (head->left != nullptr) {
					q.push(head->left);
				}
				if (head->right != nullptr) {
					q.push(head->right);
				}
				q.pop();
			}
			return root;
		}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

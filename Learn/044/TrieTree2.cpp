#include <iostream>
#include <unordered_map>
using namespace std;

////路径少的使用数组 多的使用map
//class Trie {
//		class TrieNode {
//			public:
//				int pass;
//				int end;
//				TrieNode* path [26];
//
//				TrieNode(int p, int e) {
//					pass = p;
//					end = e;
//					for (int i = 0; i < 26; i++) {
//						path[i] = nullptr;
//					}
//				}
//		};
//	public:
//		TrieNode* root;
//		Trie() {
//			// do intialization if necessary
//			root = new TrieNode(0, 0);
//		}
//
//		/*
//		* @param word: a word
//		* @return: nothing
//		*/
//		void insert(string &word) {
//			// write your code here
//			TrieNode* tmp = root;
//			for (const auto&ele : word) {
//				tmp->pass++;
//				if (tmp->path[ele - 'a'] == nullptr) {
//					tmp->path[ele - 'a'] = new TrieNode(0, 0);
//				}
//				tmp = tmp->path[ele - 'a'];
//			}
//			tmp->end++;
//			tmp->pass++;
//		}
//
//		/**
//		 * @param word: The word to be searched for.
//		 * @return: The number of words in the Trie that are equal to the given word.
//		 */
//		int countWordsEqualTo(string &word) {
//			// --- write your code here ---
//			TrieNode* tmp = root;
//			for (const auto&ele : word) {
//				if (tmp->path[ele - 'a'] == nullptr) {
//					return 0;
//				}
//				tmp = tmp->path[ele - 'a'];
//			}
//			return tmp->end;
//		}
//
//		/**
//		 * @param prefix: The prefix to be searched for.
//		 * @return: The words in the Trie that have the same prefix as the given word.
//		 */
//		int countWordsStartingWith(string &prefix) {
//			// --- write your code here ---
//			TrieNode* tmp = root;
//			for (const auto &ele : prefix) {
//				if (tmp->path[ele - 'a'] == nullptr) {
//					return 0;
//				}
//				tmp = tmp->path[ele - 'a'];
//			}
//			return tmp->pass;
//		}
//
//		/**
//		 * @param word: The word to be removed.
//		 * @return: nothing
//		 */
//		void erase(string &word) {
//			// --- write your code here ---
//			if (countWordsEqualTo(word) != 0) {
//				TrieNode* tmp = root;
//				for (const auto &ele : word) {
//					tmp->pass--;
//					if (tmp->path[ele - 'a']->pass - 1 == 0) {
//						delete (tmp->path[ele - 'a']);
//						tmp->path[ele - 'a'] = nullptr;
//						return;
//					}
//					tmp = tmp->path[ele - 'a'];
//				}
//				tmp->pass--;
//				tmp->end--;
//			}
//
//		}
//};


//使用map
//class Trie {
//		class TrieNode {
//			public:
//				int pass;
//				int end;
//				unordered_map<char, TrieNode*>pathNode;
//
//				TrieNode(int p, int e) {
//					pass = p;
//					end = e;
//					pathNode = unordered_map<char, TrieNode*>();
//				}
//		};
//	public:
//		/**
//		 * @param word: The string to be inserted into the Trie.
//		 * @return: nothing
//		 */
//		TrieNode*root ;
//		Trie() {
//			root = new TrieNode(0, 0);
//		}
//		void insert(string &word) {
//			// --- write your code here ---
//			TrieNode* tmp = root;
//			for (const auto &ele : word) {
//				tmp->pass++;
//				if (tmp->pathNode.count(ele) == 0) {
//					tmp->pathNode[ele] = new TrieNode(0, 0);
//				}
//				tmp = tmp->pathNode[ele];
//			}
//			tmp->pass++;
//			tmp->end++;
//		}
//
//		/**
//		 * @param word: The word to be searched for.
//		 * @return: The number of words in the Trie that are equal to the given word.
//		 */
//		int countWordsEqualTo(string &word) {
//			// --- write your code here ---
//			TrieNode*tmp = root;
//			for (const auto &ele : word) {
//				if (tmp->pathNode.count(ele) == 0) {
//					return 0;
//				}
//				tmp = tmp->pathNode[ele];
//			}
//			return tmp->end;
//		}
//
//		/**
//		 * @param prefix: The prefix to be searched for.
//		 * @return: The words in the Trie that have the same prefix as the given word.
//		 */
//		int countWordsStartingWith(string &prefix) {
//			// --- write your code here ---
//			TrieNode*tmp = root;
//			for (const auto &ele : prefix) {
//				if (tmp->pathNode.count(ele) == 0) {
//					return 0;
//				}
//				tmp = tmp->pathNode[ele];
//			}
//			return tmp->pass;
//		}
//
//		/**
//		 * @param word: The word to be removed.
//		 * @return: nothing
//		 */
//		//c++析构一个东西是挺麻烦的
//		void erase(string &word) {
//			// --- write your code here ---
//			if (countWordsEqualTo(word) != 0) {
//				TrieNode*tmp = root;
//				for (const auto &ele : word) {
//					tmp->pass--;
//					if (tmp->pathNode[ele]->pass - 1 == 0) {
//						tmp->pathNode.erase(ele);
//						return;
//					}
//					tmp = tmp->pathNode[ele];
//				}
//				tmp->pass--;
//				tmp->end--;
//			}
//		}
//};

const int MAXN = 1000000;

int NodePath[MAXN][26];
int pass[MAXN];
int end1[MAXN];
int cnt = 1;
/**
 * @param word: The string to be inserted into the Trie.
 * @return: nothing
 */
void insert(string &word) {
	// --- write your code here ---
	int cur = 1;
	for (const auto &ele : word) {
		pass[cur]++;
		int p = ele - 'a';
		if (NodePath[cur][p] == 0) {
			NodePath[cur][p] = ++cnt;
		}
		cur = NodePath[cur][p];
	}
	pass[cur]++;
	end1[cur]++;
}

/**
 * @param word: The word to be searched for.
 * @return: The number of words in the Trie that are equal to the given word.
 */
int countWordsEqualTo(string &word) {
	// --- write your code here ---
	int cur = 1;
	for (const auto &ele : word) {
		int p = ele - 'a';
		if (NodePath[cur][p] == 0) {
			return 0;
		}
		cur = NodePath[cur][p];
	}
	return end1[cur];
}

/**
 * @param prefix: The prefix to be searched for.
 * @return: The words in the Trie that have the same prefix as the given word.
 */
int countWordsStartingWith(string &prefix) {
	// --- write your code here ---
	int cur = 1;
	for (const auto &ele : prefix) {
		int p = ele - 'a';
		if (NodePath[cur][p] == 0) {
			return 0;
		}
		cur = NodePath[cur][p];
	}
	return pass[cur];
}

/**
 * @param word: The word to be removed.
 * @return: nothing
 */
void erase(string &word) {
	// --- write your code here ---
	int cur = 1;
	for (const auto &ele : word) {
		pass[cur]--;
		int p = ele - 'a';
		if (pass[NodePath[cur][p]] - 1 == 0) {
			NodePath[cur][p] = 0;
			return;
		}
		cur = NodePath[cur][p];
	}
	end1[cur]--;
	pass[cur]--;
}
int n;
int op;
string opor;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	while (n--) {
		cin >> op >> opor;
		if (op == 1) {
			insert(opor);
		} else if (op == 2) {
			erase(opor);
		} else if (op == 3) {
			if (countWordsEqualTo(opor) != 0) {
				cout << "YES" << "\n";
			} else {
				cout << "NO" << "\n";
			}
		} else {
			cout << countWordsStartingWith(opor) << "\n";
		}
	}
}
// 64 位输出请用 printf("%lld")

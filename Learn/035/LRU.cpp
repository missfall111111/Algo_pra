#include <unordered_map>
#include <iostream>
using namespace std;
class LRUCache {
	public:
		class DoubleNode {
			public:
				DoubleNode* pre;
				DoubleNode* next;
				int key;
				int value;
				DoubleNode(int k, int v) {
					key = k;
					value = v;
					pre = next = nullptr;
				}
		};

		class DoubleNodeList {
			public:
				DoubleNode*head;
				DoubleNode*tail;
				DoubleNodeList() {
					head = tail = nullptr;
				}

				//把列表中存在的一个节点移到末尾
				void MoveToTail(DoubleNode*n) {
					if (n == tail) {
						return;
					}
					if (n == head) {
						head = head->next;
						head->pre = nullptr;
					} else {
						n->pre->next = n->next;
						n->next->pre = n->pre;
					}
					tail->next = n;
					n->pre = tail;
					n->next = nullptr;
					tail = n;
				}

				//队列满了，删去头节点
				DoubleNode* RemoveHead() {
					DoubleNode*ans = head;
					if (head == tail) {
						head = nullptr;
						tail = nullptr;
					} else {
						head = head->next;
						head->pre = nullptr;
						ans->next = nullptr;
					}
					return ans;
				}

				//把一个新来的节点放到最后
				void AddNode(DoubleNode*n) {
					if (head == nullptr) {
						head = tail = n;
					} else {
						tail->next = n;
						n->pre = tail;
						tail = n;
					}
				}
		};

		unsigned int cap;
		unordered_map<int, DoubleNode*> map;
		DoubleNodeList nodeList;
		LRUCache(int capacity) {
			cap = capacity;
			nodeList = DoubleNodeList();
		}

		int get(int key) {
			if (map.count(key)) {
				DoubleNode*n = map[key];
				nodeList.MoveToTail(n);
				return n->value;
			} else {
				return -1;
			}
		}

		void put(int key, int value) {
			if (map.count(key)) {
				DoubleNode* node = map[key];
				node->value = value;
				nodeList.MoveToTail(node);

			} else {
				if (map.size() == cap) {
					map.erase(nodeList.RemoveHead()->key);
				}
				DoubleNode* n = new DoubleNode(key, value);
				map[key] = n;
				nodeList.AddNode(n);
			}
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {
	LRUCache a = LRUCache(2);
	a.put(1, 1);
	a.put(2, 2);
	cout << a.get(1);
	a.put(3, 3);
	cout << a.get(2);
	a.put(4, 4);
	cout << a.get(1);
	cout << a.get(3);
	cout << a.get(4);
	return 0;
}

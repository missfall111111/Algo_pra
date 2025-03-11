#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* partition(ListNode* head, int x) {
			ListNode* LeftHead = NULL, *LeftTail = NULL, *RightHead = NULL, *RightTail = NULL;
			ListNode* next = head;
			while (head != NULL) {
				next = head->next;
				if (head->val < x) {
					if (LeftHead == NULL) {
						LeftHead = head;
						LeftTail = head;
					} else {
						LeftTail->next = head;
						LeftTail = LeftTail->next;
					}
					LeftTail->next = NULL;
				} else {
					if (RightHead == NULL) {
						RightHead = head;
						RightTail = head;
					} else {
						RightTail->next = head;
						RightTail = RightTail->next;
					}
					RightTail->next = NULL;
				}
				head = next;
			}
			if (!LeftTail) {
				return RightHead;
			} else {
				LeftTail->next = RightHead;
			}
			return LeftHead;
		}
};

int main() {
	return 0;
}

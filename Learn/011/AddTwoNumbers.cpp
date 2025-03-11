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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode * head = NULL;
			ListNode* cur = NULL;
			bool c = false;
			int res;
			while (l1 != NULL || l2!= NULL) {
				res = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);
				if (c) {
					res++;
					c = false;
				}
				if (res >= 10) {
					res = res % 10;
					c = true;
				}
				if (head == NULL) {
					head = new ListNode(res, NULL);
					cur = head;
				} else {
					cur->next = new ListNode(res, NULL);
					cur = cur->next;
				}
				
				if(l1!=NULL){
					l1=l1->next;
				}
				if(l2!=NULL){
					l2=l2->next;
				}
			}
			if(c){
				cur->next=new ListNode(1,NULL);
			}
			return head;
		}
};


int main() {
	return 0;
}

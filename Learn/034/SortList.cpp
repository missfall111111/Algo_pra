#include<iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* start;
		ListNode* end;

		//r1 r2的末尾为null  l1 r1   l2 r2 本身有序
		void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2) {
			ListNode* pre = nullptr;
			if (l1->val < l2->val) {
				pre = l1;
				start = l1;
				l1 = l1->next;
			} else {
				pre = l2;
				start = l2;
				l2 = l2->next;
			}

			while (l1 != nullptr && l2 != nullptr) {
				if (l1->val < l2->val) {
					pre->next = l1;
					pre = l1;
					l1 = l1->next;
				} else {
					pre->next = l2;
					pre = l2;
					l2 = l2->next;
				}
			}

			if (l1 != nullptr) {
				pre->next = l1;
				end = r1;
			} else {
				pre->next = l2;
				end = r2;
			}
		}
		//返回s开头的k个节点的结尾，若最后少于k个，直接返回最后的节点
		ListNode* getEnd(ListNode* s, int k) {
			while (s->next != nullptr && --k != 0) {
				s = s->next;
			}
			return s;
		}
		ListNode* sortList(ListNode* head) {
			int n = 0;
			ListNode*cur = head;
			while (cur != nullptr) {
				n++;
				cur = cur->next;
			}

			ListNode* l1;
			ListNode* l2;
			ListNode* r1;
			ListNode* r2;
			ListNode* next;
			ListNode* latEnd;

			for (int step = 1; step < n; step <<= 1) {
				l1 = head;
				r1 = getEnd(l1, step);
				l2 = r1->next;
				r2 = getEnd(l2, step);

				next = r2->next;
				r1->next = nullptr;
				r2->next = nullptr;
				merge(l1, r1, l2, r2);
				head = start;
				latEnd = end;
				while (next != nullptr) {
					l1 = next;
					r1 = getEnd(l1, step);
					l2 = r1->next;
					if (l2 == nullptr) {
						latEnd->next= l1;
						break;
					}
					r2 = getEnd(l2, step);
					next = r2->next;
					r1->next = nullptr;
					r2->next = nullptr;
					merge(l1, r1, l2, r2);
					latEnd->next = start;
					latEnd = end;
				}
			}
			return head;
		}
};

int main(){
	ListNode*a=new ListNode(-1);
	ListNode*b=new ListNode(5);
	ListNode*c=new ListNode(3);
	ListNode*d=new ListNode(4);
	ListNode*e=new ListNode(0);
	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	
	Solution s=Solution();
	a=s.sortList(a);
	while(a!=nullptr){
		cout<<a->val<<"\n";
		a=a->next;
	}
	return 0;
}

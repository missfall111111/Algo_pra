#include <iostream>
#include<unordered_set>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//class Solution {
//	public:
//		ListNode *detectCycle(ListNode *head) {
//			if(head==nullptr || head->next==nullptr ||head->next->next==nullptr){
//				return nullptr;
//			}
//			ListNode*f = head->next->next;
//			ListNode*s = head->next;
//			while (f != s) {
//				if (f->next == nullptr || f->next->next == nullptr) {
//					return nullptr;
//				}
//				f = f->next->next;
//				s = s->next;
//			}
//
//			f = head;
//			while (s != f) {
//				f = f->next;
//				s = s->next;
//			}
//			return s;
//		}
//};

//使用容器
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode*>s;
		ListNode*t=head;
		while(t!=nullptr){
			if(s.count(t)){
				return t;
			}
			s.emplace(t);
			t=t->next;
		}
		
		return nullptr;
	}
};

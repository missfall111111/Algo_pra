#include<iostream>
#include<unordered_set>
#include<cstdlib>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


////使用容器
//class Solution {
//	public:
//		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//			unordered_set<ListNode*> A;
//			ListNode* t=headA;
//			while(t!=nullptr){
//				A.insert(t);
//				t=t->next;
//			}
//			t=headB;
//			while(t!=nullptr){
//				if(A.count(t)){
//					return t;
//				}
//				t=t->next;
//			}
//			
//			return nullptr;
//		}
//};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA==nullptr || headB==nullptr){
			return nullptr;
		}
		ListNode*a=headA;
		ListNode*b=headB;
		int l=0;
		
		while(a!=nullptr){
			l++;
			a=a->next;
		}
		
		while(b!=nullptr){
			l--;
			b=b->next;
		}
		
		//a是较长的链
		if(l>0){
			a=headA;
			b=headB;
		}
		else{
			a=headB;
			b=headA;
		}
		
		l=abs(l);
		while(l--!=0){
			a=a->next;
		}
		
		while(a!=b){
			a=a->next;
			b=b->next;
		}
		
		return a;
	}
};

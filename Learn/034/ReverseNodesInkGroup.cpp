#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//使用数组容器 反转
//class Solution {
//	public:
//		ListNode* reverseKGroup(ListNode* head, int k) {
//			vector<ListNode*> c;
//			ListNode*t=head;
//			while(t!=nullptr){
//				c.push_back(t);
//				t=t->next;
//			}
////			cout<<"size="<<c.size()<<"\n";
//			for(unsigned int i=0;i<c.size();i+=k){
//				unsigned int s=i;
//				unsigned int e=i+k-1;
//				if(e>=c.size()){
//					break;
//				}
//				
//				while(s<=e){
//					swap(c[s],c[e]);
//					s++;e--;
//				}
//			}
//			head=c[0];
//			for(unsigned int i=0;i<c.size();i++){
//				cout<<c[i]->val;
//			}
//			for(unsigned int i=0;i<c.size();i++){
//				if(i+1<c.size()){
//					c[i]->next=c[i+1];
//				}
//				else{
//					c[i]->next=nullptr;
//				}
//			}
//			return head;
//		}
//};

class Solution {
public:
	ListNode* getEnd(ListNode*head,int k){
		ListNode*res=head;
		for(int i=0;i<k-1;i++){
			if(res==nullptr){
				return nullptr;
			}
			res=res->next;
		}
		return res;
	}
	
	void reverse(ListNode*s,ListNode*e){
		e=e->next;
		ListNode*pre=nullptr;ListNode*cur=s;ListNode*next=nullptr;
		while(cur!=e){
			next=cur->next;
			cur->next=pre;
			pre=cur;
			cur=next;
		}
		s->next=e;
	}
	
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode*s=head;
		ListNode*e=getEnd(s,k);
		
		if(e==nullptr){
			return s;
		}
		
		reverse(s,e);
		head=e;
		ListNode* lastEnd=s;
		
		while(lastEnd->next!=nullptr){
			s=lastEnd->next;
			e=getEnd(s,k);
			if(e==nullptr){
				return head;
			}
			reverse(s,e);
			lastEnd->next=e;
			lastEnd=s;
		}
		return head;
	}
};

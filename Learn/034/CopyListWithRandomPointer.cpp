#include<iostream>
#include<unordered_map>
using namespace std;
// Definition for a Node.
class Node {
	public:
		int val;
		Node* next;
		Node* random;

		Node(int _val) {
			val = _val;
			next = NULL;
			random = NULL;
		}
};

//使用容器
//class Solution {
//	public:
//		Node* copyRandomList(Node* head) {
//			unordered_map<Node*,Node*> m;
//			Node*t=head;
//			while(t!=nullptr){
//				Node* a=new Node(t->val);
//				m[t]=a;
//				t=t->next;
//			}
//			t=head;
//			while(t!=nullptr){
//				m[t]->next=m[t->next];
//				m[t]->random=m[t->random];
//				t=t->next;
//			}
//			return m[head];
//		}
//};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if(head==nullptr){
			return nullptr;
		}
		Node*cur=head;Node*next=nullptr;
		while(cur!=nullptr){
			next=cur->next;
			cur->next=new Node(cur->val);
			cur->next->next=next;
			cur=next;
		}
		
		cur=head;
		Node*cp=nullptr;
		Node*res=head->next;
		while(cur!=nullptr){
			cp=cur->next;
			next=cur->next->next;
			cp->random=cur->random==nullptr?nullptr:cur->random->next;
			cur=next;
		}
		
		cur=head;
		while(cur!=nullptr){
			cp=cur->next;
			next=cur->next->next;
			cur->next=next;
			cp->next=next==nullptr?nullptr:next->next;
			cur=next;
		}
		return res;
	}
};

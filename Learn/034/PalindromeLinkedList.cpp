#include <stack>
using namespace std;
//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

////使用容器
//class Solution {
//	public:
//		bool isPalindrome(ListNode* head) {
//			ListNode* t=head;
//			stack<ListNode*>s;
//			while(t!=nullptr){
//				s.push(t);
//				t=t->next;
//			}
//			t=head;
//			while(!s.empty()){
//				if(t->val!=s.top()->val){
//					return false;
//				}
//				s.pop();
//				t=t->next;
//			}
//			return true;
//		}
//};


//快慢指针找中点
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode*s=head;ListNode*f=head;
		while(f->next!=nullptr && f->next->next!=nullptr){
			s=s->next;
			f=f->next->next;
		}
		
		ListNode*pre=s;ListNode*cur=s->next;ListNode*next=nullptr;
		pre->next=nullptr;
		while(cur!=nullptr){
			next=cur->next;
			cur->next=pre;
			pre=cur;
			cur=next;
		}
		
		bool ans=true;
		ListNode*l=head;ListNode*r=pre;
		while(l!=nullptr && r!=nullptr){
			if(l->val!=r->val){
				ans=false;
			}
			l=l->next;
			r=r->next;
		}
		cur=pre->next;
		pre->next=nullptr;
		next=nullptr;
		while(cur!=nullptr){
			next=cur->next;
			cur->next=pre;
			pre=cur;
			cur=next;
		}
		return ans;
	}
};

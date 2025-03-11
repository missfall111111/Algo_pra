#include<iostream>

using namespace std;
//https://leetcode.com/problems/reverse-linked-list/
//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};


//反转一个单链表需要两个额外变量
//双链表基本一样，也是pre、next两个变量
class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			ListNode*next=NULL,*pre=NULL;
			
			while(head!=NULL){
				next=head->next;
				head->next=pre;
				pre=head;
				head=next;
			}
			return pre;
		}
};

int main(){
	
}

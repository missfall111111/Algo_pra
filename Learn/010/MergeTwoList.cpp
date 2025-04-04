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

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			if(list1==NULL || list2==NULL){
				return list1==NULL?list2:list1;
			}
			
			ListNode* head=list1->val<=list2->val?list1:list2;
			ListNode* cur1=head->next;
			ListNode* cur2=list1==head?list2:list1;
			ListNode* pre=head;
			
			while(cur1!=NULL && cur2!=NULL){
				if(cur1->val<=cur2->val){
					pre->next=cur1;
					cur1=cur1->next;
				}
				else{
					pre->next=cur2;
					cur2=cur2->next;
				}
				
				pre=pre->next;
			}
			
			if(cur1==NULL){
				pre->next=cur2;
			}
			else{
				pre->next=cur1;
			}
			
			return head;
		}
};

int main(){
	
	return 0;
}

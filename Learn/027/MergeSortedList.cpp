#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct Comparator{
	bool operator()(ListNode*a,ListNode*b){
		return a->val>b->val;
	}
};
class Solution {
	public:
		/**
		 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
		 *
		 *
		 * @param lists ListNode类vector
		 * @return ListNode类
		 */
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			// write code here
			priority_queue<ListNode*,vector<ListNode*>,Comparator> smallHeap;
			for(const auto& list:lists){
				if(list!=NULL){
					smallHeap.push(list);
				}
			
			}
			
			ListNode*head=NULL;
			ListNode*p=head;
			while(!smallHeap.empty()){
				ListNode* tmp=smallHeap.top();
				smallHeap.pop();
				if(tmp->next!=NULL){
					smallHeap.push(tmp->next);
				}
				if(head==NULL){
					head=p=tmp;
				}
				else{
					p->next=tmp;
					p=p->next;
				}
			}
			if(p!=NULL){
				p->next=NULL;
			}
			return head;
		}
};

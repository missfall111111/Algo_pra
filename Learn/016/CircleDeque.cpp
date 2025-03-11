#include<iostream>

using namespace std;

//循环双端队列
class MyCircularDeque {
private:
	int l,r,size,limit;
	int *arr;
public:
	MyCircularDeque(int k) {
		l=r=size=0;
		limit=k;
		arr=new int[k];
	}
	
	bool insertFront(int value) {
		if(isFull()){
			return false;
		}
		else{
			if(isEmpty()){
				l=r=0;
				arr[l]=value;
			}
			else{
				l=l==0?limit-1:l-1;
				arr[l]=value;
				
			}
			size++;
			return true;
		}
	}
	
	bool insertLast(int value) {
		if(isFull()){
			return false;
		}
		else{
			if(isEmpty()){
				l=r=0;
				arr[r]=value;
			}
			else{
				r=(r+1)%limit;
				arr[r]=value;
			}
			size++;
			return true;
		}
	}
	
	bool deleteFront() {
		if(isEmpty()){
			return false;
		}
		else{
			l=l==limit-1?0:l+1;
		}
		size--;
		return true;
	}
	
	bool deleteLast() {
		if(isEmpty()){
			return false;
		}
		else{
			r=r==0?limit-1:r-1;
		}
		size--;
		return  true;
	}
	
	int getFront() {
		if(isEmpty()){
			return -1;
		}
		return arr[l];
	}
	
	int getRear() {
		if(isEmpty()){
			return -1;
		}
		return arr[r];
	}
	
	bool isEmpty() {
		return size==0;
	}
	
	bool isFull() {
		return size==limit;
	}
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

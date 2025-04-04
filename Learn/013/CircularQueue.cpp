class MyCircularQueue {
private:
	int *arr;
	int front;
	int rear;
	int size;
	int limit;
public:
	MyCircularQueue(int k) {
		arr=new int[k];
		front=rear=size=0;
		limit=k;
	}
	
	bool enQueue(int value) {
		if(isFull()){
			return false;
		}
		else{
			arr[rear]=value;
			rear=(rear+1)%limit;
			size++;
			return true;
		}
	}
	
	bool deQueue() {
		if(isEmpty()){
			return false;
		}
		else{
			front=(front+1)%limit;
			size--;
			return true;
		}
	}
	
	int Front() {
		if(isEmpty()){
			return -1;
		}
		else{
			return arr[front];
		}
	}
	
	int Rear() {
		if(isEmpty()){
			return -1;
		}
		else{
			int pos=rear==0?limit-1:rear-1;
			return arr[pos];
		}
	}
	
	bool isEmpty() {
		return size==0;
	}
	
	bool isFull() {
		return size==limit;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

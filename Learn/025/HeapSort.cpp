#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN =100000;
int arr[MAXN];
int n;

//从数组的i位置向上比较调整
void heapInsert(int i){
	while(arr[i]>arr[(i-1)/2]){
		//TODO
		swap(arr[i],arr[(i-1)/2]);
		i=(i-1)/2;
	}
}

//以i位置的节点为树根，向下调整堆化
void heapify(int i,int size){
	int l=i*2+1;
	while(l<size){
		int b=l+1<size&&arr[l+1]>arr[l]?l+1:l;
		b=arr[b]>arr[i]?b:i;
		if(b==i){
			break;
		}
		swap(arr[i],arr[b]);
		i=b;
		l=i*2+1;
	}
}
void heapSort1(){
	for(int i=0;i<n;i++){
		heapInsert(i);     //自顶向下建堆
	}
	
	int size=n;
	while(size-1!=0){
		//TODO
		swap(arr[0],arr[size-1]);
		size--;
		heapify(0,size);
	}
}
void heapSort2(){
	for(int i=n-1;i>=0;i--){  //自底向上建堆
		heapify(i,n);
	}
	int size=n;
	while(size-1!=0){
		//TODO
		swap(arr[0],arr[size-1]);
		size--;
		heapify(0,size);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	heapSort2();
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

#include<iostream>

using namespace std;


//交换数字arr中i位置和j位置的元素
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

//n表示数组中元素的个数
void selectionSort(int arr[],int n){
	if(arr==NULL || n<2){
		return;
	}
	
	for(int minIndex,i=0;i<n-1;i++){
		minIndex=i;
		for(int j=i+1;j<n-1;j++){
			if(arr[j]<arr[minIndex]){
				minIndex=j;
			}
		}
		swap(arr,minIndex,i);
	}
}

void bubbleSort(int arr[],int n){
	if(arr==NULL || n<2){
		return;
	}
	//每轮把最大的元素冒在最后的end的位置
	for(int end=n-1;end>0;end--){
		for(int i=0;i<end;i++){
			if(arr[i]>arr[i+1]){
				swap(arr,i,i+1);
			}
		}
	}
}
void insertSort(int arr[],int n){
	if(arr==NULL || n<2){
		return ;
	}
	
	//当i=x(x<n)的这一轮完成了，数组的索引0-x+1的闭区间是有序的
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0&&arr[j]>arr[j+1];j--){
			swap(arr,j,j+1);
		}
	}
}

void printArr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr1[]={5,2,4,1,6};
	int arr2[]={5,6,1,3,6};
	int arr3[]={7,3,1,4,2};
	
	cout<<"Before:"<<endl;
	printArr(arr1,5);
	printArr(arr2,5);
	printArr(arr3,5);
	
	selectionSort(arr1,5);
	bubbleSort(arr2,5);
	insertSort(arr3,5);
	
	cout<<"Now:"<<endl;
	printArr(arr1,5);
	printArr(arr2,5);
	printArr(arr3,5);
	
	return 0;
}

# 堆结构
1. 任意节点的父节点 （i-1)/2
2. 任意节点的左孩子 i*2+, 任意节点的右孩子 i*2+2
3. 堆的分类：大根堆（对于任意子树，父节点最大，根节点为全局最大）；小根堆（对于任意子树，父节点最小，根节点全局最小)
4. 堆的调整：heapInsert(从树的末尾插入，自底向上调整）；heapify（根节点的元素被换走了，自顶向下调整）。 都是log N的复杂度

# 堆排序
1. 自顶向下建堆:将无序的元素按索引顺序heapInsert建堆（这里建堆体现自顶向下），再循环把堆顶元素与最后的元素交换，减小size,heapify.
2. 自底向上建堆:将无序的元素按反索引顺序heapify建堆（这里建堆体现自底向上），再顺寻把堆顶元素与最后的元素交换，减小size,heapify.
3. 都是n*log n的复杂度


# 易错的地方
1. heapify的while条件 while(arr[i]>arr[(i-1)/2])很正确。整数相除的结果是向0靠近的
2. 最后交换头尾，应该先size--再heapify(i,size)
3. 自底向上建堆的条件 for(int i=n-1;i>=0;i--)

# STL
在c/c++里,堆是proiroty_queue。，默认是大根堆

注意c/c++里面的什么比较器，lambda匿名函数的编写

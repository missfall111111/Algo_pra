#三个排序算法

##选择排序

从小到大，每次选择最小/最大的值到当前i位置。[0,i-1]的闭区间是有序的。


##冒泡排序

n的数字就是n-1轮，就是end从n-1到1的过程。每一轮把最小/最大的值冒到当前end的位置。[end+1,end]总是有序的。


##插入排序

[0,i-1]的位置总是有序的。每一轮把[0,i]这个区间弄有序，同j=i-1和j+1比较。条件j>=0&&j大于或者小于j+1,j--。


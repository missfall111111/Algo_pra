# 二维前缀和 二维差分 离散化技巧

1. 二维前缀和:计算得到另一个矩阵，其[i,j]的值等于原矩阵[0,0]为左上角,[i,j]为右下角的累加和,原理可以使用容斥原理推导。

数字只是离散的数字，但是矩形是有真实长度的，这怎么想很重要，就像你之前想不明白通过扩大数组容量来避免边界讨论一样。
2. 二维差分:在一个矩阵左上角为[a,b],右下角为[c,d]的矩形范围内全部加上一个值x。

# 关于离散化处理
我认为很重要的一个点是，题目的结果不在数据的绝对的值，而在于数据的值之前的相对关系。
根据这个相对关系，你就可以做出像哈希表那样的对应，从而减少空间开支。
尤其是坐标系这样的场景，应该经常需要离散化来适用于二维数组

# 关于Debug：需要构建一套完备的Debug检查体系
1. 变量名有无写错 检查。


# 关于二维数组与数学的坐标系
1. 你需要把坐标系的一个点看作二维数组里的一个格子。你在坐标系，你就只看见了点；你在二维数组，你就只看见格子。不要在一个的地方用另一个地方的逻辑，那就混乱了。
2. 把坐标系里的点，也许通过离散化，转换为全部是非负数的坐标。还需注意，二维数组是朝向右下角的，但是坐标系里的非负数区域朝向坐上角的区域

警惕填函数风格的vector,他的size可以超过int,但是你拿int接受

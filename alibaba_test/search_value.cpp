/*
3.25第二题

给出一个二维矩阵，这个矩阵的每一行和每一列都是一个独立的等差数列，
其中一些数据缺失了，现在需要推理隐藏但是可以被唯一确定的数字，然后对输入的查询进行回答。

输入描述：
第一行，n,m,q分别表示矩阵的行数，列数和查询的条数。
接下来的n行，每行m个数表示这个矩阵，0表示缺失数据。−109≤Aij≤109-10^9≤A_{ij}≤10^9−10 
9
 ≤A 
ij
​	
 ≤10 
9
 
接下来q行，每行两个数字i,j表示对矩阵中第i行第j列的数字进行查询。

输出描述：
如果可以确定该位置的数字，则输出数字，如果不能确定则输出UNKNOWN。

输入示例：
2 3 6
1 0 3
0 0 0
1 1
1 2
1 3
2 1
2 2
2 3

输出示例：
1
2
3
Unknown
Unknown
Unknown
*/

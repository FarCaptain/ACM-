>51nod 1276   


**题目描述**  
有N个岛连在一起形成了一个大的岛屿，如果海平面上升超过某些岛的高度时，则这个岛会被淹没。原本的大岛屿则会分为多个小岛屿，如果海平面一直上升，则所有岛都会被淹没在水下。
给出N个岛的高度。然后有Q个查询，每个查询给出一个海平面的高度H，问当海平面高度达到H时，海上共有多少个岛屿。例如：
岛屿的高度为：{2, 1, 3, 2, 3}, 查询为：{0, 1, 3, 2}。
当海面高度为0时，所有的岛形成了1个岛屿。
当海面高度为1时，岛1会被淹没，总共有2个岛屿{2} {3, 2, 3}。
当海面高度为3时，所有岛都会被淹没，总共0个岛屿。
当海面高度为2时，岛0, 1, 3会被淹没，总共有2个岛屿{3} {3}。


**Input**

第1行：2个数N, Q中间用空格分隔，其中N为岛的数量，Q为查询的数量(1 <= N, Q <= 50000)。
第2 - N + 1行，每行1个数，对应N个岛屿的高度(1 <= A[i] <= 10^9)。
第N + 2 - N + Q + 1行，每行一个数，对应查询的海平面高度(1 <= Q[i] <= 10^9)。


**Output**

输出共Q行，对应每个查询的岛屿数量。

> 5 4  
2  
1  
3  
2  
3  
0  
1  
3  
2  

>1  
2  
0  
2  


_________

这道题非常有趣，好题。
数的范围非常大，标记数组GG；

查询次数非常多，N\*Q就别想了；
那……排序？
发现了吗，如果从小到大查询，那么岛屿的数量是线性变化的。那么将岛屿与查询分别排序，当然，要记下下标。然后可以看成一个dp的过程。
对于每一个被淹没的岛屿，讨论两侧岛屿是否被淹没，计算岛屿的增减。




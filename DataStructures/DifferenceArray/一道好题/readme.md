不知道是哪里的题……
> 给定数字串a1~an，每次可以使用如下操作：
> 选择一个数i, range(2,n-1)，将 `ai` 变成  `ai+1 + ai-1 - ai` ，问经过任意多次操作，该数列数字总和最小为多少。

这题，乍一看，线段树嘛，沙比题。。哎不太对，这怎么修改，难道枚举吗。
考虑差分数组，`fi = ai - ai-1` ，`fi+1 = ai+1 - ai`，操作完，`fi = ai+1 - ai` , `fi+1 = ai - ai-1`。嗯？相当于把差分数组相邻两项交换！

	
又由于 `sum[x] =  sum(1->x) {f_i * (x-i+1)}` ,那么就将差分数组升序排序，然后求sum[n]就好。


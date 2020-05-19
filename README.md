# 滑动窗口问题

- 思路：

保证右指针每次往前移动一格，每次移动都会有新的一个元素进入窗口，这时条件可能就会发生改变，然后根据当前条件来决定左指针是否移动，以及移动多少格

- 模板如下：
```
int slidingWindowTemplate(string s) {

	//输入参数有效性判断
	if (...) {
		...
	}

	//申请一个散列，用于记录窗口中具体元素的个数情况
	unordered_set<char>hash;	//如果是判断是否重复的问题，也可以这样做int hash[256] = {0}; ，Ascill码的总数是256个
	

	//预处理（可省略），一般情况下是改变hash

	//l 表示左指针
	//count 记录当前的条件，具体根据题目要求定义
	//result 存放结果

	int l = 0, count = ..., result = ...,
		for (int r = 0; r < s.size(0; r++) {
			//更新元素在哈希表中的数量
			hash[s[r]]--; //hash[s[r]]++

				// 根据窗口的变更结果来改变条件值
				if (hash[s[r]] == ...) {
					count++;
				}

			// 如果当前条件不满足，移动左指针直至条件满足为止
			while (count > K || ...) {
				...
					if (...) {
						count--;
					}
				hash[A[l]]++; //滑动左窗口
				l++; //滑动左窗口
			}

			// 更新结果
			results = ...
		}
	return results;
}
```

- 例题：

[3.无重复字符的最长子串](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E9%97%AE%E9%A2%98/3.%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2.cpp)
</br>
[438. 找到字符串中所有字母异位词](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E9%97%AE%E9%A2%98/438.%20%E6%89%BE%E5%88%B0%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E6%89%80%E6%9C%89%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.cpp)

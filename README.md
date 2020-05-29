# 一、滑动窗口问题

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
</br>
[76.最小覆盖子串](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E9%97%AE%E9%A2%98/76.%20%E6%9C%80%E5%B0%8F%E8%A6%86%E7%9B%96%E5%AD%90%E4%B8%B2.cpp)
</br>
[567.字符串的排列](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E9%97%AE%E9%A2%98/567.%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%8E%92%E5%88%97.cpp)
</br>
[992. K 个不同整数的子数组](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E9%97%AE%E9%A2%98/992.%20K%20%E4%B8%AA%E4%B8%8D%E5%90%8C%E6%95%B4%E6%95%B0%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.cpp)

----
# 二、搜索问题
- 思路：1.函数调用方式实现的DFS；2.使用栈实现的DFS；3.使用队列实现的BFS

- 模板1 :
```
class Solution_695_dfs {
	int dfs(vector<vector<int>> &grid, int cur_i, int cur_j) {
		//递归基:搜索到的点是0，或者达到边界，退回，重新探索其他方向 
		//这个地方一定要先判断边界，否则判断是否为土地会越界grid[cur_i][cur_j]
		if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
			return 0;
		grid[cur_i][cur_j] = 0; //每个网格只被探索一次

								//往右走，往左走，往下走，往上走
		int di[4] = { 0,0,1,-1 };
		int dj[4] = { 1,-1,0,0 };
		int ans = 1;
		//遍历当前土地的四个方向
		for (int index = 0; index != 4; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			ans += dfs(grid, next_i, next_j);
		}
		return ans;
	}

public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j)
				ans = std::max(ans, dfs(grid, i, j));
		}
		return ans;
	}
};
```
- 例题 </br>
[200.岛屿数量](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%90%9C%E7%B4%A2%E9%97%AE%E9%A2%98/200.%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F.cpp) </br>
[695. 岛屿的最大面积](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E6%90%9C%E7%B4%A2%E9%97%AE%E9%A2%98/695.%20%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF.cpp)</br>
[130. 被围绕的区域:  这一题是对边界上的进行DFS]()

---
# 三、并查集
- 思路：Union-find算法

- 模板：
```
class Solution {
public:
	//vector<int>fa;		//父亲节点'
	int fa[200];
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);		//路径压缩
	}


	int findCircleNum(vector<vector<int>>& M) {

		int N = M.size();
		//初始化父节点
		for (int i = 0; i < N; i++)
			fa[i] = i;

		int res = N;		//初始化有N个圈子：谁跟谁都不是朋友
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (M[i][j] == 0) continue;

				//节点合并 union
				int fx = find(i), fy = find(j);
				if (fx != fy) {
					fa[fx] = fy;
					res--;
				}
			}
		}
		return res;
	}
};
```

- 例题：</br>
[547.朋友圈](https://github.com/ccpang96/leetcode/blob/master/leetcode/%E5%B9%B6%E6%9F%A5%E9%9B%86/547.%E6%9C%8B%E5%8F%8B%E5%9C%88.cpp)

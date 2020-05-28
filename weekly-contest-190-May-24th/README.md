# Leetcode-Weekly-Contest
Weekly Contest Problems on Leetcode 

### check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

- [题目](https://leetcode-cn.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)
- 思路
    - 遍历数组, 检查当前字符串的前缀是目标字符串即可
- 复杂度
    - 时间复杂度 O(NM): N 表示单词个数, M 表示搜索字符串长度, 对于每个单词需要匹配一遍搜索字符串, 所以复杂度是 O(NM)
    - 空间复杂度 O(1) 或 O(N): 如果利用 split 转成字符串列表就是 O(N), 如果直接对字符串本身进行处理就是 O(1). O(1)空间的做法, 就是碰到空格后重置下标即可
